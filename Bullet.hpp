#pragma once
#include "GameObject.hpp"

// Base class for bullets, both player and enemy bullets inherit from this
class Bullet : public GameObject {
protected:
    float speed; // how fast the bullet moves

public:
    Bullet(float x, float y);
    virtual ~Bullet();
    void update(float deltaTime) override; // overridden in PlayerBullet/EnemyBullet
    void draw(sf::RenderWindow& window) override;
};