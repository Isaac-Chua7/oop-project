#include "GameManager.h"

#include "Attacker.h"
#include "Attacker1.h"
#include "Attacker2.h"
#include "Attacker3.h"

GameManager::GameManager() {
  this->money = 100;
  this->income = 100;
  this->roundNumber = 1;
  this->numberOfSpawns = 0;
};

vector<GameCharacter*>& GameManager::getGameCharacters() {
  return gameCharacters;
};

GameManager::~GameManager() {};

bool GameManager::isGameOver() {
  for (int i = 0; i < gameCharacters.size(); i++) {
    if (gameCharacters[i]->getPosition().getCol() ==
        -1) {  // set to negative one as attackers can walk here but plants
               // can't be placed.
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
  cout << "Money: " << money << " Income: " << income
       << " Round: " << roundNumber << endl;
  cout << "🌱: 100   🌻: 50   🌰: 25" << endl;
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

void GameManager::nextTurn() {

    clearTerminal();
    money = money + income;
    roundNumber++;

    for(int i = 0; i < gameCharacters.size(); i++){
      gameCharacters[i]->move();
    }

    for (int i = 0; i < roundNumber % 3; i++) {
      addAttacker();
    }

    printBoard();
    promptPlayer();

  }

int GameManager::promptPlayer() {
  string decision1 = "";
  int decision2;
  int decisionRow;
  int decisionCol;

  cout << "Do you want to buy a plant (Y/N):\n";
  cin >> decision1;
  decision1[0] = toupper(decision1[0]);

  while (decision1 != "Y" && decision1 != "N") {
    cout << "Invalid input\nDo you want to buy a plant (Y/N):\n";
    cin >> decision1;
    decision1[0] = toupper(decision1[0]);
  }

  if (decision1 == "N") {
    return 0;
  } else {
    cout << "What plant do you want to buy (1/2/3):\n";
    cin >> decision2;
    while (decision2 != 1 && decision2 != 2 && decision2 != 3) {
      cout << "Invalid input\nWant plant do you want to buy (1/2/3):\n";
      cin >> decision1;
    }
    cout << "Where do you want to place the plant (row number col number)\n";
    cin >> decisionRow;
    cin >> decisionCol;
    while (decisionRow > 4 && decisionRow < 0 && decisionRow % 1 != 0 &&
           decisionCol > 9 && decisionCol < 0 && decisionCol % 1 != 0) {
      cout << "Invalid input\nWhere do you want to place the plant (row number "
              "col number)\n";
      cin >> decisionRow;
      cin >> decisionCol;
      // createPlant(decision2);//use parameters of decision 2 and decision row
      // and col to add to vector.
    }
    return 0;
  }
  return 0;
}
/*
void GameManager::createPlant(Defender* d){
  if(plantType == 1){
    temp = new Defender("");
    gameCharacters.push_back(temp);


  }*/

void GameManager::addAttacker() { // will this work or will it has scope issues?
  int whatToSpawn = numberOfSpawns % 3;
  
  switch (whatToSpawn) {
    case 0:
      gameCharacters.push_back(new Attacker1);  // all attackers just have a default constructor
      break;
    case 1:
      gameCharacters.push_back(new Attacker2);
      break;
    case 2:
      gameCharacters.push_back(new Attacker3);
      break;
    default:
      gameCharacters.push_back(new Attacker1);
      break;
  }

  numberOfSpawns++;
}


/*COMMENTING OUT UNTIL IMPLEMENTED

void GameManager::addDefender1(int r, int c) { // will this work or will it has scope issues?
  gameCharacters.push_back(new Defender1(r, c));  // all defender just have a parameterised constructor with row and col number
}

void GameManager::addDefender2(int r, int c) { // will this work or will it has scope issues?
  gameCharacters.push_back(new Defender2(r, c));  // all defender just have a parameterised constructor with row and col number
}

void GameManager::addDefender3(int r, int c) { // will this work or will it has scope issues?
  gameCharacters.push_back(new Defender3(r, c));  // all defender just have a parameterised constructor with row and col number
}

*/

int GameManager::getRoundNumber(){
  return roundNumber;
}