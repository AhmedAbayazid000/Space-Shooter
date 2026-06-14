#include "Bullet.hpp"
#include "Config.hpp"

// constructor, sets position and speed
Bullet::Bullet(float x, float y) : GameObject(x, y), speed(BULLET_SPEED) {
}

Bullet::~Bullet() {
}

// empty, gets overridden by player/enemy bullets to move up/down
void Bullet::update(float deltaTime) {
}

// draws the bullet sprite
void Bullet::draw(sf::RenderWindow& window) {
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}