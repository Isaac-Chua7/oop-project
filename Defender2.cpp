#include "Defender2.h"
#include <iostream>
#include "Coordinate.h"

using namespace std;

const int Defender2HP = 50;
const int Defender2Cost = 25;
const int Defender2Income = 10;

Defender2 :: Defender2() : Defender(Defender2HP, Defender2Cost), income(Defender2Income) {}

void Defender2 :: update() {
    this -> increaseMoney();
}

void Defender2 :: increaseMoney() {
    cout << "Defender2 at (" << position.x << ", "position.y <<") generated " << this -> income << " resources" << endl;

}