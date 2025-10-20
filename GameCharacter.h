#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include"Coordinate.h"
#include<string>
#include<vector>

using namespace std;

class Projectile;

class GameCharacter{
    protected:
        Coordinate position;
        int health;
        string name;
        string type;
        
    
    public:
        GameCharacter();
        GameCharacter(int r, int c, int hp);
        virtual ~GameCharacter();
        int getHealth();
        void setHealth(int health);
        void takeDamage(int dmg);
        Coordinate getPosition();
        string getName();
        void setName(string name);
        virtual void move() = 0; 
        string getType();
        virtual vector<Projectile*>& getProjectiles();

};

#endif