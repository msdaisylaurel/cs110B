//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*
 The MyString class can be used to create and manipulate c-string objects implemented as dynamic character arrays.
 
   The following functions are available:
 
    
 */

#ifndef Balrog_h
#define Balrog_h

#include <cstdio>
#include <string>
#include "Demon.h"
using namespace std;

namespace cs_creature {
    class Balrog: public Demon {
        public:
            Balrog();             // initialize to 10 strength, 10 hitpoints
            Balrog(const int &newStrength, const int &newHitpoints);
        
            string getSpecies() const;    // returns the type of the species
            int getDamage() const;     
        
        // also include appropriate accessors and mutators
    };
}
#endif /* Balrog_h */
