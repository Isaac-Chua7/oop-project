#include "GameManager.h"

GameManager::GameManager() { roundNumber = 0; };

vector<GameCharacter*>& GameManager::getGameCharacters() {
  return gameCharacters;
};

GameManager::~GameManager() {};

bool GameManager::isGameOver() {
  for (int i = 0; i < gameCharacters.size(); i++) {
    if (gameCharacters[i]->getPosition().getCol() == 0) {
      clearTerminal();
      cout << "Gameover" << endl;
      return true;
    }
  }
  return false;
}

void GameManager::clearTerminal() {
#ifdef _WIN32
  system("cls");  // Windows
#else
  system("clear");  // Linux, macOS
#endif
}

void GameManager::printBoard() {
  int numRows = 5;
  int numCols = 10;

  string board[numRows][numCols];

  for (int r = 0; r < numRows; r++)
    for (int c = 0; c < numCols; c++) board[r][c] = "[  ]";

  for (int i = 0; i < gameCharacters.size(); i++) {
    if (gameCharacters[i] != nullptr) {
      Coordinate pos = gameCharacters[i]->getPosition();
      int r = pos.getRow();
      int c = pos.getCol();

      if (r >= 0 && r < numRows && c >= 0 && c < numCols) {
        string name = gameCharacters[i]->getName();
        board[r][c] = "[" + name + "]";
      }
    }
  }

  cout << endl;
  for (int r = 0; r < numRows; r++) {
    for (int c = 0; c < numCols; c++) {
      cout << board[r][c];
    }
    cout << endl;
  }
  cout << endl;
}

void GameManager::nextTurn(){
    if(isGameOver() == false){
        clearTerminal();
        printBoard();
    }
}