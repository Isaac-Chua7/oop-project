#include "Attacker.h"
#include "GameCharacter.h"
#include "Coordinate.h"
// #include "Defender.h"

// Attacker::Attacker(int hp, int spd, int dmg) : hp(hp), speed(spd), damage(dmg) {}

Attacker::Attacker(int r, int c, int hp, int spd, int dmg) : GameCharacter(r, c, hp), speed(spd), damage(dmg) {}

void Attacker::takeDamage(int dmg) {
    hp -= dmg; // this uses inherit health
    if (hp < 0) {
        hp = 0;
    }
}

int Attacker::getSpeed() {
    return speed;
}

int Attacker::getDamage() {
    return damage;
}

// void Attacker::attacker(Defender* p) {
//     if (!p) {
//         return;
//     }

//     p->takeDamage(damage);
    
// }

// move function by 1 col
void Attacker::move(int deltaCol) {
    position.col += deltaCol;
}

GameCharacter::GameCharacter(int r, int c, int hp) {
    health = hp;
    position.row = r;
    position.col = c;
  }