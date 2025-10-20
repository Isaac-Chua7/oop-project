#include "Defender1.h"

#include "Defender.h"
#include "GameCharacter.h"

using namespace std;

Defender1 ::Defender1(int row, int col) : Defender(row, col) {
  health = 7;
  willFire = 1;
  name = "🌱";
  type = "Defender1";
}

void Defender1::move() {
  if (willFire % 2 == 0) {
    projectiles.push_back(new Projectile(position.row, position.col + 1));
  }
  willFire++;
}

vector<Projectile*>& Defender1::getProjectiles() { return projectiles; }
