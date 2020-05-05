//  Course Name: CS110B Spring 2020
//  Lab Name: a6.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Description:     This is a program that will allow you to manipulate a string as an array in a number of ways; namely, to obtain the last index of a character in the string, reverse the string, replace a character in the string with one of your choosing, check if the string is a palindrome, change the string to all uppercase letters, and count the number of letters in the string.  It runs on a loop so that you can either do any of these things over and over again to the same string array, or input a new string to manipulate.  */




//includes and namespaces
#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;



//function headers
int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);
int beginProgram();
char playAgain(char* inString, int userChoice);




//main function
int main () {
    
    
    //operating variables for looping program
    char *userString;
    int userChoice;
    char target;
    
    
    
    
    /* This initial post check loop is going to allow the user to enter in a string as an array that they will then be able to be manipulated; they can do this many times with new strings if they choose. */
    do {
        cout << "Give me a string: ";
        cin.getline(userString, 256);
        
        
        
                
        /* This interal post check loop will first enter a new function that asks the user how they would like to manipulate the string array they just entered and then passes that choice and the array into a switch case function for further processing.*/
        do {
            userChoice = beginProgram();
            target = playAgain(userString, userChoice);
        } while (target == 'y');
        
        
        
        //asks user if they would like to enter a new string/keep playing
        cout << "Would you prefer to start again with another string? (y/n): ";
        cin >> target;
        
        
        if (target == 'y') {
            cin.ignore(); // clears getline for new string input
        }
    } while (target == 'y');
    
    
    //end program
    cout << "Thanks for playing with me!" << endl;
    
    return 0;
}





/* This function will take the string array input by the user and uses a post check loop to traverse the array in reverse to find the last location of a character the user chooses.  */
int lastIndexOf(const char* inString, char target) {
    
    int i = (int)strlen(inString);
    
    //post check loop
    do {
        i--;
    } while (inString[i] != target && i != -1);
    
    //returns target character location or -1 if the character is not found in array
    if (i == -1 ) {
        return -1;
    } else {
        return i;
    }
}





/* This function will take the string array input by the user and reverses it using a post check loop and the swap function. */
void reverse(char* inString) {
    
    int i = (int)strlen(inString);
    
    //post check loop
    do {
        i--;
        swap(inString[i], inString[((int)strlen(inString) - 1) - i]); //swap
    } while (i >= ceil(((int)strlen(inString)/2)));
}





/* This function will take the string array input by the user and replaces any character with another character, both of which the user chooses.  It uses a for loop to traverse the entire array and ensure that all target characters get switched out.  Lastly, it returns the number of times a character was switched out. */
int replace(char* inString, char target, char replacementChar) {
    
    int count = 0;
    
    //for loop
    for (int i = 0; i < strlen(inString); i++) {
        
        if (inString[i] == target) {
            inString[i] = replacementChar;
            count++;
        }
    }
    return count;
}





/* This function will take the string array input by the user and checks if it is a palindrome.  It will return true if it is and false otherwise.*/
bool isPalindrome(const char* inString) {
    
    int i = 0;
    
    /* This pre-check loop traverses the string from both the beginning and the end and checks if the character in each location matches it's mirror location. */
    while (inString[i] == inString[((int)strlen(inString) - 1) - i]) i++;
    
    if (i == (int)strlen(inString) + 2) return true; //if string is palindrome
    
    return false;
}





/* This function will take the string array input by the user and changes every letter in the array to an uppercase.  It does not do anything to non-letter characters.*/
void toupper(char* inString) {
    
    int i = 0;
    
    //post check loop
    do {
        inString[i] = toupper(inString[i]);
        i++;
    } while (inString[i]);
}





/* This function will take the string array input by the user and counts the number of letters in the string.  It then returns that value. */
int numLetters(const char* inString) {
    
    int i = 0;
    int count = 0;
    
    //pre-check loop
    while (inString[i]) {
        
        if (isalpha(inString[i])) count++; //counts the letters
        i++;
    }
    return count;
}





/* This function will ask the user how they would like to manipulate the string array they've entered into the program's main function.  It will then pass the user's selection to a switch case function. */
int beginProgram () {
    
    int userChoice;
    
    cout << "How would you like to manipulate this string?" << endl;
    cout << "--------------------" << endl;
    cout << "1. Get the last index of a target character." << endl;
    cout << "2. Reverse the string." << endl;
    cout << "3. Replace a target character with another one." << endl;
    cout << "4. Check if the string is a palindrome." << endl;
    cout << "5. Change the string to all uppercase." << endl;
    cout << "6. Count the number of letters in the string." << endl;
    cout << "--------------------" << endl;
    cout << "Please pick one: ";
    cin >> userChoice;
    
    return userChoice;
}





/* This is a switch case function that will pass the string array into any one of the manipulator functions based on the user's choice.  This is kind of the 'master' function that directs the flow of the string array manipulation process.  At the end of each case, it will ask the user if it would like to try another manipulation process and then passes that answer back to the main function for further processing by eithe allowing the user to make another selection or allowing the user to exit the program. */
char playAgain(char* userString, int userChoice) {
    
    char target1;
    char target2;
    int result1;
    
    //switch
    switch (userChoice) {
            
        //last index of target character
        case 1:
            cout << "For which character would you like to get the last index in the string?: ";
            cin >> target1;
            userChoice = lastIndexOf(userString, target1);
            if (userChoice == -1) {
                cout << "That character is not in the string." << endl;
            } else {
                cout << "The last index of " << target1 << " in the string is the number " << userChoice << " location." << endl;
            }
            cout << "Would you like to try something else? (y/n): " << endl;
            cin >> target1;
            return target1;
        
        //reverse characters in string array
        case 2:
            reverse(userString);
            cout << "This is the string in reverse: " << userString << endl;
            cout << "Would you like to try something else? (y/n): " << endl;
            cin >> target1;
            return target1;
            
        //replace target character with another character
        case 3:
            cout << "Which character would you like to switch out?: ";
            cin >> target1;
            cout << "With which character would you like to replace it?: ";
            cin >> target2;
            result1 = replace(userString, target1, target2);
            if (result1 == 1) {
                cout << "There was " << result1 << " letter replaced." << endl;
            } else {
                cout << "There were " << result1 << " letters replaced." << endl;
            }
            cout << "This is the new string: " << userString << endl;
            cout << "Would you like to try something else? (y/n): " << endl;
            cin >> target1;
            return target1;
            
        //checks if the string is a palindrome
        case 4:
            if (!isPalindrome(userString)) {
                cout << "The string is not a palindrome." << endl;
            } else {
                cout << "The string is a palindrome." << endl;
            }
            cout << "Would you like to try something else? (y/n): " << endl;
            cin >> target1;
            return target1;
            
        //changes all of the characters in the string to uppercase
        case 5:
            toupper(userString);
            cout << "This is the string in all uppercase: " << userString << endl;
            cout << "Would you like to try something else? (y/n): " << endl;
            cin >> target1;
            return target1;
            
        //counts all of the letters in a string
        case 6:
            result1 = numLetters(userString);
            cout << "The number of letters in the string is " << result1 << "." << endl;
            cout << "Would you like to try something else? (y/n): " << endl;
            cin >> target1;
            return target1;
    }
    return 'n';
}
