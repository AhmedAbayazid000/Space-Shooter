#include "Grunt.hpp"

// basic enemy, doesn't change speed/cooldown, just loads its own sprite
Grunt::Grunt(float x, float y) : Enemy(x, y) {
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\grunt.png");
}

Grunt::~Grunt() {
}