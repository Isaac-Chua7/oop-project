#include "Defender3.h"
#include "Defender.h"

using namespace std;

Defender3 :: Defender3(int row, int col) : Defender(row, col) {
    health = 10;
    name = "🌰";
    type = "Defender3";
}
