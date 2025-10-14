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
    // Attacker(int hp, int spd, int dmg);
    Attacker(int r, int c, int hp, int spd, int dmg);

    // GameCharacter();
    // GameCharacter(int r, int c, int hp);
    // virtual ~GameCharacter();


    void takeDamage(int dmg) override;
    void move(int deltaCol);
    int getSpeed();
    int getDamage();
    // void attacker(Defender* p);
    virtual void update() = 0;

};

#endif