#pragma once
#include "GameObject.hpp"
#include "Bullet.hpp"
#include <memory>

// Base enemy class, Grunt/Rusher/Gunner inherit from this
class Enemy : public GameObject {
protected:
    float speed;        // how fast it moves down
    float shootTimer;   // counts down until next shot
    float shootCooldown; // time between shots

public:
    Enemy(float x, float y);
    virtual ~Enemy();
    float getShootTimer();
    void setShootTimer(float timer);
    float getShootCooldown();
    std::unique_ptr<Bullet> shoot(); // creates an enemy bullet
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};