#pragma once

// Game parameters - modify these values to change game behavior

// Player 
const float PLAYER_SPEED = 200.0f;          // pixels per second
const float PLAYER_SHOOT_COOLDOWN = 0.5f;   // seconds between shots

// Enemy 
const float ENEMY_BASE_SPEED = 100.0f;        // Grunt speed (pixels/sec)
const float ENEMY_BASE_SHOOT_COOLDOWN = 2.0f; // Grunt shoot cooldown (sec)
const float RUSHER_SPEED = 180.0f;            // Rusher speed (pixels/sec)
const float GUNNER_SHOOT_COOLDOWN = 0.8f;     // Gunner shoot cooldown (sec)

// Bullet 
const float BULLET_SPEED = 300.0f;          // pixels per second

// Spawner 
const float ENEMY_SPAWN_COOLDOWN = 2.0f;    // seconds between enemy spawns
const int WEAPON_DROP_CHANCE = 20;          // percent chance an enemy drops a pickup