#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
// Constructor Initializer list
Game::Game() : highscore(0), window(sf::VideoMode(sf::Vector2u(1280, 720)), "Space Shooter"), state(Menu) {
    if (!backgroundT.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\background.png")) {
        std::cout << "Failed to load background!" << std::endl;
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
        window.display();
    }
}

// Main gameplay screen
void Game::gamescreen(){
    while (window.isOpen() && state == Playing) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
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