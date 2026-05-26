#pragma once
#include "GameObject.hpp"
//Bullet class base for enemybullet and playerbullet
class Bullet : public Gameobject {
protected:
    float speed;

public:
    Bullet(float x, float y);
    virtual ~Bullet();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};