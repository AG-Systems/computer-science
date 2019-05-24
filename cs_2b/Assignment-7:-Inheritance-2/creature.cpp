#include "creature.h"
#include <cstdlib>
#include <ctime>


string Creature::getSpecies() const{
    return "Creature";
}

int Creature::getDamage(){
    int damage;
    damage = (rand() % strength) + 1; 
    cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;  
    return damage;    
}

void Creature::setStrength(int strength_points) {
    strength = strength_points;
}

void Creature::setHitpoints(int hitpoints_points) {
    hitpoints = hitpoints_points;
}

int Creature::getStrength() {
    return strength;
}

int Creature::getHitpoints() {
    return hitpoints;
}