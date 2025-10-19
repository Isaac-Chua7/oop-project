#ifndef DEFENDER1_H
#define DEFENDER1_H
#include "Defender.h"
#include "GameCharacter.h"

using namespace std;

class Defender1 : public Defender {
 protected:
  int fireRate;
  int damage;

 public:
  Defender1(int row, int col);

  int getDamage();

  int getFireRate();


};

#endif