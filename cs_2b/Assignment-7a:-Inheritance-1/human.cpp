#include "human.h"
#include <iostream>
#include <string>

string Human::getSpecies() const {
    return "Human";
}

int Human::getDamage() const {
    int base_damage = Creature::getDamage();
    cout << getSpecies() << " attacks for " << base_damage << " points!" << endl;
    return base_damage;
}