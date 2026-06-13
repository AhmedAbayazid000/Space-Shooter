#include "GameObject.hpp"

// Constructor - initializes position and sets object as alive
GameObject::GameObject(float x, float y) : x(x), y(y), isAlive(true) {
}
// Destructor
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