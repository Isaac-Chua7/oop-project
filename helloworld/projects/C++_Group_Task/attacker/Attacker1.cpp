#include "Attacker1.h"
#include <iostream>

Attacker1::Attacker1(int r, int c, int hp, int spd, int dmg) : Attacker(r, c, hp, spd, dmg) {}

void Attacker1::update() {
    std::cout << "[Attacker1] hp = " << hp
              << " speed = " << speed
              << " damage = " << damage
              << std::endl;
}