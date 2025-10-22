#include "GameManager.h"
#include <fstream>

int main() {
  srand(time(NULL));
  GameManager gm;

  gm.introduction();

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

  cout << "YOU SURVIVED " << gm.getRoundNumber() << " ROUNDS\n";

  // Create a text file
  ofstream MyFile("Previous_Scores.txt");

  // Write to the file
  MyFile << "YOU SURVIVED " << gm.getRoundNumber() << " ROUNDS\n";

  // Close the file
  MyFile.close();

  return 0;
}
