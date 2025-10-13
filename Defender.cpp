#include "Defender.h"
#include "GameCharacter.h"

using namespace std;

Defender :: Defender(int hp, int cost) : GameCharacter(hp), cost(cost) {
 // Constructor body is empty as all initialization
}

//This implementation accesses the 'health' variable, which is assumed to be a protected member of the GameCharacter base class.
void Defender::takeDamage(int dmg) {
    this->health -= dmg;

    if (this->health < 0) { //To prevent health from going below 0
        this->health = 0;
    }
}

int Defender::getCost() const {
    return this->cost;
}
