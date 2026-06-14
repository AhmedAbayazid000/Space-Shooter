#pragma once
#include "GameObject.hpp"

// the two weapon pickups enemies can drop, player collects by touching it
enum Pickup { ShotgunPickup, RapidPickup };

class WeaponPickup : public GameObject {
private:
    Pickup type;
    float speed; // how fast it falls

public:
    WeaponPickup(float x, float y, Pickup type);
    virtual ~WeaponPickup();
    Pickup getType(); // tells Game which weapon to give the player
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};