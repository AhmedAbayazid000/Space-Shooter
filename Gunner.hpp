#pragma once
#include "Enemy.hpp"

class Gunner : public Enemy {
public:
    Gunner(float x, float y);
    virtual ~Gunner();
};