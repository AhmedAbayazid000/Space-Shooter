#include "EnemyBullet.hpp"

// constructor, loads the enemy bullet sprite
EnemyBullet::EnemyBullet(float x, float y) : Bullet(x, y) {
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\enemy_bullet.png");
}

EnemyBullet::~EnemyBullet() {
}

void EnemyBullet::update(float deltaTime) {
    // move down
    y += speed * deltaTime;

    // remove if it goes off screen
    if (y > 720) {
        isAlive = false;
    }
}