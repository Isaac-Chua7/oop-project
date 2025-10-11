#include "Attacker1.h"
#include <iostream>

Attacker1::Attacker1(int hp, int spd, int dmg) : Attacker(hp, spd, dmg) {}

void Attacker1::update() {
    std::cout << "[Attacker1] hp = " << hp
              << " speed = " << speed
              << " damage = " << damage
              << std::endl;
}