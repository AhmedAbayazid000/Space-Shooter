#pragma once 
#include <SFML/Graphics.hpp>

class Gameobject{
    protected:
    // Sprite and texture for evry class that inherits for GameObject
       sf::Sprite sprite;
       sf::Texture texture;
       float x,y; 
       bool isAlive;

    public:
    Gameobject(float x, float y);
    virtual ~Gameobject();
    //To make sure that the movement is framerate independent
    virtual void update(float deltatime)=0;
    virtual void draw(sf::RenderWindow& window)=0;
};
