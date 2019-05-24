#ifndef DEMON_H
#define DEMON_H

#include "creature.h"
#include <string>

#include <cstdlib>
#include <ctime>

using namespace std;

class Demon : public Creature {
    public:
        Demon()
        {
            Creature::setStrength(10);
            Creature::setHitpoints(10); 
        };

        Demon(int new_strength, int new_hitpoints)
        {
            Creature::setStrength(new_strength);
            Creature::setHitpoints(new_hitpoints);  
        };  

        int getDamage();     
        string getSpecies() const;
        
         

};



#endif