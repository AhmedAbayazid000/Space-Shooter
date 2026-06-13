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

// Main loop Run function for the game
void Game::run(){
    while (window.isOpen()){
        std::cout << "run loop, state=" << state << " window open=" << window.isOpen() << std::endl;
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

    while (window.isOpen() && state == Menu) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                if (keyEvent->code == sf::Keyboard::Key::Enter){
                    state = Playing;
                        std::cout << "Enter pressed, switching to Playing" << std::endl;

                }
                if (keyEvent->code == sf::Keyboard::Key::Q)
                    window.close();
            }
        }
        window.clear();
        window.draw(backgroundS);
        window.draw(title);
        window.draw(begin);
        window.draw(end);
        window.display();
    }
}

// Main gameplay screen
void Game::gamescreen() {
    std::cout << "Entered gamescreen" << std::endl;
    sf::Sprite backgroundS(backgroundT);
    std::cout << "Background created" << std::endl;
    Player player(640, 650);
    std::cout << "Player created" << std::endl;
    Spawner spawner(2.0f);
    std::cout << "Spawner created" << std::endl;
    std::vector<std::unique_ptr<GameObject>> gameObjects;
    sf::Clock deltaClock;
    int score = 0;
    std::cout << "About to enter loop" << std::endl;

    while (window.isOpen() && state == Playing) {
        std::cout << "Loop iteration" << std::endl;
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

        // Enemy shooting
        for (auto& obj : gameObjects) {
            if (auto* enemy = dynamic_cast<Enemy*>(obj.get())) {
                if (enemy->getShootTimer() <= 0) {
                    gameObjects.push_back(enemy->shoot());
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
                            pb->getX() < enemy->getX() + 50 && pb->getX() + 10 > enemy->getX() &&
                            pb->getY() < enemy->getY() + 50 && pb->getY() + 20 > enemy->getY()) {
                            pb->setIsAlive(false);
                            enemy->setIsAlive(false);
                            score += 10;
                            gameObjects.push_back(std::make_unique<Explosion>(enemy->getX(), enemy->getY()));
                            auto pickup = spawner.spawnPickup(enemy->getX(), enemy->getY());
                            if (pickup) gameObjects.push_back(std::move(pickup));
                        }
                    }
                }
            }
            // Enemy bullet hits player
            if (auto* eb = dynamic_cast<EnemyBullet*>(obj.get())) {
                if (eb->getIsAlive() &&
                    eb->getX() < player.getX() + 50 && eb->getX() + 10 > player.getX() &&
                    eb->getY() < player.getY() + 50 && eb->getY() + 20 > player.getY()) {
                    eb->setIsAlive(false);
                    player.setLives(player.getLives() - 1);
                    if (player.getLives() <= 0) {
                        state = Gameover;
                        currentscore = score;
                    }
                }
            }
            // Player collects weapon pickup
            if (auto* pickup = dynamic_cast<WeaponPickup*>(obj.get())) {
                if (pickup->getIsAlive() &&
                    pickup->getX() < player.getX() + 50 && pickup->getX() + 30 > player.getX() &&
                    pickup->getY() < player.getY() + 50 && pickup->getY() + 30 > player.getY()) {
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

        // Draw HUD - score and lives
        sf::Font font("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\font.ttf");
        sf::Text scoreText(font, "Score: " + std::to_string(score), 30);
        scoreText.setPosition(sf::Vector2f(10, 10));
        sf::Text livesText(font, "Lives: " + std::to_string(player.getLives()), 30);
        livesText.setPosition(sf::Vector2f(1100, 10));
        window.draw(scoreText);
        window.draw(livesText);
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