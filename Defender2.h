#ifndef DEFENDER2_H
#define DEFENDER2_H
#include "Defender.h"

using namespace std;

class Defender2 : public Defender {
 private:
  int incomeBonus;

 public:
  Defender2(int row, int col);
  int getIncomeBonus();
};
#endif