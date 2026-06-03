#include "Rusher.hpp"

// Faster enemy, speed increased by 10%
Rusher::Rusher(float x, float y) : Enemy(x, y) {
    speed = 110.0f;
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\rusher.png");
}

// Destructor
Rusher::~Rusher() {
}