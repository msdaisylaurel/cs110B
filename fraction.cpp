//  Course Name: CS110B Spring 2020
//  Lab Name: a9.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Class Invariant: a Fraction object has 2 int data members: numerator and denominator        which store their respective integers.  Fraction objects will always be stored in       lowest terms.  Internal operations always result in valid fractions.  The client is     prevented from providing an undefined fraction however, no effort is made to            prevent the client from providing a negative value fraction.
*/

#include <iostream>
#include <cassert>
#include "fraction.hpp"
using namespace std;



Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}




Fraction::Fraction(int num, int denom) {
    assert(denom != 0);
    numerator = num;
    denominator = denom;
    simplify();
}





/*  private function is used to store any fraction object in its lowest terms.  An initial conditional statement determines the largest integer in the fraction, either the numerator or the denominator.  A decrementing for-loop determines the Greatest Common Factor (GCF) of both the numerator and the denominator.  Finally, the numerator and denominator are assigned their lowest terms based on the GCF. */

void Fraction::simplify() {
    if (numerator <= denominator) {
        for (int i = (numerator); i > 0; i--) {
            if (numerator % i == 0 && denominator % i ==0) {
                numerator = numerator / i;
                denominator = denominator / i;
            }
        }
    } else {
        for (int i = (denominator); i > 0; i--) {
            if (numerator % i == 0 && denominator % i ==0) {
                numerator = numerator / i;
                denominator = denominator / i;
            }
        }
    }
}





Fraction Fraction::addedTo(const Fraction &secondFract) const {
    int addNum;
    int multDenom;
    if (denominator == secondFract.denominator) {
        addNum = numerator + secondFract.numerator;
        Fraction result(addNum, denominator);
        return result;
    } else {
        multDenom = denominator * secondFract.denominator;
        addNum = (numerator * secondFract.denominator) + (secondFract.numerator * denominator);
        Fraction result(addNum, multDenom);
        return result;
    }
}





Fraction Fraction::subtract(const Fraction &secondFract) const {
    int addNum;
    int multDenom;
    if (denominator == secondFract.denominator) {
        addNum = numerator - secondFract.numerator;
        Fraction result(addNum, denominator);
        return result;
    } else {
        multDenom = denominator * secondFract.denominator;
        addNum = (numerator * secondFract.denominator) - (secondFract.numerator * denominator);
        Fraction result(addNum, multDenom);
        return result;
    }
}





Fraction Fraction::multipliedBy(const Fraction &secondFract) const {
    int multNum;
    int multDenom;
    
    multNum = numerator * secondFract.numerator;
    multDenom = denominator * secondFract.denominator;
    Fraction result(multNum, multDenom);
    return result;
}





Fraction Fraction::dividedBy(const Fraction &secondFract) const {
    int multNum;
    int multDenom;
    
    multNum = numerator * secondFract.denominator;
    multDenom = denominator * secondFract.numerator;
    Fraction result(multNum, multDenom);
    return result;
}





bool Fraction::isEqualTo(const Fraction &secondFract) const {
    return ((numerator * secondFract.denominator) == (secondFract.numerator * denominator));
}




void Fraction::print() const {
    cout << numerator << "/" << denominator;
}


