#ifndef BALROG_H
#define BALROG_H

#include "demon.h"
#include <string>

using namespace std;

class Balrog : public Demon {
    public:
        Balrog();
        Balrog(string s);   

        int getDamage() const;     
        string getSpecies() const;

};



#endif