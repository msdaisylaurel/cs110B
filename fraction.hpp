//  Course Name: CS110B Spring 2020
//  Lab Name: a9.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*
   
   The Fraction class can be used to create objects that store a fraction as two separate integers, the numerator and the denominator.
 
   The following functions are available:
   
   Fraction();
     post: The calling object has been created and initialized to 0/1.
   
   Fraction(int num, int denom);
     post: The calling object has been created and initialized so that the numerator is num, the denominator is denom, and it these integer values are stored in the simplest terms, dividing them by their Greatest Common Factor (GCF).
   
   Fraction addedTo(const Fraction &secondFract) const;
     post: The calling object has been added to the parameter "secondFract" and the sum is returned as a new Fraction object.
   
   Fraction subtract(const Fraction &secondFract) const;
     post: The calling object is subtracted from by the parameter "secondFract" and the difference is returned as a new Fraction object.
   
   Fraction multipliedBy(const Fraction &secondFract) const;
     post: The calling object is multiplied by the parameter "secondFract" and the product is returned as a new Fraction object.
 
   Fraction dividedBy(const Fraction &secondFract) const;
     post: The calling object is divided by the parameter "secondFract" by multiplying the calling object by the parameter's reciprocal and returning the quotient as a new Fraction object.
   
   bool isEqualTo(const Fraction &secondFract) const;
     post: Returns true if the calling object is equal to the parameter "secondFract" by using cross multiplication.
              
   void print() const;
     post: The calling object is printed to the console as a fraction.
            
   */ 

#ifndef fraction_hpp
#define fraction_hpp

#include <stdio.h>


class Fraction {
public:
    Fraction();
    Fraction(int num, int denom);
    Fraction addedTo(const Fraction &secondFract) const;
    Fraction subtract(const Fraction &secondFract) const;
    Fraction multipliedBy(const Fraction &secondFract) const;
    Fraction dividedBy(const Fraction &secondFract) const;
    bool isEqualTo(const Fraction &secondFract) const;
    void print() const;
private:
    void simplify();
    int numerator;
    int denominator;
};

#endif /* fraction_hpp */


/*
 The result starts off at 0/1
 The product of 9/8 and 2/3 is 3/4
 The quotient of 9/8 and 2/3 is 27/16
 The sum of 9/8 and 2/3 is 43/24
 The difference of 9/8 and 2/3 is 11/24
 The two Fractions are not equal.
 The product of 3/2 and 2/3 is 1/1
 Program ended with exit code: 0
 */
