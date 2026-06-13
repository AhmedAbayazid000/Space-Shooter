#include "Explosion.hpp"

// Constructor - initializes animation variables
Explosion::Explosion(float x, float y) : GameObject(x, y), currentFrame(0), totalFrames(27), frameWidth(512), frameHeight(292), animationTimer(0.0f), animationSpeed(0.05f) {
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\explosion.png");
}

// Destructor
Explosion::~Explosion() {
}

// Advances animation frame based on deltaTime
void Explosion::update(float deltaTime) {
    animationTimer += deltaTime;
    //If timer exceeds the speed currentframe is killed and timer is reset
    if (animationTimer >= animationSpeed) {
        currentFrame++;
        animationTimer = 0.0f;
        //When all frames have been shown the animation is done and the obj is removed
        if (currentFrame >= totalFrames) {
            isAlive = false;
        }
    }
}

// Draws the current frame of the explosion
void Explosion::draw(sf::RenderWindow& window) {
    int col = currentFrame % 4;
    //Every four frame you move down a row
    int row = currentFrame / 4;
    //To crop the correct frame from the spritesheet
    sf::Sprite sprite(texture, sf::IntRect(sf::Vector2i(col * frameWidth, row * frameHeight), sf::Vector2i(frameWidth, frameHeight)));
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}