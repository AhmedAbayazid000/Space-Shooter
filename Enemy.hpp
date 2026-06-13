#pragma once
#include "GameObject.hpp"
#include "Bullet.hpp"
#include <memory>

//Enemy attributes and inherits from GameObject
class Enemy : public GameObject {
protected:
    float speed;
    float shootTimer;
    float shootCooldown;
//Constructor, Destructor,Functions(shoot,update,draw)
public:
    Enemy(float x, float y);
    virtual ~Enemy();
    float getShootTimer();
    void setShootTimer(float timer);
    float getShootCooldown();
    std::unique_ptr<Bullet> shoot();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};