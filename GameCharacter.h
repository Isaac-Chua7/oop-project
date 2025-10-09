#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

struct Coordinate{
    public:
    int row;
    int col;    
    int getRow();
    void setRow(int r);
    int getCol();
    void setCol(int c);
};

class GameCharacter{
    protected:
        Coordinate position;
        int health;
    
    public:
        GameCharacter();
        GameCharacter(int hp);
        virtual ~GameCharacter();
        int getHealth();
        void setHealth(int health);
        virtual void takeDamage(int dmg);
        virtual void update() = 0;
};

#endif