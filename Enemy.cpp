#include "Enemy.hpp"
#include "EnemyBullet.hpp"
#include "Config.hpp"

// constructor, default values from config (Grunt uses these as is)
Enemy::Enemy(float x, float y) : GameObject(x, y), speed(ENEMY_BASE_SPEED), shootTimer(0.0f), shootCooldown(ENEMY_BASE_SHOOT_COOLDOWN) {
}

Enemy::~Enemy() {
}

void Enemy::update(float deltaTime) {
    // move down
    y += speed * deltaTime;

    // count down shoot timer
    if (shootTimer > 0) {
        shootTimer -= deltaTime;
    }

    // remove enemy if it goes off the bottom of the screen
    if (y > 720) {
        isAlive = false;
    }
}

// draws the enemy sprite
void Enemy::draw(sf::RenderWindow& window) {
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}

// spawns a bullet at the enemy's position
std::unique_ptr<Bullet> Enemy::shoot() {
    return std::make_unique<EnemyBullet>(x, y);
}

float Enemy::getShootTimer() { 
    return shootTimer; 
}
void Enemy::setShootTimer(float timer) { 
    shootTimer = timer; 
}
float Enemy::getShootCooldown() { 
    return shootCooldown; 
}