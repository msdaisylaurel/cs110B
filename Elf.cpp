//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Class Invariant:
*/

#include "Elf.h"
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;

namespace cs_creature {


Elf::Elf()

: Creature() {
    //setStrength(10);
    //setHitpoints(10);
}



Elf::Elf(const int &newStrength, const int &newHitpoints)

: Creature(newStrength, newHitpoints) {
    //setStrength(newStrength);
    //setHitpoints(newHitpoints);
}



int Elf::getDamage() const {
    int damage;
    
    damage = Creature::getDamage();
    
    //cout << "The Elf attacks for " << damage << " points!" << endl;
    if ((rand() % 2) == 0) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        damage *= 2;
    }
    return damage;
}



string Elf::getSpecies() const {
    return "Elf";
}
    
};
