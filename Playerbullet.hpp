#pragma once
#include "Bullet.hpp"
//Bullets fired by player moves upwards
class PlayerBullet : public Bullet {
public:
    PlayerBullet(float x, float y);
    virtual ~PlayerBullet();
    void update(float deltaTime) override;
};