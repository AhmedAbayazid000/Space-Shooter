#include "Rusher.hpp"
#include "Config.hpp"

// faster enemy, overrides the default movement speed
Rusher::Rusher(float x, float y) : Enemy(x, y) {
    speed = RUSHER_SPEED;
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\rusher.png");
}

Rusher::~Rusher() {
}