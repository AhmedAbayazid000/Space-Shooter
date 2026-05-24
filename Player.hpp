#pragma once
#include "GameObject.hpp"
//Enumerator for the diffrent types fo weapons
enum Weapon { Normal, Shotgun, Rapid };

class Player : public Gameobject {
    private:
        int lives;
        float speed;
        float shootCooldown;
        float shootTimer;
        Weapon currentWeapon;
    public:
        Player(float x, float y);
        virtual ~Player();
        void handleInput(float deltaTime);
        void shoot();
        void update(float deltaTime) override;
        void draw(sf::RenderWindow& window) override;
        int getLives();
        void setLives(int lives);
        Weapon getCurrentWeapon();
        void setCurrentWeapon(Weapon weapon);
};