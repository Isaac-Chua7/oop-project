#ifndef ATTACKER_H
#define ATTACKER_H

#include "GameCharacter.h" // This is included as Attacker inherits from it.

// class Defender;

class Attacker : public GameCharacter { // Inherits from GameCharacter
protected:
    // Shows how high the speed is, and the amount of damage it deals
    int speed;
    int damage;

public:
    Attacker(); // initialise the constructor for a new attacker
    void takeDamage(int dmg); // to reduce the attacker's health when hit
    void move(); // makes the attacker to move one col forward
    int getSpeed(); // returns the attacker's speed
    int getDamage(); // returns the amount of damage the attacker could cause
    virtual void update() = 0; // this is an abstract class, which you can't create an Attacker directly - only through subclasses that define update()

};

#endif