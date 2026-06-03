#include "Gunner.hpp"

//Shoots more frequently, cooldown reduced by 20%
Gunner::Gunner(float x, float y) : Enemy(x, y) {
    shootCooldown = 1.6f;
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\gunner.png");
}

// Destructor
Gunner::~Gunner() {
}