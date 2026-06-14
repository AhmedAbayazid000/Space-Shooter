#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Grunt.hpp"
#include "Rusher.hpp"
#include "Gunner.hpp"
#include "Bullet.hpp"
#include "PlayerBullet.hpp"
#include "EnemyBullet.hpp"
#include "Explosion.hpp"
#include "WeaponPickup.hpp"
#include "Spawner.hpp"
#include "Config.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <algorithm>

// Constructor Initializer list
Game::Game() : highscore(0), window(sf::VideoMode(sf::Vector2u(1280, 720)), "Space Shooter"), state(Menu) {
    if (!backgroundT.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\background.png")) {
        std::cout << "Failed to load background!" << std::endl;
    }
}

// Returns the current high score
int Game::get_highscore() {
    return highscore;
}

// Updates high score only if the new score is higher
void Game::set_highscore(int score) {
    if (score > highscore) {
        highscore = score;
    }
}

// Main loop Run function for the game
void Game::run(){
    while (window.isOpen()){
        if (state == Menu) mainmenu();
        else if (state == Playing) gamescreen();
        else if (state == Gameover) gameover();
    }
}

// Main menu screen
void Game::mainmenu(){
    sf::Sprite backgroundS(backgroundT);
    sf::Font font("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\font.ttf");
    sf::Text title(font, "Space Shooter", 100);
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setPosition(sf::Vector2f((1280 - titleBounds.size.x) / 2, 180));
    sf::Text begin(font, "Press Enter to begin", 40);
    sf::FloatRect beginBounds = begin.getLocalBounds();
    begin.setPosition(sf::Vector2f((1280 - beginBounds.size.x) / 2, 350));
    sf::Text end(font, "Press Q to quit", 40);
    sf::FloatRect endBounds = end.getLocalBounds();
    end.setPosition(sf::Vector2f((1280 - endBounds.size.x) / 2, 420));

    // Display the current high score below the menu options
    sf::Text highScoreText(font, "High Score: " + std::to_string(get_highscore()), 30);
    sf::FloatRect hsBounds = highScoreText.getLocalBounds();
    highScoreText.setPosition(sf::Vector2f((1280 - hsBounds.size.x) / 2, 500));

    while (window.isOpen() && state == Menu) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                if (keyEvent->code == sf::Keyboard::Key::Enter)
                    state = Playing;
                if (keyEvent->code == sf::Keyboard::Key::Q)
                    window.close();
            }
        }
        window.clear();
        window.draw(backgroundS);
        window.draw(title);
        window.draw(begin);
        window.draw(end);
        window.draw(highScoreText);
        window.display();
    }
}

