#include "Game.hpp"
#include <SFML/Graphics.hpp>
//Constructor Initializer list
Game::Game() : highscore(0), window(sf::VideoMode(sf::Vector2u(800, 600)), "Space Shooter"), state(Menu), backgroundS(backgroundT) {
    backgroundT.loadFromFile("Extra/MM background.png");
}