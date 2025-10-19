#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include"GameCharacter.h"
#include<iostream>
#include<vector>
#include<cstdlib>
#include"Attacker.h"

using namespace std;

class GameManager{
    protected:
        int money;
        int income;
        int roundNumber;
        vector<GameCharacter*> gameAttackers; 
        vector<GameCharacter*> gameDefenders; 
    
    public:
        GameManager();
        vector<GameCharacter*>& getGameAttackers();
        vector<GameCharacter*>& getGameDefenders();
        ~GameManager();
        bool isGameOver();
        void clearTerminal();
        void printBoard();
        void nextTurn();
        int promptPlayer();
        void addAttacker();
        void addDefender(int attackerType, int row, int col);
        int getRoundNumber();
        void removeDeadCharacters();
        void introduction();


};

#endif