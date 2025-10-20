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

void GameCharacter::takeDamage(int dmg) {
  health = health - dmg;
  if (health < 0) {
    health = 0;
  }
}

Coordinate GameCharacter::getPosition() { return position; }

string GameCharacter::getName() { return name; }

void GameCharacter::setName(string name) { this->name = name; }

string GameCharacter::getType() { return type; }

vector<Projectile*>& GameCharacter::getProjectiles() {
  static vector<Projectile*> empty;
  return empty;
};