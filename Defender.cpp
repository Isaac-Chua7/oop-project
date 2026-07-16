#include "Defender.h"
#include "GameCharacter.h"

using namespace std;

Defender :: Defender(int row, int col) {
    position.row = row;
    position.col = col;
}



int Defender::getCost() {
    return cost;
}

void Defender::move(){}
