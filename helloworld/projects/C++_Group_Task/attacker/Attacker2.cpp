#include "Attacker2.h"
#include <iostream>
#include <algorithm>

// This shows that Attacker2 shows no different things, while the emoji shows that it reprsents a different attacker
Attacker2::Attacker2() {
    
    // initialises the constructor for Atacker2 - showing the attacker default values
    health = 5;
    damage = 1;
    speed = 1;
    position.col = 9;
    name = "🐗";
    armour = 3; // This shows that Attacker has an additional ability, where it has an armour value of 3

    if (health < 0) {
        health = 0;
    }
}
// Shows Attacker2's info - with the armour stat
void Attacker2::update() {
    std::cout << "[Attacker2] hp = " << health
              << " speed = " << speed
              << " damage = " << damage
              << " armour = " << armour
              << std::endl;

    armour += 1;
}