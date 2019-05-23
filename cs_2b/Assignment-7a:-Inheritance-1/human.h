#ifndef SALARIEDEMP_H
#define SALARIEDEMP_H

#include "creature.h"
#include <string>

using namespace std;

class Human : public Creature {
    public:
        string getSpecies() const; 
    protected:
        double salary;
};


string Human::getSpecies() const {
    return "Human";
}



#endif