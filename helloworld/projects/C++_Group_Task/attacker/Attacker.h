#ifndef ATTACKER_H
#define ATTACKER_H

#include "GameCharacter.h"

// class Defender;

class Attacker : public GameCharacter {
protected:
    int hp;
    int speed;
    int damage;

public:
    Attacker(int maxRow, int maxCol, int hp, int spd, int dmg);
    void takeDamage(int dmg) override;
    void move(int deltaCol);
    int getSpeed();
    int getDamage();
    virtual void update() = 0;

};

#endif