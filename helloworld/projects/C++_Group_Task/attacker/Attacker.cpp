#include "Attacker.h"
#include "GameCharacter.h"
#include "Coordinate.h"
#include <cstdlib>
#include <ctime>
// #include "Defender.h"

// Attacker::Attacker(int hp, int spd, int dmg) : hp(hp), speed(spd), damage(dmg) {}

Attacker::Attacker() {

    // This shows that the attacker will be randomly placed at any row on the right side
    srand(static_cast<unsigned>(time(nullptr)));

    position.row = rand() % 4;
    position.col = 9;
}

void Attacker::takeDamage(int dmg) {
    health -= dmg; // this uses inherit health
    if (health < 0) {
        health = 0;
    }
}

int Attacker::getSpeed() {
    return speed;
}

int Attacker::getDamage() {
    return damage;
}

// move function by 1 col
void Attacker::move() {
    position.col--;
}

// GameCharacter::GameCharacter(int r, int c, int hp) {
//     health = hp;
//     position.row = r;
//     position.col = c;
//   }