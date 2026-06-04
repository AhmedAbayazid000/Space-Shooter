#include "WeaponPickup.hpp"

// Initializing pickup type and speed
WeaponPickup::WeaponPickup(float x, float y, Pickup type) : GameObject(x, y), type(type), speed(80.0f) {
    if (type == ShotgunPickup) {
        texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\shotgun_pickup.png");
    } else {
        texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\rapid_pickup.png");
    }
}

// Destructor
WeaponPickup::~WeaponPickup() {
}

// Moves pickup downward and removes it if it goes off screen
void WeaponPickup::update(float deltaTime) {
    y += speed * deltaTime;
    if (y > 720) {
        isAlive = false;
    }
}

// Draws the pickup to the window
void WeaponPickup::draw(sf::RenderWindow& window) {
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}

// Returns the type of weapon this pickup gives
Pickup WeaponPickup::getType() {
    return type;
}