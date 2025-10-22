#include "GameManager.h"

#include "Attacker.h"
#include "Attacker1.h"
#include "Attacker2.h"
#include "Attacker3.h"
#include "Defender.h"
#include "Defender1.h"
#include "Defender2.h"
#include "Defender3.h"

GameManager::GameManager() {  // default constructor, no parameterised
                              // constructor is needed
  this->money = 100;
  this->income = 25;
  this->roundNumber = 1;
};

// initialising vectors for attackers and defenders

vector<GameCharacter*>& GameManager::getGameAttackers() {
  return gameAttackers;
};

vector<GameCharacter*>& GameManager::getGameDefenders() {
  return gameDefenders;
};

// default constructor that takes care of dynamically allocated attackers and
// defenders
GameManager::~GameManager() {
  for (int i = 0; i < gameAttackers.size(); i++) {
    delete gameAttackers[i];
  }

  for (int i = 0; i < gameDefenders.size(); i++) {
    delete gameDefenders[i];
  }
};

// checks the col number of all attackers to see if any have made it to the end
// of the row
bool GameManager::isGameOver() {
  for (int i = 0; i < gameAttackers.size(); i++) {
    if (gameAttackers[i]->getPosition().getCol() ==
        0) {  // set to negative one as attackers can walk here but plants
              // can't be placed.
      clearTerminal();
      cout << "Gameover" << endl;
      return true;
    }
  }
  return false;
}

// clears terminal after checking whether user is on windows or mac
void GameManager::clearTerminal() {
#ifdef _WIN32
  system("cls");  // Windows
#else
  system("clear");  // Linux, macOS
#endif
}

// print board function this prints the CLI
void GameManager::printBoard() {
  cout << "Money: " << money << " Income: " << income
       << " Round: " << roundNumber << endl;
  cout << "🌱: 100   🌻: 50" << endl;
  int numRows = 5;
  int numCols = 10;

  string board[numRows][numCols];  // the board/grid is just a static 2D array

  for (int r = 0; r < numRows; r++)
    for (int c = 0; c < numCols; c++)
      board[r][c] = "[  ]";  // initialising the board

  for (int i = 0; i < gameDefenders.size();
       i++) {  // adding projectiles to the board
    if (gameDefenders[i]->getType() == "Defender1" &&
        !gameDefenders[i]->getProjectiles().empty()) {
      vector<Projectile*> projectiles = gameDefenders[i]->getProjectiles();
      for (int j = 0; j < projectiles.size(); j++) {
        Coordinate pos = projectiles[j]->getPosition();
        int r = pos.getRow();
        int c = pos.getCol();

        if (r >= 0 && r < numRows && c >= 0 && c < numCols) {
          string name = projectiles[j]->getName();
          board[r][c] = "[" + name + "]";
        }
      }
    }
  }

  for (int i = 0; i < gameDefenders.size();
       i++) {  // adding defenders to board array before printing
    if (gameDefenders[i] != nullptr) {
      Coordinate pos = gameDefenders[i]->getPosition();
      int r = pos.getRow();
      int c = pos.getCol();

      if (r >= 0 && r < numRows && c >= 0 && c < numCols) {
        string name = gameDefenders[i]->getName();
        board[r][c] = "[" + name + "]";
      }
    }
  }

  for (int i = 0; i < gameAttackers.size();
       i++) {  // adding attackers to board array before printing
    if (gameAttackers[i] != nullptr) {
      Coordinate pos = gameAttackers[i]->getPosition();
      int r = pos.getRow();
      int c = pos.getCol();

      if (r >= 0 && r < numRows && c >= 0 && c < numCols) {
        string name = gameAttackers[i]->getName();
        board[r][c] = "[" + name + "]";
      }
    }
  }

  cout << endl;
  // this is where the board is actually printed
  for (int r = 0; r < numRows; r++) {
    for (int c = 0; c < numCols; c++) {
      cout << board[r][c];
    }
    cout << endl;
  }
  cout << endl;
}

