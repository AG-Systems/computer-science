#ifndef HUMAN_H
#define HUMAN_H

#include "creature.h"
#include <string>

using namespace std;

class Human : public Creature {
    public:
        Human()
        {
            Creature::setStrength(10);
            Creature::setHitpoints(10);  
        };

        Human(int new_strength, int new_hitpoints)
        {
            Creature::setStrength(new_strength);
            Creature::setHitpoints(new_hitpoints);  
        };   

        int getDamage();     
        string getSpecies() const;

};



#endif