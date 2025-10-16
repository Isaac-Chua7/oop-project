#include "Attacker2.h"
#include <iostream>
#include <algorithm>

Attacker2::Attacker2(int r, int c, int hp, int spd, int dmg, int armourValue) : Attacker(r, c, hp, spd, dmg), armour(armourValue) {}

int Attacker2::reduceDamage(int dmg) {
    int damageTaken = std::max(0, dmg - armour);
    hp -= damageTaken;

    if (hp < 0) {
        hp = 0;
    }

    return damageTaken;
}

void Attacker2::update() {
    std::cout << "[Attacker2] hp = " << hp
              << " speed = " << speed
              << " damage = " << damage
              << " armour = " << armour
              << std::endl;

    armour += 1;
}