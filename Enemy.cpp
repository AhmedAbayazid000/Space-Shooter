#include "Enemy.hpp"
#include "EnemyBullet.hpp"

// Constructor
Enemy::Enemy(float x, float y) : GameObject(x, y), speed(100.0f), shootTimer(0.0f), shootCooldown(2.0f) {
}

// Destructor
Enemy::~Enemy() {
}

void Enemy::update(float deltaTime) {
    // Enemy moves downwards
    y += speed * deltaTime;
    
    // Updates shooter timer
    if (shootTimer > 0) {
        shootTimer -= deltaTime;
    }
    
    // If the enemy reaches the bottom game over screen appears
    if (y > 720) {
        isAlive = false;
    }
}

//Draws the enemy
void Enemy::draw(sf::RenderWindow& window) {
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}

std::unique_ptr<Bullet> Enemy::shoot() {
    return std::make_unique<EnemyBullet>(x, y);
}