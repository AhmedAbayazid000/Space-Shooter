#pragma once
#include "GameObject.hpp"
#include <vector>
#include <memory>
#include "PlayerBullet.hpp"

// the different weapons the player can have
enum Weapon { Normal, Shotgun, Rapid };

// the player's ship, moves left/right and shoots
class Player : public GameObject {
    private:
        int lives;
        float speed;
        float shootCooldown;
        float shootTimer;
        Weapon currentWeapon;
    public:
        Player(float x, float y);
        virtual ~Player();

        // shoot timer getters/setters (used by Game to control fire rate)
        float getShootTimer();
        void setShootTimer(float timer);
        float getShootCooldown();

        void handleInput(float deltaTime); // moves the player based on key presses
        std::vector<std::unique_ptr<Bullet>> shoot(); // returns the bullet(s) to spawn based on current weapon

        void update(float deltaTime) override;
        void draw(sf::RenderWindow& window) override;

        int getLives();
        void setLives(int lives);
        Weapon getCurrentWeapon();
        void setCurrentWeapon(Weapon weapon);
};