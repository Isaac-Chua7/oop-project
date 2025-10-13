#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include"Coordinate.h"
#include<string>

using namespace std;

class GameCharacter{
    protected:
        Coordinate position;
        int health;
        
    
    public:
        string name;
        GameCharacter();
        GameCharacter(int r, int c, int hp);
        virtual ~GameCharacter();
        int getHealth();
        void setHealth(int health);
        virtual void takeDamage(int dmg);
        //virtual void update() = 0; commented out to try instantiate
        Coordinate getPosition();
        string getName();

};

#endif