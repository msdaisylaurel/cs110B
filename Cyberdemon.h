//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*
 The MyString class can be used to create and manipulate c-string objects implemented as dynamic character arrays.
 
   The following functions are available:
 
    
 */

#ifndef Cyberdemon_h
#define Cyberdemon_h

#include <cstdio>
#include <string>
#include "Demon.h"
using namespace std;

namespace cs_creature {
    class Cyberdemon: public Demon {
        public:
            Cyberdemon();             // initialize to 10 strength, 10 hitpoints
            Cyberdemon(const int &newStrength, const int &newHitpoints);
        
            string getSpecies() const;    // returns the type of the species
    };
}

#endif /* Cyberdemon_h */
