//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Class Invariant:
*/

#include "Human.h"
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;

namespace cs_creature {


Human::Human()

: Creature() {
    //setStrength(10);
   // setHitpoints(10);
}



Human::Human(const int &newStrength, const int &newHitpoints)

: Creature(newStrength, newHitpoints) {
    //setStrength(newStrength);
    //setHitpoints(newHitpoints);
}



string Human::getSpecies() const {
    return "Human";
}
    
};
