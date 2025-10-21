#ifndef ATTACKER3_H
#define ATTACKER3_H

/*
inheriting from Attacker - access Attacker's stats
*/
#include "Attacker.h"

class Attacker3 : public Attacker {
private:
    // this is to show the health level at which the attacker will activate its ability
    int lowHPThreshold;
    // defines the amount of the attacker's speed where the speed will increase when the health is low
    int speedBoost;

public:
    Attacker3(); // initialise the constructor for Attacker3's stats and the additional ability
    void update() override; // to override the virtual function from Attacker for the behaviouir (e.g. increasing speed when health is low)
};

#endif