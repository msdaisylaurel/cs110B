//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Class Invariant:
*/

#include "Cyberdemon.h"
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;

namespace cs_creature {


Cyberdemon::Cyberdemon()

: Demon() {
    //setStrength(10);
    //setHitpoints(10);
}



Cyberdemon::Cyberdemon(const int &newStrength, const int &newHitpoints)

: Demon(newStrength, newHitpoints) {
    //setStrength(newStrength);
    //setHitpoints(newHitpoints);
}



string Cyberdemon::getSpecies() const {
    return "Cyberdemon";
}
    
};
