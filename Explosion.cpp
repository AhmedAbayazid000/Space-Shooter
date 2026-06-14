#include "Explosion.hpp"

// constructor, sets up animation values and loads the spritesheet
// spritesheet is a 4x2 grid of 200x200 frames (8 frames total)
Explosion::Explosion(float x, float y) : GameObject(x, y), currentFrame(0), totalFrames(8), frameWidth(200), frameHeight(200), animationTimer(0.0f), animationSpeed(0.05f) {
    texture.loadFromFile("C:\\Users\\ahmed_nxns003\\Desktop\\Game Project\\Project implementation step\\Extra\\explosion.png");
}

Explosion::~Explosion() {
}

// moves to the next frame every animationSpeed seconds
void Explosion::update(float deltaTime) {
    animationTimer += deltaTime;
    if (animationTimer >= animationSpeed) {
        currentFrame++;
        animationTimer = 0.0f;
        // done playing all frames, remove the explosion
        if (currentFrame >= totalFrames) {
            isAlive = false;
        }
    }
}

// draws the current frame cropped from the spritesheet
void Explosion::draw(sf::RenderWindow& window) {
    int col = currentFrame % 4;
    int row = currentFrame / 4; // 4 frames per row
    sf::Sprite sprite(texture, sf::IntRect(sf::Vector2i(col * frameWidth, row * frameHeight), sf::Vector2i(frameWidth, frameHeight)));
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}