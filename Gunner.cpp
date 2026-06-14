#include "Gunner.hpp"
#include "Config.hpp"

// faster shooter, overrides the default shoot cooldown
Gunner::Gunner(float x, float y) : Enemy(x, y) {
    shootCooldown = GUNNER_SHOOT_COOLDOWN;
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\gunner.png");
}

Gunner::~Gunner() {
}