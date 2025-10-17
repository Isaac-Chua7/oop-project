#include "Attacker1.h"
#include <iostream>

Attacker1::Attacker1() {
    health = 5;
    damage = 1;
    speed = 1;
    position.col = 9;
    name = "🦆";

    if (health < 0) {
        health = 0;
    }
}

void Attacker1::update() {
    std::cout << "[Attacker1] hp = " << health
              << " speed = " << speed
              << " damage = " << damage
              << std::endl;
}

