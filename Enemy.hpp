#pragma once
#include "GameObject.hpp"
//Enemy attributes and inherits from GameObject
class Enemy : public Gameobject {
protected:
    float speed;
    float shootTimer;
    float shootCooldown;
//Constructor, Destructor,Functions(shoot,update,draw)
public:
    Enemy(float x, float y);
    virtual ~Enemy();
    void shoot();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};