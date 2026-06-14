#pragma once
#include "Enemy.hpp"

// faster enemy, moves quicker than a normal Grunt
class Rusher : public Enemy {
public:
    Rusher(float x, float y);
    virtual ~Rusher();
};