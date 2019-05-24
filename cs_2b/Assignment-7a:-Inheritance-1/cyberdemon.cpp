#include "cyberdemon.h"
#include "creature.h"
#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

string Cyberdemon::getSpecies() const {
    return "Cyberdemon";
}

int Cyberdemon::getDamage(){
    int base_damage = Demon::getDamage();
    cout << getSpecies() << " attacks for " << base_damage << " points!" << endl;
    if (rand() % 4 == 0) {
        base_damage = base_damage + 50;
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
    }        
    int strength = Creature::getStrength();
    int damage2 = (rand() % strength) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    base_damage += damage2;
    
    return base_damage;
}