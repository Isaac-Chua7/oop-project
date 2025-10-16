#include "Attacker3.h"
#include <iostream>

Attacker3::Attacker3() {
    health = 5;
    damage = 1;
    speed = 1;
    position.col = 9;
    name = "🧟‍♂️";
    speedBoost = 2;

    if (health < 0) {
        health = 0;
    }
}

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

// move function by 1 col
void Attacker::move() {
    position.col--;
}