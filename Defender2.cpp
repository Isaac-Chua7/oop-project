#include "Defender2.h"

#include "Defender.h"
#include "GameCharacter.h"

using namespace std;

Defender2 ::Defender2(int row, int col) : Defender(row, col) {
  health = 5;
  name = "🌻";
  incomeBonus = 50;
}

int Defender2::getIncomeBonus() { return incomeBonus; }