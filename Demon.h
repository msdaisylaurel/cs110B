//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*
 The MyString class can be used to create and manipulate c-string objects implemented as dynamic character arrays.
 
   The following functions are available:
 
    
 */

#ifndef Demon_h
#define Demon_h

#include <cstdio>
#include <string>
#include "creature.h"
using namespace std;

namespace cs_creature {
    class Demon: public Creature {
        public:
            Demon();             // initialize to 10 strength, 10 hitpoints
            Demon(const int &newStrength, const int &newHitpoints);
        
            string getSpecies() const;    // returns the type of the species
            int getDamage() const;
        
        // also include appropriate accessors and mutators
    };
}


#endif /* Demon_h */
