#include "Spawner.hpp"
#include "Grunt.hpp"
#include "Rusher.hpp"
#include "Gunner.hpp"
#include "WeaponPickup.hpp"
#include "Config.hpp"
#include <cstdlib>

// constructor, sets how often enemies should spawn
Spawner::Spawner(float spawnCooldown) : spawnCooldown(spawnCooldown) {
}

Spawner::~Spawner() {
}

// checks if enough time has passed to spawn another enemy
bool Spawner::shouldSpawn() {
    return spawnTimer.getElapsedTime().asSeconds() >= spawnCooldown;
}

// restarts the spawn timer
void Spawner::reset() {
    spawnTimer.restart();
}

// picks a random enemy type and spawns it at a random x position
std::unique_ptr<Enemy> Spawner::spawnEnemy() {
    int Etype = rand() % 3;
    std::unique_ptr<Enemy> enemy;

    if (Etype == 0) enemy = std::make_unique<Grunt>(0, 0);
    else if (Etype == 1) enemy = std::make_unique<Rusher>(0, 0);
    else enemy = std::make_unique<Gunner>(0, 0);

    // keep the enemy fully on screen horizontally
    float maxX = 1280 - enemy->getWidth();
    float randomP = rand() % (int)maxX;
    enemy->setX(randomP);

    return enemy;
}

// random chance to drop a weapon pickup when an enemy dies
std::unique_ptr<WeaponPickup> Spawner::spawnPickup(float x, float y) {
    int chance = rand() % 100;
    if (chance < WEAPON_DROP_CHANCE) {
        int Wtype = rand() % 2;
        if (Wtype == 0) return std::make_unique<WeaponPickup>(x, y, ShotgunPickup);
        else return std::make_unique<WeaponPickup>(x, y, RapidPickup);
    }
    return nullptr;
}