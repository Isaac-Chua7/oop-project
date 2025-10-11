#ifndef ATTACKER_H
#define ATTACKER_H

class Defender;

class Attacker {
protected:
    int hp;
    int speed;
    int damage;

public:
    Attacker(int hp, int spd, int dmg);

    void takeDamage(int dmg);
    int getSpeed();
    int getDamage();
    void attacker(Defender* p);
    virtual void update() = 0;

};

#endif