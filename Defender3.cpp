#include "Defender3.h"
#include <iostream>
#include "Coordinate.h"

using namespace std;

const int Defender3HP = 100;
const int Defender3Cost = 50;

Defender3 :: Defender3() : Defender(Defender3HP, Defender3Cost) {}

void Defender3 :: update() {
    cout << "Defender3 at (" << position.x << ", " << position.y << ") is blocking the attackers." << endl;
}