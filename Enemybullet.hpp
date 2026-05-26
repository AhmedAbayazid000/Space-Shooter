#pragma once
#include "Bullet.hpp"
//Enemy bullet moves downwards
class EnemyBullet : public Bullet {
public:
    EnemyBullet(float x, float y);
    virtual ~EnemyBullet();
    void update(float deltaTime) override;
};