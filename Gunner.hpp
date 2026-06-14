#pragma once
#include "Enemy.hpp"

// shoots more often than a normal Grunt (shorter cooldown)
class Gunner : public Enemy {
public:
    Gunner(float x, float y);
    virtual ~Gunner();
};