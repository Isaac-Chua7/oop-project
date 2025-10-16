#include "Attacker.h"
#include "GameCharacter.h"
#include "Coordinate.h"
#include <cstdlib>
#include <ctime>
// #include "Defender.h"

// Attacker::Attacker(int hp, int spd, int dmg) : hp(hp), speed(spd), damage(dmg) {}

Attacker::Attacker(int maxRow, int maxCol, int hp, int spd, int dmg) : GameCharacter(0, 0, hp), speed(spd), damage(dmg) {

    // This shows that the attacker will be randomly placed at any row on the right side
    srand(static_cast<unsigned>(time(nullptr)));

    position.row = rand() % maxRow;
    position.col = maxCol - 1;
}

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

// move function by 1 col
void Attacker::move(int deltaCol) {
    position.col += deltaCol;
}

GameCharacter::GameCharacter(int r, int c, int hp) {
    health = hp;
    position.row = r;
    position.col = c;
  }