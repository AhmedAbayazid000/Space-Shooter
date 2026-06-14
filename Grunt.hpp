#pragma once
#include "Enemy.hpp"

// the normal/basic enemy, just uses the default speed and shoot cooldown from Enemy
class Grunt : public Enemy {
public:
    Grunt(float x, float y);
    virtual ~Grunt();
};