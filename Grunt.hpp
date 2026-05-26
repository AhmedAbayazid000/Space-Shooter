#pragma once
#include "Enemy.hpp"

class Grunt : public Enemy {
public:
    Grunt(float x, float y);
    virtual ~Grunt();
};