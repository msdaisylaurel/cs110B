//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Class Invariant:
*/

#include "creature.h"
#include <string>
#include <iostream>
using namespace std;

namespace cs_creature {


Creature::Creature() {
    strength = 10;
    hitpoints = 10;
}



Creature::Creature(int newStrength, int newHitpoints) {
    strength = newStrength;
    hitpoints = newHitpoints;
}



int Creature::getDamage() const {
    int damage;
    
    // All Creatures inflict damage which is a random number up to their strength
    damage = (rand() % strength) + 1;
    
    cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
    
    return damage;
}



string Creature::getSpecies() const {
    return "Creature";
}



int Creature::getStrength() const {
    return strength;
}



int Creature::getHitpoints() const {
    return hitpoints;
}

void Creature::setStrength(const int &newStrength) {
    strength = newStrength;
}



void Creature::setHitpoints(const int &newHitpoints) {
    hitpoints = newHitpoints;
}
    
};
