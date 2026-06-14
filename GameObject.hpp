#pragma once 
#include <SFML/Graphics.hpp>

// base class for everything that appears in the game (player, enemies, bullets, etc)
class GameObject{
    protected:
    // every object that inherits from this has a texture and a position
       sf::Texture texture;
       float x, y; 
       bool isAlive; // false = remove this object from the game

    public:
    GameObject(float x, float y);
    virtual ~GameObject();

    float getX();
    float getY();
    void setX(float x_);
    void setY(float y_);
    bool getIsAlive();
    void setIsAlive(bool alive);

    // used for collision detection, based on the texture size
    float getWidth();
    float getHeight();

    // pure virtual, every object has to implement these themselves
    virtual void update(float deltaTime) = 0; // deltaTime makes movement frame-rate independent
    virtual void draw(sf::RenderWindow& window) = 0;
};