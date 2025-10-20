#include "Projectile.h"

Projectile::Projectile(int row, int col){
    position.row = row;
    position.col = col;
    damage = 100;
    name = "* ";
}

int Projectile::getDamage() { return damage; }

Projectile::~Projectile(){};

void Projectile::move(){
    position.col = position.col+1;
}