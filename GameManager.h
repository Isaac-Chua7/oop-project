#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include"GameCharacter.h"
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

class GameManager{
    protected:
        vector<GameCharacter*> gameCharacters; 
        int roundNumber;
    
    public:
        GameManager();
        vector<GameCharacter*>& getGameCharacters();
        ~GameManager();
        bool isGameOver();
        void clearTerminal();
        void printBoard();
        void nextTurn();
};

#endif