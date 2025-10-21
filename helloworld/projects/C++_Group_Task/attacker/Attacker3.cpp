#include "Attacker3.h"
#include <iostream>

Attacker3::Attacker3() {
    // initialises the constructor for Atacker3 - showing the attacker default values
    health = 5;
    damage = 1;
    speed = 1;
    position.col = 9;
    name = "🐤";
    speedBoost = 2; // shows an additional ability for Attacker3, where if the health is low, then it will have more speed boost

    if (health < 0) {
        health = 0;
    }
}

// shows Attacker3's stats - also showing the speedBoost stat
void Attacker3::update() {
    if (health <= lowHPThreshold) {
        speed = speedBoost;
        std::cout << "[Attacker3] Low health! Speed increased by "
                  << speedBoost << " to " << speed
                  << std::endl;
    } else {
        std::cout << "[Attacker3] hp = " << health
              << " speed = " << speed
              << " damage = " << damage
              << std::endl;
    }
}