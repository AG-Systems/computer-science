#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "demon.h"
#include <string>

using namespace std;

class Cyberdemon : public Demon {
    public:
        Cyberdemon();
        Cyberdemon(string s);   

        int getDamage() const;     
        string getSpecies() const;

};



#endif