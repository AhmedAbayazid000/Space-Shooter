#include "GameObject.hpp"

// Constructor - initializes position and sets object as alive
GameObject::GameObject(float x, float y) : x(x), y(y), isAlive(true) {
}
// Destructor
GameObject::~GameObject() {
}