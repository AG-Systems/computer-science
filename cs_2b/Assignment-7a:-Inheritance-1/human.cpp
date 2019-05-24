#include "human.h"
#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

string Human::getSpecies() const {
    return "Human";
}

int Human::getDamage() {
    int base_damage = Creature::getDamage();
    cout << getSpecies() << " attacks for " << base_damage << " points!" << endl;
    return base_damage;
}