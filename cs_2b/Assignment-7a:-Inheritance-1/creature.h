#ifndef CREATURE_H
#define CREATURE_H


#include <iostream>
#include <string>

using namespace std;

// namespace cs_mystring {

   class Creature
   { 
      private:
        int strength;           // how much damage this Creature inflicts
        int hitpoints;          // how much damage this Creature can sustain          
      public:
        Creature();
        Creature(int newStrength, int newHitpoints);

        int getDamage(); 
        string getSpecies();

        int getStrength();
        int getHitpoints();

        void setStrength(int strength_points);
        void setHitpoints(int hitpoints_points); 
   }; 



// }
#endif