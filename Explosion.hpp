#pragma once
#include "GameObject.hpp"

// Explosion animation, plays when an enemy is destroyed then removes itself
class Explosion : public GameObject {
private:
    int currentFrame;     // which frame we're on
    int totalFrames;      // total frames in the spritesheet (8)
    int frameWidth;       // width of one frame in pixels
    int frameHeight;      // height of one frame in pixels
    float animationTimer; // time since last frame change
    float animationSpeed; // how long each frame is shown

public:
    Explosion(float x, float y);
    virtual ~Explosion();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};