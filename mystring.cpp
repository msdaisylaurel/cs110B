//  Course Name: CS110B Spring 2020
//  Lab Name: a11.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Class Invariant:
*/

#include "mystring.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;


namespace cs_mystring {



    MyString::MyString() {
        inputString = new char[1];
        strcpy(inputString, "");
    }



    MyString::MyString(const char *stringInput) {
        inputString = new char[(strlen(stringInput) + 1)];
        strcpy(inputString, stringInput);
    }



    MyString::MyString(const MyString &right) {
        inputString = new char[(strlen(right.inputString) + 1)];
        strcpy(inputString, right.inputString);
    }



    MyString::~MyString() {
        delete [] inputString;
    }



    MyString MyString::operator=(const MyString &right) {
        if(this != &right) {
            delete [] inputString;
            inputString = new char[(strlen(right.inputString) + 1)];
            strcpy(inputString, right.inputString);
        }
        return *this;
    }



    bool operator<(const MyString &left, const MyString &right) {
        return (strcmp(left.inputString, right.inputString) < 0);
    }



    bool operator<=(const MyString &left, const MyString &right) {
        return (strcmp(left.inputString, right.inputString) <= 0);
    }



    bool operator>(const MyString &left, const MyString &right) {
        return (strcmp(left.inputString, right.inputString) > 0);
    }




    bool operator>=(const MyString &left, const MyString &right) {
        return (strcmp(left.inputString, right.inputString) >= 0);
    }



    bool operator==(const MyString &left, const MyString &right) {
        return (strcmp(left.inputString, right.inputString) == 0);
    }



    bool operator!=(const MyString &left, const MyString &right) {
        return (strcmp(left.inputString, right.inputString) != 0);
    }



    std::ostream& operator<<(std::ostream& out, const MyString &printTerm) {
        out << printTerm.inputString;
        return out;
    }



    char MyString::operator[](int j) const {
        assert(j >= 0 && j < strlen(inputString));
        return inputString[j];
    }



    char& MyString::operator[](int j) {
        assert(j >= 0 && j < strlen(inputString));
        return inputString[j];
    }
    


    int MyString::length() const {
        return (static_cast<int>(strlen(inputString)));
    }
}