// Main gameplay screen
void Game::gamescreen() {
    // Setup
    sf::Sprite backgroundS(backgroundT);
    Player player(640, 650);
    Spawner spawner(ENEMY_SPAWN_COOLDOWN);
    std::vector<std::unique_ptr<GameObject>> gameObjects;
    sf::Clock deltaClock;
    int score = 0;

    // Heart icons for displaying player lives (max 3)
    sf::Texture heartTexture;
    heartTexture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\heart.png");
    sf::Sprite heart1(heartTexture);
    sf::Sprite heart2(heartTexture);
    sf::Sprite heart3(heartTexture);
    heart1.setScale(sf::Vector2f(0.5f, 0.5f));
    heart2.setScale(sf::Vector2f(0.5f, 0.5f));
    heart3.setScale(sf::Vector2f(0.5f, 0.5f));
    heart1.setPosition(sf::Vector2f(1100, 10));
    heart2.setPosition(sf::Vector2f(1145, 10));
    heart3.setPosition(sf::Vector2f(1190, 10));

    // HUD text created once, updated each frame
    sf::Font font("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\font.ttf");
    sf::Text scoreText(font, "Score: 0", 30);
    scoreText.setPosition(sf::Vector2f(10, 10));

    while (window.isOpen() && state == Playing) {
        // Calculate time since last frame
        float deltaTime = deltaClock.restart().asSeconds();

        // Event handling
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Handle player input (movement)
        player.handleInput(deltaTime);

        // Spawn enemies on a timer
        if (spawner.shouldSpawn()) {
            gameObjects.push_back(spawner.spawnEnemy());
            spawner.reset();
        }

        // Player shooting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player.getShootTimer() <= 0) {
            auto bullets = player.shoot();
            for (auto& bullet : bullets) {
                gameObjects.push_back(std::move(bullet));
            }
            player.setShootTimer(player.getShootCooldown());
        }
        if (player.getShootTimer() > 0) {
            player.setShootTimer(player.getShootTimer() - deltaTime);
        }

        // Enemy shooting - collect new bullets separately to avoid modifying vector while iterating
        std::vector<std::unique_ptr<GameObject>> newObjects;
        for (auto& obj : gameObjects) {
            if (auto* enemy = dynamic_cast<Enemy*>(obj.get())) {
                if (enemy->getShootTimer() <= 0) {
                    newObjects.push_back(enemy->shoot());
                    enemy->setShootTimer(enemy->getShootCooldown());
                }
            }
        }

        // Update all game objects
        for (auto& obj : gameObjects) {
            obj->update(deltaTime);
        }

        // Collision detection
        for (auto& obj : gameObjects) {
            // Player bullet hits enemy
            if (auto* pb = dynamic_cast<PlayerBullet*>(obj.get())) {
                for (auto& obj2 : gameObjects) {
                    if (auto* enemy = dynamic_cast<Enemy*>(obj2.get())) {
                        if (pb->getIsAlive() && enemy->getIsAlive() &&
                            pb->getX() < enemy->getX() + enemy->getWidth() && pb->getX() + pb->getWidth() > enemy->getX() &&
                            pb->getY() < enemy->getY() + enemy->getHeight() && pb->getY() + pb->getHeight() > enemy->getY()) {
                            pb->setIsAlive(false);
                            enemy->setIsAlive(false);
                            score += 10;
                            newObjects.push_back(std::make_unique<Explosion>(enemy->getX(), enemy->getY()));
                            auto pickup = spawner.spawnPickup(enemy->getX(), enemy->getY());
                            if (pickup) newObjects.push_back(std::move(pickup));
                        }
                    }
                }
            }
            // Enemy bullet hits player
            if (auto* eb = dynamic_cast<EnemyBullet*>(obj.get())) {
                if (eb->getIsAlive() &&
                    eb->getX() < player.getX() + player.getWidth() && eb->getX() + eb->getWidth() > player.getX() &&
                    eb->getY() < player.getY() + player.getHeight() && eb->getY() + eb->getHeight() > player.getY()) {
                    eb->setIsAlive(false);
                    player.setLives(player.getLives() - 1);
                    if (player.getLives() <= 0) {
                        // Player ran out of lives, go to game over screen
                        state = Gameover;
                        currentscore = score;
                        // Update high score if this run beat the previous best
                        set_highscore(score);
                    }
                }
            }
            // Player collects weapon pickup
            if (auto* pickup = dynamic_cast<WeaponPickup*>(obj.get())) {
                if (pickup->getIsAlive() &&
                    pickup->getX() < player.getX() + player.getWidth() && pickup->getX() + pickup->getWidth() > player.getX() &&
                    pickup->getY() < player.getY() + player.getHeight() && pickup->getY() + pickup->getHeight() > player.getY()) {
                    if (pickup->getType() == ShotgunPickup) {
                        player.setCurrentWeapon(Shotgun);
                    } 
                    else {
                        player.setCurrentWeapon(Rapid);
                    }
                    pickup->setIsAlive(false);
                }
            }
        }

        // Add newly created objects (bullets, explosions, pickups) to main vector
        for (auto& obj : newObjects) {
            gameObjects.push_back(std::move(obj));
        }

        // Remove dead objects from vector
        gameObjects.erase(
            std::remove_if(gameObjects.begin(), gameObjects.end(),
                [](const std::unique_ptr<GameObject>& obj) { return !obj->getIsAlive(); }),
            gameObjects.end()
        );

        // Draw everything
        window.clear();
        window.draw(backgroundS);
        player.draw(window);
        for (auto& obj : gameObjects) {
            obj->draw(window);
        }

        // Update and draw HUD - score
        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);

        // Draw one heart per remaining life
        if (player.getLives() >= 1) window.draw(heart1);
        if (player.getLives() >= 2) window.draw(heart2);
        if (player.getLives() >= 3) window.draw(heart3);

        window.display();
    }
}

// Game over screen
void Game::gameover(){
    sf::Sprite backgroundS(backgroundT);
    sf::Font font("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\font.ttf");
    sf::Text gameOver(font, "GAME OVER", 60);
    gameOver.setPosition(sf::Vector2f(490, 250));
    sf::Text score_(font, "Score: " + std::to_string(currentscore), 30);
    score_.setPosition(sf::Vector2f(550, 380));

    sf::Clock timer;
    while (window.isOpen() && timer.getElapsedTime().asSeconds() < 5) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        window.draw(backgroundS);
        window.draw(gameOver);
        window.draw(score_);
        window.display();
    }
    state = Menu;
}