//  Course Name: CS110B Spring 2020
//  Lab Name: a1.1
//  Student Name: Daisy L Whitfield
//  Student ID: W
/*  Description: This program asks the user to enter a date as (month/day/2-digit-year) and if the month multiplied by the day is equal to the year then it prints out that the date is a magic date, otherwise it prints that it is not a magic date.*/

#include <iostream>
using namespace std;

int main() {
    
    
    //declaring variables
    
    int userInputMonth;
    int userInputDay;
    int userInputYear;
    
    
    //asks the user to input a date
    
    cout << "Enter a date in the format month/day/2-digit-year: ";
    cin >> userInputMonth;
    cin.ignore(1);
    cin >> userInputDay;
    cin.ignore(1);
    cin >> userInputYear;
        
        
    /*  A conditional statement checks if the month multiplied by the day is equal to the year.  If the condition is met, it prints out that a magic date was entered.  Otherwise, it prints out that a magic date was not entered. */
        
    if (userInputMonth * userInputDay == userInputYear) {
        cout << "That is a magic date!" << endl;
    } else {
        cout << "That is not a magic date." << endl;
    }
    
    return 0; // exits program
}

/*  output:
           Enter a date in the format month/day/2-digit-year: 1/1/1
           That is a magic date!
           Program ended with exit code: 0
 */
