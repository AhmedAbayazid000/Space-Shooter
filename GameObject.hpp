#pragma once 
#include <SFML/Graphics.hpp>

class GameObject{
    protected:
    // Texture for every class that inherits for GameObject
       sf::Texture texture;
       float x,y; 
       bool isAlive;

    public:
    GameObject(float x, float y);
    virtual ~GameObject();
    float getX();
    float getY();
    void setX(float x_);
    void setY(float y_);
    bool getIsAlive();
    void setIsAlive(bool alive);
    //To make sure that the movement is framerate independent
    virtual void update(float deltaTime)=0;
    virtual void draw(sf::RenderWindow& window)=0;
};
