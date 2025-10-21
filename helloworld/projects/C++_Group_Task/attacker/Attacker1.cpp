#include "Attacker1.h"
#include <iostream>

// This shows Attacker1 where it initialises the constructor 
Attacker1::Attacker1() {
    // this shows that Attacker's stats
    health = 5;
    damage = 1;
    speed = 1;
    position.col = 9; // this shows that this attacker starts on the right side of the board
    name = "🦆"; // use an emoji to easily show that this shows it is an attacker

    if (health < 0) {
        health = 0;
    }
}

// This shows Attacker1's info (stats)
void Attacker1::update() {
    std::cout << "[Attacker1] hp = " << health
              << " speed = " << speed
              << " damage = " << damage
              << std::endl;
}