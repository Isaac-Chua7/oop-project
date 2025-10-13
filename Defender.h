#ifndef DEFENDER_H
#define DEFENDER_H
#include "GameCharacter.h"

using namespace std;

class Defender : public GameCharacter {
    protected:
        int cost;
    
    public:
        Defender(int hp, int cost);
    
    virtual ~Defender() = default;

    void takeDamage(int dmg) override; //Overrides the takeDamage method from GameCharacter.

    int getCost() const;

    virtual void update() = 0; //This function is intended to define the defender's behavior for a single turn (e.g., attacking, generating resources).

};

#endif