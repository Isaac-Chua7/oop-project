#include "GameCharacter.h"

GameCharacter::GameCharacter() {
  health = 0;
  position.row = 0;
  position.col = 0;
}

GameCharacter::GameCharacter(int r, int c, int hp) {
  health = hp;
  position.row = r;
  position.col = c;
}

GameCharacter::~GameCharacter() {};

int GameCharacter::getHealth() { return health; };

void GameCharacter::setHealth(int health) { this->health = health; };

void GameCharacter::takeDamage(int dmg) { health = health - dmg; }

int Coordinate::getRow() { return row; };

int Coordinate::getCol() { return col; }

void Coordinate::setRow(int r) { row = r; };

void Coordinate::setCol(int c) { col = c; };