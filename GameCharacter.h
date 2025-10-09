#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

struct Coordinate{
    public:
    int row;
    int col;    
    int getRow(GameCharacter* gc);
    int getCol(GameCharacter* gc);
};

class GameCharacter{
    protected:
        Coordinate position;
        int health;
    
    public:
        GameCharacter();
        GameCharacter(int hp);
        virtual ~GameCharacter();
        int getHealth(GameCharacter* gc);
        virtual void takeDamage(int dmg);
        virtual void update() = 0;
};

#endif