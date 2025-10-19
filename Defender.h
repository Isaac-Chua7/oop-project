#ifndef DEFENDER_H
#define DEFENDER_H
#include "GameCharacter.h"

using namespace std;

class Defender : public GameCharacter {
 protected:
  int cost;

 public:
  Defender(int row, int col);
  void move();

  int getCost();

};

#endif