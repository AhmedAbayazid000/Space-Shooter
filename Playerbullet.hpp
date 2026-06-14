#pragma once
#include "Bullet.hpp"

// bullet fired by the player, moves upward
class PlayerBullet : public Bullet {
public:
    PlayerBullet(float x, float y);
    virtual ~PlayerBullet();
    void update(float deltaTime) override;
};