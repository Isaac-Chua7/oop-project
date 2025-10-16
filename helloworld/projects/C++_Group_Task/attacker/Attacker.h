#ifndef ATTACKER_H
#define ATTACKER_H

#include "GameCharacter.h"

// class Defender;

class Attacker : public GameCharacter {
protected:
    int speed;
    int damage;

public:
    Attacker();
    void takeDamage(int dmg);
    void move();
    int getSpeed();
    int getDamage();
    virtual void update() = 0;

};

#endif