#include "elf.h"
#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

string Elf::getSpecies() const {
    return "Elf";
}

int Elf::getDamage(){
    int base_damage = Creature::getDamage();
    cout << getSpecies() << " attacks for " << base_damage << " points!" << endl;
    if ((rand() % 2) == 0) {
        cout << "Magical attack inflicts " << base_damage << " additional damage points!" << endl;
        base_damage *= 2;
    }
    return base_damage;
}