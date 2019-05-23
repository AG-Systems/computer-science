#include "creature.h"


string Creature::getSpecies(){
    return "Creature";
}

int Creature::getDamage(){
    int damage;
    damage = (rand() % strength) + 1;   
    return damage;    
}

void Creature::setStrength(int strength_points){
    strength = strength_points;
}

void Creature::setHitpoints(int hitpoints_points){
    hitpoints = hitpoints_points;
}

int Creature::getStrength(){
    return strength;
}

int Creature::getHitpoints() {
    return hitpoints;
}