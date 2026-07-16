#ifndef DEFENDER1_H
#define DEFENDER1_H
#include <vector>

#include "Defender.h"
#include "GameCharacter.h"
#include "Projectile.h"

using namespace std;

class Defender1 : public Defender {
 protected:
  int willFire;
  vector<Projectile*> projectiles;

 public:
  Defender1(int row, int col);

  int getDamage();

  void move();

  vector<Projectile*>& getProjectiles();

  ~Defender1();
};

#endif