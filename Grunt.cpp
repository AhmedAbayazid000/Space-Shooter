#include "Grunt.hpp"
#include <iostream>

// Basic enemy with normal speed and fire rate
Grunt::Grunt(float x, float y) : Enemy(x, y) {
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\grunt.png");
    }

// Destructor
Grunt::~Grunt() {
}