#ifndef DEMON_H
#define DEMON_H

#include "creature.h"
#include <string>

using namespace std;

class Demon : public Creature {
    public:
        Demon();
        Demon(string s);   

        int getDamage() const;     
        string getSpecies() const;
        
         

};



#endif