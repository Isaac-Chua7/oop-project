#include <iostream>
#include "Attacker1.h"
#include "Attacker2.h"
#include "Attacker3.h"

int main() {
    // Generates a random no., calling to rand() in the Attacker constructor to generate different random rows each time
    srand(static_cast<unsigned>(time(nullptr)));
    
    /* shows one of each attacker type
    creates instances of each attacker subclass
    */
    Attacker1 a1; // basic attacker
    Attacker2 a2; // has armour to reduce damage
    Attacker3 a3; // provides a speed boost when low on health

    // Calls the update() for each attacker
    std::cout << "=== Initial Stats ===" << std::endl;
    // shows the stats for each attacker - helps visualise the starting stats before any actions
    a1.update(); 
    a2.update();
    a3.update();

    // Applies damage to each attacker using takeDamage()
    std::cout << std::endl
              << "=== Simulate Damage ===" << std::endl;
    // shows to reduce health for behaviour changes
    
    std::cout << "Attacker1 takes 2 damage" << std::endl;
    a1.takeDamage(2);
    a1.update();

    std::cout << "Attacker2 takes 3 damage" << std::endl;
    a2.takeDamage(3);
    a2.update();

    std::cout << "Attacker3 takes 4 damage" << std::endl;
    a3.takeDamage(4);
    a3.update();

    // each attacker moves by 1 col to the left, moving towards the player
    std::cout << std::endl
              << "=== Move Attackers ===" << std::endl;
    a1.move();
    a2.move();
    a3.move();

    // Prints the col positions for each attacker after moving
    std::cout << "Positions after moving:" << std::endl;
    std::cout << a1.getName() << " col = " << a1.getPosition().col << std::endl;
    std::cout << a2.getName() << " col = " << a2.getPosition().col << std::endl;
    std::cout << a3.getName() << " col = " << a3.getPosition().col << std::endl;

    return 0;
}