#ifndef BALROG_H
#define BALROG_H

#include "demon.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Balrog : public Demon {
    public:
        Balrog()
        {
            Creature::setStrength(10);
            Creature::setHitpoints(10); 
        };

        Balrog(int new_strength, int new_hitpoints)
        {
            Creature::setStrength(new_strength);
            Creature::setHitpoints(new_hitpoints);  
        }; 

        int getDamage();     
        string getSpecies() const;

};



#endif