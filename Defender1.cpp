#include "Defender1.h"

#include "Defender.h"
#include "GameCharacter.h"

using namespace std;

Defender1 ::Defender1(int row, int col) : Defender(row, col) {
  health = 7;
  damage = 1;
  fireRate = 1;
  name = "🌱";
}

int Defender1::getDamage() { return damage; }

int Defender1::getFireRate() { return fireRate; }