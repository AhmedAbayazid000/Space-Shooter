#pragma once
#include "GameObject.hpp"

// Explosion animation played when an enemy is destroyed
class Explosion : public GameObject {
private:
    int currentFrame;    // current frame of the animation
    int totalFrames;     // total number of frames in the spritesheet
    int frameWidth;      // width of each frame in pixels
    int frameHeight;
    float animationTimer;  // tracks time between frame changes
    float animationSpeed;  // time between each frame

public:
    Explosion(float x, float y);
    virtual ~Explosion();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};