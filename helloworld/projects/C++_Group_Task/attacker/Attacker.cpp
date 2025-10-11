#include "Attacker.h"
#include "defender.h"

Attacker::Attacker(int hp, int spd, int dmg) : hp(hp), speed(spd), damage(dmg) {}

void Attacker::takeDamage(int dmg) {
    hp -= dmg;
    if (hp < 0) {
        hp - 0;
    }
}

int Attacker::getSpeed() {
    return speed;
}

int Attacker::getDamage() {
    return damage;
}

void Attacker::attacker(Defender* p) {
    if (!p) {
        return;
    }

    p->takeDamage(damage);
    
}