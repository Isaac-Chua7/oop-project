#include "Attacker2.h"
#include <iostream>
#include <algorithm>

Attacker2::Attacker2() {
    health = 5;
    damage = 1;
    speed = 1;
    position.col = 9;
    name = "🐗";
    armour = 3;
    type = "Attacker2";
}

void Attacker2::update() {
    std::cout << "[Attacker2] hp = " << health
              << " speed = " << speed
              << " damage = " << damage
              << " armour = " << armour
              << std::endl;

    armour += 1;
}
