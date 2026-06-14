#include "GameObject.hpp"

// constructor, sets starting position and marks the object as alive
GameObject::GameObject(float x, float y) : x(x), y(y), isAlive(true) {
}

GameObject::~GameObject() {
}

float GameObject::getX() { 
    return x;
}
float GameObject::getY() { 
    return y; 
}
void GameObject::setX(float x_) { 
    x = x_; 
}
void GameObject::setY(float y_) { 
    y = y_; 
}
bool GameObject::getIsAlive() {
    return isAlive;
}
void GameObject::setIsAlive(bool alive) {
    isAlive = alive; 
}

// width/height of the sprite, used for collision boxes
float GameObject::getWidth() {
    return texture.getSize().x;
}
float GameObject::getHeight() {
    return texture.getSize().y;
}