// this runs each turn after it has been confirmed that the game is not yet over
void GameManager::nextTurn() {
  clearTerminal();
  money = money + income;
  roundNumber++;

  int numberOfSpawns = rand() % (roundNumber / 2);

  for (int i = 0; i < gameAttackers.size(); i++) {
    gameAttackers[i]->move();
  }

  for (int i = 0; i < numberOfSpawns; i++) {
    addAttacker();
  }

  // getting Defender1 to shoot and projectiles to move forward
  for (int i = 0; i < gameDefenders.size(); i++) {
    gameDefenders[i]->move();
    if (gameDefenders[i]->getType() == "Defender1" &&
        !gameDefenders[i]->getProjectiles().empty()) {
      vector<Projectile*> projectiles = gameDefenders[i]->getProjectiles();
      for (int j = 0; j < projectiles.size(); j++) {
        projectiles[j]->move();
      }
    }
  }

  handleProjectileCollisions();
  removeDeadCharacters();

  printBoard();
  promptPlayer();
}

// this guides the player through their turn and ensures they enter appropriate
// inputs
int GameManager::promptPlayer() {
  string decision1 = "";  // whether or not they want to buy a plant
  int decision2;          // what type of plant they want to buy
  int decisionRow;        // the row that they want to place the plant
  int decisionCol;        // the column that they want to place the plant

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
    cout << "What plant do you want to buy (1/2):\n";
    cin >> decision2;
    while (decision2 != 1 && decision2 != 2) {
      cout << "Invalid input\nWant plant do you want to buy (1/2):\n";
      cin.clear();
      cin.ignore(100, '\n');
      cin >> decision2;
    }

    do {
      cout << "Which row do you want to place the plant (0-4)\n";
      cin >> decisionRow;
      while (decisionRow > 4 || decisionRow < 0 || decisionRow % 1 != 0) {
        cout << "Invalid input\nWhich row do you want to place the plant "
                "(0-4)\n";
        cin.clear();
        cin.ignore(10, '\n');
        cin >> decisionRow;
      }

      cout << "Which column do you want to place the plant (0-9)\n";
      cin >> decisionCol;
      while (decisionCol > 9 || decisionRow < 0 || decisionRow % 1 != 0) {
        cout << "Invalid input\nWhich column do you want to place the plant "
                "(0-9)\n";
        cin.clear();
        cin.ignore(10, '\n');
        cin >> decisionCol;
      }
    } while (!isGridSpaceFree(decisionRow, decisionCol));
  }

  // call the addDefender function with the type of plant and
  // where the user wants to place it has parameters
  addDefender(decision2, decisionRow, decisionCol);

  return 0;
}

// this function adds the desired defender to the board at the desired position
// after ensuring the player has sufficient funds
void GameManager::addDefender(int attackerType, int r, int c) {
  if (attackerType == 1) {
    if (money >= 100) {
      gameDefenders.push_back(new Defender1(r, c));
      money = money - 100;
      income = income - 25;  // planting a 🌱 loses the player income
    } else {
      cout << "Failed to purchase plant, insuficient funds\n";
    }
  } else if (attackerType == 2) {
    if (money >= 50) {
      gameDefenders.push_back(new Defender2(r, c));
      income = income + 50;
      money = money - 50;
    } else {
      cout << "Failed to purchase plant, insufficient funds\n";
    }
  } else {
    cout << "Failed to pruchase plant, insufficient funds\n";
  }
}

// this function adds a random attacker to the board, the row they spawn in is
// also randomly decided (this is done in the attacker constructor)
void GameManager::addAttacker() {
  int whatToSpawn = (rand() % 3) + 1;

  switch (whatToSpawn) {
    case 1:
      gameAttackers.push_back(
          new Attacker1);  // all attackers just have a default constructor
      break;
    case 2:
      gameAttackers.push_back(new Attacker2);
      break;
    case 3:
      gameAttackers.push_back(new Attacker3);
      break;
    default:
      gameAttackers.push_back(new Attacker1);
      break;
  }
}

