#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "WeaponPickup.hpp"
#include <memory>

// handles spawning enemies and weapon pickups
class Spawner {
private:
    float spawnCooldown; // how often enemies spawn
    sf::Clock spawnTimer;

public:
    Spawner(float spawnCooldown);
    ~Spawner();

    bool shouldSpawn(); // true once spawnCooldown has passed
    void reset();       // resets the timer after spawning

    std::unique_ptr<Enemy> spawnEnemy(); // random enemy type, random x position
    std::unique_ptr<WeaponPickup> spawnPickup(float x, float y); // chance to drop a weapon
};