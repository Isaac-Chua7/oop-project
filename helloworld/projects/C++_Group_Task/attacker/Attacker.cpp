#include "Attacker.h"
#include "GameCharacter.h"
#include "Coordinate.h"
#include <cstdlib> 
#include <ctime> // Both the <cstdlib> and <ctime> is to generate a random no.
// #include "Defender.h"

// Attacker::Attacker(int hp, int spd, int dmg) : hp(hp), speed(spd), damage(dmg) {}

/* 
This is to iniitialise a new Attacker object, where it randomly places the attaker on any row from 0 to 4, on any col to 9.
This is so that the attacker starts on the right side of the board.
*/
Attacker::Attacker() {

    // This shows that the attacker will be randomly placed at any row on the right side
    position.row = rand() % 5;
    position.col = 9;
}
/* 
This is to reduce the attacker's health by the damage amount.
This shows that the health should never go below 0.
This function uses the health variable inherited from GameCharacter.
*/
void Attacker::takeDamage(int dmg) {
    health -= dmg; // this uses inherit health
    if (health < 0) {
        health = 0;
    }
}
/* 
This is to show that it is returning the attacker's speed value.
*/
int Attacker::getSpeed() {
    return speed;
}

/*  
This shows that it is returning the attacker's damage value.
This is to find out the damage amount the attacker could deal to another character.
*/
int Attacker::getDamage() {
    return damage;
}

/*  
This shows the attacker moves by one col to the left of the board, which
the attacker is moving towards the player/target
*/
void Attacker::move() {
    position.col--;
}