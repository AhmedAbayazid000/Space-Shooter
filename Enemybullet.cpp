#include "EnemyBullet.hpp"

EnemyBullet::EnemyBullet(float x, float y) : Bullet(x, y) {
}

EnemyBullet::~EnemyBullet() {
}

void EnemyBullet::update(float deltaTime) {
// Enemy bullet moves downward
    y += speed * deltaTime;
    
// Remove if off screen
    if (y > 720) {
        isAlive = false;
    }
}