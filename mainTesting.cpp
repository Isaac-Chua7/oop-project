// #include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

#include"GameCharacter.h"
#include"GameManager.h"


using namespace std;

void clearTerminal() {
#ifdef _WIN32
  system("cls");  // Windows
#else
  system("clear");  // Linux, macOS
#endif
}

/*bool gameOver() {
  int numOfAttackers = 0;
  for (int i = 0; i < numOfAttackers; i++) {
    if(attacker[i]->getCol() = 0){
        clearTerminal();
        cout << "Game Over";
        return 1;
    }
  }
  return 0;
}*/

void printGrid() {
  cout << "[ ][ ][ ][ ][ ][ ][🏃][ ][ ][🏃]\n[ ][ ][ ][ ][ ][ ][🏃][ ][ ][🏃]\n[ ][ ][ ][🏃][🏃][🏃][ ][ ][ ][🏃]\n[ ][ ][ ][ ][ ][ ][ ][ ][ ][🏃]\n[ ][ ][ ][ ][ ][🏃][ ][ ][ ][ ]\n";

}

int main() {
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
    cout << "This is a turn based tower defence game where the objective is to "
            "stop the attackers 🏃 from reaching the end of the row they spawn "
            "in \n you can do this by placing defenders down to stop them. You "
            "get 3 choices 🌱, 🌻, 🌰 the plant will slowly damage defenders "
            "by shooting projectiles, the sunflower will grant you more cash "
            "each turn to buy defenders and the nut will provide a temporary "
            "blockade hindering the attackers progress\n";
  }

  string ready = "";

  cout << "Are you ready to start this game? (Y/N)\n";
  cin >> ready;

  ready[0] = toupper(ready[0]);

  while (ready != "Y") {
    cout << "Are you ready to start this game? (Y/N)\n";
    cin >> ready;
    ready[0] = toupper(ready[0]);
  }

  if (ready == "Y") {
    clearTerminal();
    cout << "Game Starting\n";
    printGrid();
  }
}