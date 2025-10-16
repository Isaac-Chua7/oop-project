#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

#include "Coordinate.h"
#include <GameCharacter.h>
#include "Attacker.h"
#include "Attacker1.h"
#include "Attacker2.h"
#include "Attacker3.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Coordinate c;
    c.setRow(2);
    c.setCol(3);
    assert(c.getRow() == 2);
    assert(c.getCol() == 3);
    std::cout << "Coordinate is great: (" << c.getRow() << "," << c.getCol() << ")" << std::endl;

    GameCharacter g(1, 1, 50);
    assert(g.getHealth() == 50);
    g.takeDamage(10);
    assert(g.getHealth() == 40);
    std::cout << "GameCharacter is great: health = " << g.getHealth() << std::endl;

    Attacker a(5, 10, 100, 2, 12);
    auto p = a.getPosition();
    std::cout << "Attacker at row " << p.row << " col " << p.col << std::endl;
    assert(p.col == 9);
    a.move(-1);
    std::cout << "Attacker moved to col " << a.getPosition().col << std::endl;

    a.takeDamage(30);
    std::cout << "Attacker health after damage: " << a.getHealth() << std::endl;
    assert(a.getHealth() == 70);

    Attacker1 a1(2, 9, 80, 3, 8);
    a1.update();
    assert(a1.getHealth() == 80);

    Attacker2 a2(0, 9, 60, 2, 10, 5);
    int taken = a2.reduceDamage(12);
    assert(taken == 7);
    assert(a2.getHealth() == 53);
    a2.update();

    Attacker3 a3(1, 9, 20, 2, 6, 15, 3);
    a3.update();
    std::cout << "Alright." << std::endl;
    
    return 0;
}