#include "balrog.h"
#include <iostream>
#include <string>

string Balrog::getSpecies() const {
    return "Balrog";
}

int Balrog::getDamage() const {
    int base_damage = Demon::getDamage();
    cout << getSpecies() << " attacks for " << base_damage << " points!" << endl;
    
    int damage2 = (rand() % strength) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    base_damage += damage2;

    return base_damage;
}