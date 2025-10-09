#include "GameCharacter.h"

GameCharacter::GameCharacter() { health = 0; };

GameCharacter::GameCharacter(int hp) { health = hp; }

GameCharacter::~GameCharacter() {};

int GameCharacter::getHealth() { return health; };

void GameCharacter::setHealth(int health) { this->health = health; };

void GameCharacter::takeDamage(int dmg) { health = health - dmg; }

int Coordinate::getRow() { return row; };

int Coordinate::getCol() { return col; }

void Coordinate::setRow(int r) { row = r; };

void Coordinate::setCol(int c) { col = c;};