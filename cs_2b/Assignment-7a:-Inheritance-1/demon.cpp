#include "demon.h"


string Demon::getSpecies() const {
    return "Demon";
}

int Demon::getDamage() const {
    int base_damage = Creature::getDamage();
    cout << getSpecies() << " attacks for " << base_damage << " points!" << endl;
    if (rand() % 4 == 0) {
        base_damage = base_damage + 50;
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
    }    
    return base_damage;    
}