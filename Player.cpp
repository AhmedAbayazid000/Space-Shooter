#include "Player.hpp"

// Constructor 
Player::Player(float x, float y) : GameObject(x, y), lives(3), speed(200.0f), shootTimer(0.0f), shootCooldown(0.5f), currentWeapon(Normal) {
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\player.png");
}

// Destructor
Player::~Player() {
}

//Updates players position
void Player::update(float deltaTime) {
}

//Draws the player
void Player::draw(sf::RenderWindow& window) {
}

void Player::handleInput(float deltaTime) {
    // Moving left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        x -= speed * deltaTime;
    }
    // Moving right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        x += speed * deltaTime;
    }
    // Shooting 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if (shootTimer <= 0) {
            shootTimer = shootCooldown;
        }
    }
    // Update shooting timer
    if (shootTimer > 0) {
        shootTimer -= deltaTime;
    }
}

std::vector<std::unique_ptr<Bullet>> Player::shoot() {
    std::vector<std::unique_ptr<Bullet>> bullets;
    
    switch (currentWeapon) {
        // Single bullet 
        case Normal:
            bullets.push_back(std::make_unique<PlayerBullet>(x, y));
            break;
        // Three bullets in diffrent angles
        case Shotgun:
            bullets.push_back(std::make_unique<PlayerBullet>(x, y));
            bullets.push_back(std::make_unique<PlayerBullet>(x - 20, y));
            bullets.push_back(std::make_unique<PlayerBullet>(x + 20, y));
            break;
        // Single bullet but shooting colldown is reduced
        case Rapid:
            bullets.push_back(std::make_unique<PlayerBullet>(x, y));
            break;
    }
    return bullets;
}
