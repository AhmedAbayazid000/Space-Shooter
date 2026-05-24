#include "Game.hpp"
#include <SFML/Graphics.hpp>
//Constructor Initializer list
Game::Game() : highscore(0), window(sf::VideoMode(sf::Vector2u(800, 600)), "Space Shooter"), state(Menu) {
    backgroundT.loadFromFile("Extra/MM background.png");
}
//Main loop Run function for the game
void Game::run(){
    while (window.isOpen()){
        if (state==Menu)mainmenu();
        else if (state==Playing)gamescreen();
        else if (state== Gameover)gameover();
    }
}
//Mainmenu screen and functions (Font,title,Quit,Start)
void Game::mainmenu(){
    sf::Sprite backgroundS(backgroundT);
    sf::Font font ("Extra/font.ttf");
    sf::Text title(font,"Space Shooter", 50);
    title.setPosition(sf::Vector2f(300,200));
    sf::Text begin(font,"Press Enter to begin",30);
    begin.setPosition(sf::Vector2f(270,350));
    sf::Text end (font, "Press Q to quit", 30 );
    //The outter loop is to keep the screen running 
    while (window.isOpen() && state == Menu) {
        //The inner loop is to check for events 
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
        //TO show the screen background and text
        window.clear();
        window.draw(backgroundS);
        window.draw(title);
        window.draw(begin);
        window.draw(end);
        window.display();
    }

}
//Main gameplay screen functions
void Game::gamescreen(){

}
//Game over screen ("Game over" and current score) with the help of sfml::Clock
void Game::gameover(){
    sf::Sprite backgroundS(backgroundT);
    sf::Font font("Extra/font.ttf");
    sf::Text gameOver(font, "GAME OVER", 60);
    gameOver.setPosition(sf::Vector2f(250, 200));
    sf::Text score_(font, "Score: " + std::to_string(currentscore), 30);
    score_.setPosition(sf::Vector2f(300, 320));
    //sfml::Clock to count five seconds to show the game over screen
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

