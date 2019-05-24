#include "demon.h"
#include <cstdlib>
#include <ctime>

string Demon::getSpecies() const {
    return "Demon";
}

int Demon::getDamage(){
    int base_damage = Creature::getDamage();
    return base_damage;    
}