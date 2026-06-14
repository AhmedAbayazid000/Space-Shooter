#include "WeaponPickup.hpp"

// constructor, picks the right sprite based on pickup type
WeaponPickup::WeaponPickup(float x, float y, Pickup type) : GameObject(x, y), type(type), speed(80.0f) {
    if (type == ShotgunPickup) {
        texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\shotgun_pickup.png");
    } else {
        texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\rapid_pickup.png");
    }
}

WeaponPickup::~WeaponPickup() {
}

// falls down slowly, removed if it goes off screen
void WeaponPickup::update(float deltaTime) {
    y += speed * deltaTime;
    if (y > 720) {
        isAlive = false;
    }
}

// draws the pickup sprite
void WeaponPickup::draw(sf::RenderWindow& window) {
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}

// returns which weapon this pickup gives
Pickup WeaponPickup::getType() {
    return type;
}