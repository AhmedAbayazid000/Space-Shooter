#pragma once
#include "GameObject.hpp"
//Diffrent types of weapons enemies drop. The player can collect it by touching it 
enum Pickup { ShotgunPickup, RapidPickup };

class WeaponPickup : public GameObject {
private:
    Pickup type;
    float speed;

public:
    WeaponPickup(float x, float y, Pickup type);
    virtual ~WeaponPickup();
    Pickup getType();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};