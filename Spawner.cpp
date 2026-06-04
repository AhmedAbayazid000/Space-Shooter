#include "Spawner.hpp"
#include "Grunt.hpp"
#include "Rusher.hpp"
#include "Gunner.hpp"
#include "WeaponPickup.hpp"
#include <cstdlib>

// Constructor - sets spawn cooldown
Spawner::Spawner(float spawnCooldown) : spawnCooldown(spawnCooldown) {
}

// Destructor
Spawner::~Spawner() {
}

// Returns true if enough time has passed to spawn a new enemy
bool Spawner::shouldSpawn() {
    return spawnTimer.getElapsedTime().asSeconds() >= spawnCooldown;
}

// Resets the spawn timer after spawning
void Spawner::reset() {
    spawnTimer.restart();
}

// Spawns a random enemy type at a random X position
std::unique_ptr<Enemy> Spawner::spawnEnemy() {
    float randomP = rand() % 1280;
    int Etype = rand() % 3;
    
    if (Etype == 0) return std::make_unique<Grunt>(randomP, 0);
    else if (Etype == 1) return std::make_unique<Rusher>(randomP, 0);
    else return std::make_unique<Gunner>(randomP, 0);
}

// Random chance to drop a weapon pickup at given position
std::unique_ptr<WeaponPickup> Spawner::spawnPickup(float x, float y) {
    int chance = rand() % 100;
    if (chance < 20) { // 20% drop chance
        int Wtype = rand() % 2;
        if (Wtype == 0) return std::make_unique<WeaponPickup>(x, y, ShotgunPickup);
        else return std::make_unique<WeaponPickup>(x, y, RapidPickup);
    }
    return nullptr;
}