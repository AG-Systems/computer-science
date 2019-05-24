#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "demon.h"
#include <string>

#include <cstdlib>
#include <ctime>

using namespace std;

class Cyberdemon : public Demon {
    public:
        Cyberdemon()
        {
            Creature::setStrength(10);
            Creature::setHitpoints(10);   
        };

        Cyberdemon(int new_strength, int new_hitpoints)
        {
            Creature::setStrength(new_strength);
            Creature::setHitpoints(new_hitpoints);  
        }; 

        int getDamage();     
        string getSpecies() const;

};



#endif