int GameManager::getRoundNumber() { return roundNumber; }

// this function runs each turn to check whether a game character has 0 health,
// if so it removes them from the game.
void GameManager::removeDeadCharacters() {
  // removing dead attackers
  for (int i = 0; i < gameAttackers.size();) {
    if (gameAttackers[i]->getHealth() <= 0) {
      delete gameAttackers[i];
      gameAttackers.erase(gameAttackers.begin() + i);
    } else {
      i++;  // i in only incremented when nothing is erased
    }
  }

  // removing dead attackers
  for (int i = 0; i < gameDefenders.size();) {
    if (gameDefenders[i]->getHealth() <= 0) {
      delete gameDefenders[i];
      gameDefenders.erase(gameDefenders.begin() + i);
    } else {
      i++;  // i in only incremented when nothing is erased
    }
  }
}

// this function is called when the code is compiled and introduces the player
// to the game
void GameManager::introduction() {
  clearTerminal();
  string isNewPlayer = "";

  cout << "Are you new to this game? (Y/N)\n";
  cin >> isNewPlayer;

  isNewPlayer[0] = toupper(isNewPlayer[0]);

  while (isNewPlayer != "Y" && isNewPlayer != "N") {
    cout << "Invalid input\nAre you new to this game? (Y/N)\n";
    cin >> isNewPlayer;
    isNewPlayer[0] = toupper(isNewPlayer[0]);
  }

  if (isNewPlayer == "Y") {
    cout
        << "This is a turn based tower defence game where the objective is to\n"
           "stop the attackers 🦆, 🐗, 🐤 from reaching the end of the row "
           "they spawn\n"
           "in you can do this by placing defenders down to stop them. You\n"
           "get 3 choices 🌱, 🌻, 🌰 the plant will slowly damage defenders\n"
           "by shooting projectiles, the sunflower will grant you more cash\n"
           "each turn to buy defenders and the nut will provide a temporary\n"
           "blockade hindering the attackers progress\n";
  }
}

// projectile collision with attackers was done by ChatGPT
void GameManager::handleProjectileCollisions() {
  for (size_t i = 0; i < gameDefenders.size(); ++i) {
    // Only Defender1 has projectiles
    auto* d1 = dynamic_cast<Defender1*>(gameDefenders[i]);
    if (!d1) continue;

    auto& projectiles = d1->getProjectiles();  // reference to real vector

    // Loop over projectiles
    for (size_t j = 0; j < projectiles.size();) {
      Projectile* p = projectiles[j];
      if (!p) {
        projectiles.erase(projectiles.begin() + j);
        continue;
      }

      Coordinate pPos = p->getPosition();
      bool projectileRemoved = false;

      // Check against all attackers
      for (size_t k = 0; k < gameAttackers.size(); ++k) {
        GameCharacter* a = gameAttackers[k];
        if (!a) continue;

        Coordinate aPos = a->getPosition();

        // Check: same row, and same col OR 1 column ahead
        if (pPos.getRow() == aPos.getRow() &&
            (pPos.getCol() == aPos.getCol() ||
             pPos.getCol() + 1 == aPos.getCol())) {
          a->takeDamage(p->getDamage());  // attacker takes damage

          // Remove projectile
          delete p;
          projectiles.erase(projectiles.begin() + j);
          projectileRemoved = true;
          break;  // no need to check other attackers
        }
      }

      // Only increment j if projectile wasn’t erased
      if (!projectileRemoved) ++j;
    }
  }
}

// verifies user plant location, by checking if their is already a plant there
bool GameManager::isGridSpaceFree(int row, int col) {
  for (int i = 0; i < gameDefenders.size(); i++) {
    Coordinate pos = gameDefenders[i]->getPosition();
    if (pos.row == row && pos.col == col) {
      cout << "Grid Location Occupied, pick a different spot" << endl;
      return false;
    }
  }
  return true;
}