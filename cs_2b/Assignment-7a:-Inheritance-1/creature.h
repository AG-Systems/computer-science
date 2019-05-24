#ifndef CREATURE_H
#define CREATURE_H


#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

using namespace std;

// namespace cs_mystring {

   class Creature
   { 
      private:
        int strength;           // how much damage this Creature inflicts
        int hitpoints;          // how much damage this Creature can sustain          
      public:
        Creature()
        {
            Creature::setStrength(10);
            Creature::setHitpoints(10); 
        };

        Creature(int new_strength, int new_hitpoints)
        {
            Creature::setStrength(new_strength);
            Creature::setHitpoints(new_hitpoints);  
        }; 

        int getDamage(); 
        string getSpecies();

        int getStrength();
        int getHitpoints();

        void setStrength(int strength_points);
        void setHitpoints(int hitpoints_points); 
   }; 



// }
#endif