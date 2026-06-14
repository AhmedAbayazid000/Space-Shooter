#pragma once
#include "Bullet.hpp"

// Bullet fired by enemies, moves downward toward the player
class EnemyBullet : public Bullet {
public:
    EnemyBullet(float x, float y);
    virtual ~EnemyBullet();
    void update(float deltaTime) override;
};