#ifndef CREATURE_H
#define CREATURE_H


#include <iostream>
#include <string>

using namespace std;

// namespace cs_mystring {

   class Creature
   { 
      private:
        int type;               // 0 Human, 1 Cyberdemon, 2 Balrog, 3 elf
        int strength;           // how much damage this Creature inflicts
        int hitpoints;          // how much damage this Creature can sustain          
      public:
        Creature();             // initialize to Human, 10 strength, 10 hitpoints
        Creature(int newType, int newStrength, int newHitpoints);
        int getDamage() const;         // returns the amount of damage this Creature
                                 // inflicts in one round of combat
        
        // also include appropriate accessors and mutators   
   }; 


    int Creature::getDamage() const {
        int damage;
        
        // All Creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        
        // Demons can inflict damage of 50 with a 25% chance
        if (type == 2 || type == 1){
            if (rand() % 4 == 0) {
                damage = damage + 50;
                cout << "Demonic attack inflicts 50 additional damage points!" << endl;
            }
        }
        
        // Elves inflict double magical damage with a 50% chance
        if (type == 3) {
            if ((rand() % 2) == 0) {
                cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
                damage *= 2;
            }
        }
        
        // Balrogs are so fast they get to attack twice
        if (type == 2) {
            int damage2 = (rand() % strength) + 1;
            cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
            damage += damage2;
        }
        
        return damage;
    }


// }
#endif
