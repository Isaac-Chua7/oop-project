#ifndef ATTACKER3_H
#define ATTACKER3_H

#include "Attacker.h"

class Attacker3 : public Attacker {
private:
    int lowHPThreshold;
    int speedBoost;

public:
    Attacker3(int hp, int spd, int dmg, int threshold, int boost);
    void update() override;
};

#endif