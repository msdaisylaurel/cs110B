//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Class Invariant:
*/

#include "Demon.h"
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;

namespace cs_creature {


Demon::Demon()

: Creature() {
    //setStrength(10);
    //setHitpoints(10);
}



Demon::Demon(const int &newStrength, const int &newHitpoints)

: Creature(newStrength, newHitpoints) {
    //setStrength(newStrength);
    //setHitpoints(newHitpoints);
}



int Demon::getDamage() const {
    int damage;
    
    damage = Creature::getDamage();
    
    //cout << "attacks for " << damage << " points!" << endl;
    
    if (rand() % 4 == 0) {
        damage = damage + 50;
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
    }
    
    return damage;
}



string Demon::getSpecies() const {
    return "Demon";
}
    
};
