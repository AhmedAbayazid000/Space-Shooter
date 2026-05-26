#pragma once
#include <SFML/Graphics.hpp>

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
};