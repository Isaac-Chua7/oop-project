#ifndef ATTACKER1_H
#define ATTACKER1_H

#include "Attacker.h"

class Attacker1 : public Attacker {
public:
    Attacker1(int r, int c, int hp, int spd, int dmg);
    void update() override;
};

#endif
