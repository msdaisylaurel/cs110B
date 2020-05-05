//  Course Name: CS110B Spring 2020
//  Lab Name: a13
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*
 The MyString class can be used to create and manipulate c-string objects implemented as dynamic character arrays.
 
   The following functions are available:
 
    
 */

#ifndef creature_h
#define creature_h

#include <cstdio>
#include <string>
using namespace std;

namespace cs_creature {
    class Creature {
        private:
            int strength;           // how much damage this Creature inflicts
            int hitpoints;          // how much damage this Creature can sustain
        public:
            Creature();             // initialize to 10 strength, 10 hitpoints
            Creature(int newStrength, int newHitpoints);
        
            virtual string getSpecies() const = 0;    // returns the type of the species
            virtual int getDamage() const;         // returns the amount of damage this Creature
                                            // inflicts in one round of combat
            int getStrength() const;
            int getHitpoints() const;
        
            void setStrength(const int &newStrength);
            void setHitpoints(const int &newHitpoints);
        
        // also include appropriate accessors and mutators
    };
}


#endif /* creature_h */
