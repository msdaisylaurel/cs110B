//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*
 The MyString class can be used to create and manipulate c-string objects implemented as dynamic character arrays.
 
   The following functions are available:
 
    
 */

#ifndef Human_h
#define Human_h

#include <cstdio>
#include <string>
#include "creature.h"
using namespace std;

namespace cs_creature {
    class Human: public Creature {
        public:
            Human();             // initialize to 10 strength, 10 hitpoints
            Human(const int &newStrength, const int &newHitpoints);
        
            string getSpecies() const;    // returns the type of the species
    };
}

#endif /* Human_h */
