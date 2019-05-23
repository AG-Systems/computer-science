#ifndef ELF_H
#define ELF_H

#include "creature.h"
#include <string>

using namespace std;

class Elf : public Creature {
    public:
        Elf();
        Elf(string s);   

        int getDamage() const;     
        string getSpecies() const;
        
         

};



#endif