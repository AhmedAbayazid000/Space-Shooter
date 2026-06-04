#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "WeaponPickup.hpp"
#include <memory>

class Spawner {
private:
    float spawnCooldown;
    sf::Clock spawnTimer;

public:
    Spawner(float spawnCooldown);
    ~Spawner();
    //Returns true when its time to spawn a new enemy
    bool shouldSpawn();
    //Resets the timer after spawning 
    void reset(); 
//Spawns a random enemy tyoe at a random position
    std::unique_ptr<Enemy> spawnEnemy();
//Random chance to drop a weapon pickup
    std::unique_ptr<WeaponPickup> spawnPickup(float x, float y);
};