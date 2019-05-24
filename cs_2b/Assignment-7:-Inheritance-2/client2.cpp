#include <iostream>
#include <string>

#include "creature.h"
#include "human.h"
#include "cyberdemon.h"
#include "balrog.h"
#include "elf.h"
#include "demon.h"
#include <cstdlib>
#include <ctime>

void battleArena(Creature& Creature1, Creature& Creature2)
{
    if(Creature1.getHitpoints() > 0 && Creature2.getHitpoints() > 0)
    {
        Creature1.setHitpoints(Creature2.getHitpoints() - Creature1.getDamage());
        Creature2.setHitpoints(Creature1.getHitpoints() - Creature2.getDamage());
        return battleArena(Creature1, Creature2);
    } else {
        if(Creature1.getHitpoints() < 0)
        {
            std::cout << "Creature: " << Creature2.getSpecies() << "2 has won!" << std::endl;
        } else if(Creature2.getHitpoints() < 0) {
            std::cout << "Creature: " << Creature1.getSpecies() << "1 has won!" << std::endl;
        } else {
            std::cout << "Its a tie!" << std::endl;
        }
        return;
    }
}

int main()
{
	srand(static_cast<unsigned>(time(0)));

	Elf e(50,50);
	Balrog b(50,50);

	battleArena(e, b);	
}

/*
The Elf attacks for 3 points!
Magical attack inflicts 3 additional damage points!
The Balrog attacks for 6 points!
Balrog attacks for 6 points!
Balrog speed attack inflicts 7 additional damage points!
The Elf attacks for 42 points!
Magical attack inflicts 42 additional damage points!
The Balrog attacks for 5 points!
Balrog attacks for 5 points!
Balrog speed attack inflicts 31 additional damage points!
Creature: Balrog2 has won!
*/