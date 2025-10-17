#include "GameManager.h"

void introduction() {
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
           "stop the attackers 🏃 from reaching the end of the row they spawn\n"
           "in you can do this by placing defenders down to stop them. You\n"
           "get 3 choices 🌱, 🌻, 🌰 the plant will slowly damage defenders\n"
           "by shooting projectiles, the sunflower will grant you more cash\n"
           "each turn to buy defenders and the nut will provide a temporary\n"
           "blockade hindering the attackers progress\n";
  }
}

int main() {
  srand(time(NULL));
  GameManager gm;

  introduction();

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
    gm.clearTerminal();
    cout << "Game Starting\n";
    gm.printBoard();
  }

  gm.promptPlayer();

  while (gm.isGameOver() == false) {
    gm.nextTurn();
  }

  cout << "YOU SURVIVED " << gm.getRoundNumber() << " ROUNDS";

  return 0;
}
