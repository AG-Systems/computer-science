#include "balrog.h"
#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

string Balrog::getSpecies() const {
    return "Balrog";
}

int Balrog::getDamage(){
    int base_damage = Demon::getDamage();
    cout << getSpecies() << " attacks for " << base_damage << " points!" << endl;
     if (rand() % 4 == 0) {
        base_damage = base_damage + 50;
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
    }     
    int damage2 = (rand() % Creature::getStrength()) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    base_damage += damage2;

    return base_damage;
}