#ifndef ATTACKER2_H
#define ATTACKER2_H

#include "Attacker.h"

class Attacker2 : public Attacker {
protected:
    int armour; // An additional abillity for Attacker2

public:
    Attacker2(); // Inherits from Attacker, doesnt need to repeat things
    int reduceDamage(int dmg);
    int getArmour() const { return armour; }
    void setArmour(int a) { armour = a; }
    
    void update() override;
};

#endif