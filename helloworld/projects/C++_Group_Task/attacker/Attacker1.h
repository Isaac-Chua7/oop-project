#ifndef ATTACKER1_H
#define ATTACKER1_H

/* 
inherits from Attacker so that Attacker1 could get access to the stats.
this is so that you don't need to repeat writing the stats
*/
#include "Attacker.h"


class Attacker1 : public Attacker {
public:
    Attacker1(); // initialise the constructor - inheriting from Attacker
    void update() override; // this function overrides the pure virtual 
};

#endif
