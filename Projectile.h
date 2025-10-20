#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameCharacter.h"

using namespace std;

class Projectile : public GameCharacter {
 protected:
  int damage;

 public:
  Projectile(int row, int col);
  int getDamage();
  void move();
  ~Projectile();
};

#endif