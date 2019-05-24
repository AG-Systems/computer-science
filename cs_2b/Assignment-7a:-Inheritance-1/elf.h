#ifndef ELF_H
#define ELF_H

#include "creature.h"
#include <string>

using namespace std;

class Elf : public Creature {
    public:
        Elf()
        {
            Creature::setStrength(10);
            Creature::setHitpoints(10);  
        };

        Elf(int new_strength, int new_hitpoints)
        {
            Creature::setStrength(new_strength);
            Creature::setHitpoints(new_hitpoints);  
        }; 

        int getDamage();     
        string getSpecies() const;
        
         

};



#endif