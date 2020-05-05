//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Class Invariant: 
*/

#include "Balrog.h"
#include <iostream>
#include <string>
#include "Demon.h"
using namespace std;

namespace cs_creature {


Balrog::Balrog()

: Demon() {
    //setStrength(80);
    //setHitpoints(90);
}



Balrog::Balrog(const int &newStrength, const int &newHitpoints)

: Demon(newStrength, newHitpoints) {
    //setStrength(newStrength);
    //setHitpoints(newHitpoints);
}



int Balrog::getDamage() const {
    
    //cout << "The Balrog ";
    int damage;
    int damage2;
    
    damage = Demon::getDamage();
    damage2 = (rand() % Creature::getStrength()) + 1;
    
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    
    return damage += damage2;
}



string Balrog::getSpecies() const {
    return "Balrog";
}
    
};

