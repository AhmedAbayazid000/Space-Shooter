#include "Player.hpp"
#include "Config.hpp"

// constructor, sets starting stats and loads the ship sprite
Player::Player(float x, float y) : GameObject(x, y), lives(3), speed(PLAYER_SPEED), shootTimer(0.0f), shootCooldown(PLAYER_SHOOT_COOLDOWN), currentWeapon(Normal) {
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\player.png");
}

Player::~Player() {
}

// nothing to update every frame, movement is handled in handleInput
void Player::update(float deltaTime) {
}

// draws the player ship at its current position
void Player::draw(sf::RenderWindow& window) {
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}

// checks the keyboard and moves the player left/right
void Player::handleInput(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        x += speed * deltaTime;
    }
}

// returns the bullets to spawn based on the current weapon
std::vector<std::unique_ptr<Bullet>> Player::shoot() {
    std::vector<std::unique_ptr<Bullet>> bullets;
    
    switch (currentWeapon) {
        // one bullet straight up
        case Normal:
            bullets.push_back(std::make_unique<PlayerBullet>(x, y));
            break;
        // three bullets in a spread
        case Shotgun:
            bullets.push_back(std::make_unique<PlayerBullet>(x, y));
            bullets.push_back(std::make_unique<PlayerBullet>(x - 20, y));
            bullets.push_back(std::make_unique<PlayerBullet>(x + 20, y));
            break;
        // one bullet, but Game uses a shorter cooldown for this
        case Rapid:
            bullets.push_back(std::make_unique<PlayerBullet>(x, y));
            break;
    }
    return bullets;
}

float Player::getShootTimer() { 
    return shootTimer; 
}
void Player::setShootTimer(float timer) { 
    shootTimer = timer; 
}
float Player::getShootCooldown() { 
    return shootCooldown; 
}
int Player::getLives() {
    return lives;
}
void Player::setLives(int newLives) {
    lives = newLives;
}
Weapon Player::getCurrentWeapon() {
    return currentWeapon;
}
void Player::setCurrentWeapon(Weapon weapon) {
    currentWeapon = weapon;
}