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
    //To make sure that the movement is framerate independent
    virtual void update(float deltaTime)=0;
    virtual void draw(sf::RenderWindow& window)=0;
};
