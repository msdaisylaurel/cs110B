//  Course Name: CS110B Spring 2020
//  Lab Name: a8.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Description:   N/A   */


#include <iostream>
using namespace std;

class Fraction {
public:
    void set(int num, int denom);
    Fraction addedTo(Fraction secondFract);
    Fraction subtract(Fraction secondFract);
    Fraction multipliedBy(Fraction secondFract);
    Fraction dividedBy(Fraction secondFract);
    bool isEqualTo(Fraction secondFract);
    void print();
private:
    int numerator;
    int denominator;
};




int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}



void Fraction::set(int num, int denom) {
    numerator = num;
    denominator = denom;
}



Fraction Fraction::addedTo(Fraction secondFract) {
    int addNum;
    int multDenom;
    Fraction result;
    if (denominator == secondFract.denominator) {
        addNum = numerator + secondFract.numerator;
        result.set(addNum, denominator);
        return result;
    } else {
        multDenom = denominator * secondFract.denominator;
        addNum = (numerator * secondFract.denominator) + (secondFract.numerator * denominator);
        result.set(addNum, multDenom);
        return result;
    }
}



Fraction Fraction::subtract(Fraction secondFract) {
    int addNum;
    int multDenom;
    Fraction result;
    if (denominator == secondFract.denominator) {
        addNum = numerator - secondFract.numerator;
        result.set(addNum, denominator);
        return result;
    } else {
        multDenom = denominator * secondFract.denominator;
        addNum = (numerator * secondFract.denominator) - (secondFract.numerator * denominator);
        result.set(addNum, multDenom);
        return result;
    }
}



Fraction Fraction::multipliedBy(Fraction secondFract) {
    int multNum;
    int multDenom;
    Fraction result;
    
    multNum = numerator * secondFract.numerator;
    multDenom = denominator * secondFract.denominator;
    result.set(multNum, multDenom);
    return result;
}



Fraction Fraction::dividedBy(Fraction secondFract) {
    int multNum;
    int multDenom;
    Fraction result;
    
    multNum = numerator * secondFract.denominator;
    multDenom = denominator * secondFract.numerator;
    result.set(multNum, multDenom);
    return result;
}
bool Fraction::isEqualTo(Fraction secondFract) {
    return ((numerator * secondFract.denominator) == (secondFract.numerator * denominator));
}

void Fraction::print() {
    cout << numerator << "/" << denominator;
}


/*
 The product of 9/8 and 2/3 is 18/24
 The quotient of 9/8 and 2/3 is 27/16
 The sum of 9/8 and 2/3 is 43/24
 The difference of 9/8 and 2/3 is 11/24
 The two Fractions are not equal.
 Program ended with exit code: 0
 */
