#include "PlayerBullet.hpp"

// constructor, loads the player bullet sprite
PlayerBullet::PlayerBullet(float x, float y) : Bullet(x, y) {
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\player_bullet.png");
}

PlayerBullet::~PlayerBullet() {
}

void PlayerBullet::update(float deltaTime) {
    // move up
    y -= speed * deltaTime;

    // remove if it goes off the top of the screen
    if (y < 0) {
        isAlive = false;
    }
}