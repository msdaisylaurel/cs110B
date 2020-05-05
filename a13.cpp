//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Description:
*/

#include <iostream>
#include <string>
#include "creature.h"
#include "Demon.h"
#include "Human.h"
#include "Elf.h"
#include "Cyberdemon.h"
#include "Balrog.h"
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace cs_creature;

void battleArena(Creature& Creature1, Creature& Creature2);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    
    Elf e(50,50);
    Balrog b(50,50);

    battleArena(e,b);
}

void battleArena(Creature& Creature1, Creature& Creature2) {
    
    do {
        Creature1.setHitpoints((Creature1.getHitpoints() - Creature2.getDamage()));
        Creature2.setHitpoints((Creature2.getHitpoints() - Creature1.getDamage()));
        
    } while (Creature1.getHitpoints() > 0 && Creature2.getHitpoints() > 0);
    
    
    if (Creature1.getHitpoints() <= 0 && Creature2.getHitpoints() <= 0) {
        cout << "The battle is a tie!" <<endl ;
        
    } else if (Creature1.getHitpoints() <= 0) {
        cout << Creature2.getSpecies() << " wins!" << endl;
        
    } else {
        cout << Creature1.getSpecies() << " wins!" << endl;
    }
}



/*
 The Balrog attacks for 21 points!
 Balrog speed attack inflicts 10 additional damage points!
 The Elf attacks for 16 points!
 The Balrog attacks for 37 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 40 additional damage points!
 The Elf attacks for 37 points!
 Magical attack inflicts 37 additional damage points!
 The battle is a tie!
 Program ended with exit code: 0
 */
