#include "Attacker3.h"
#include <iostream>

Attacker3::Attacker3(int hp, int spd, int dmg, int threshold, int boost) : Attacker(hp, spd, dmg), lowHPThreshold(threshold), speedBoost(boost) {}

void Attacker3::update() {
    if (hp <= lowHPThreshold) {
        speed += speedBoost;
        std::cout << "[Attacker3] Low health! Speed increased by "
                  << speedBoost << " to " << speed
                  << std::endl;
    } else {
        std::cout << "[Attacker3] hp = " << hp
              << " speed = " << speed
              << " damage = " << damage
              << std::endl;
    }
}