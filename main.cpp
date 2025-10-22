#include "GameManager.h"
#include <fstream>

int main() {
  //begins with seeding for later random number generation
  srand(time(NULL));

  //creates game manager
  GameManager gm;

// runs introduction function
  gm.introduction();

//input handling and checking if user is ready
  string ready = "";

  cout << "Are you ready to start this game? (Y/N)\n";
  cin >> ready;

  ready[0] = toupper(ready[0]);

  while (ready != "Y") {
    cout << "Are you ready to start this game? (Y/N)\n";
    cin >> ready;
    ready[0] = toupper(ready[0]);
  }

//once ready starts game
  if (ready == "Y") {
    gm.clearTerminal();
    cout << "Game Starting\n";
    gm.printBoard();
  }

//prompts guide the player through the course of a turn
  gm.promptPlayer();

//for loop of next turns until the game is over
  while (gm.isGameOver() == false) {
    gm.nextTurn();
  }

  // Create a text file
  ofstream MyFile("Previous_Scores.txt");

  // Write to the file
  MyFile << "YOU SURVIVED " << gm.getRoundNumber() << " ROUNDS\n";

  // Close the file
  MyFile.close();

  string endGameText;

  ifstream ReadFile("Previous_Scores.txt");

    while (getline (ReadFile, endGameText)) {
    // Output the text from the file
    cout << endGameText;
  }

  ReadFile.close();


  return 0;
}
