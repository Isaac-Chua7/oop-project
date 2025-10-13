#include "GameManager.h"
#include "GameCharacter.h"
#include <iostream>
using namespace std;

int main() {
    // Create a GameManager
    GameManager gm;

    // Create some GameCharacters (you said you'll comment out the pure virtual)
    GameCharacter* plant1 = new GameCharacter(1, 2, 100);
    GameCharacter* zombie1 = new GameCharacter(0, 8, 100);
    GameCharacter* plant2 = new GameCharacter(3, 4, 100);

    // Give them names manually (since constructor doesn’t set name)
    plant1->setHealth(90); // just testing method
    zombie1->setHealth(80);
    plant2->setHealth(50);

    // You can either add a setName() function to GameCharacter,
    // or temporarily set 'name' public in GameCharacter for this test.
    // For now, we’ll assume name can be directly assigned.
    plant1->name = "🌱";
    zombie1->name = "🧟";
    plant2->name = "🌻";

    // Add them to the GameManager’s vector
    gm.getGameCharacters().push_back(plant1);
    gm.getGameCharacters().push_back(zombie1);
    gm.getGameCharacters().push_back(plant2);

    // Print the board
    gm.printBoard();

    // Cleanup dynamically allocated memory
    for (GameCharacter* gc : gm.getGameCharacters()) {
        delete gc;
    }

    return 0;
}
