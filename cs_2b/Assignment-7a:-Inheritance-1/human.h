#ifndef HUMAN_H
#define HUMAN_H

#include "creature.h"
#include <string>

using namespace std;

class Human : public Creature {
    public:
        Human();
        Human(string s);   

        int getDamage() const;     
        string getSpecies() const;

};



#endif