//  Course Name: CS110B Spring 2020
//  Lab Name: a3.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Description: This is a game that uses bisection search to guess the number a player chooses, between 1 and 100.  It contains a main function that runs the game as a loop allowing the player to play the game as many times as they choose, and then three functions are used to operate the game.  The first function layer defines the variables for playing the game and contains a conditional statement inside of a do-while loop which are the game mechanics and allows the program to "guess" the player's number.  Within this function are two more that drive the logic of the game; one function asks the user if the program has guessed the number correctly and, if not, if the number is higher or lower than the guess.  Until the program guesses correctly, the last function uses the guess and the the lower or higher bound of the range to provide a new guess which becomes the lower or higher bound of the range for a new guessing round.  */



#include <iostream>
#include <cmath>
using namespace std;


//function headers
void playOneGame();
void getUserResponseToGuess(int, char&);
int getMidpoint(int, int);


// global constants for guessing range
int const LOWEST = 1;
int const HIGHEST = 100;



/*  The main function contains a loop that allows the user to choose to play the game at the onset and if they want to play, then runs the game in a loop until such time as they choose that they would no longer like to play the game.  */
int main() {
    
    char response;
    
    
    // asks the user if they want to play the game
    cout << "Ready to play (y/n)? ";
    cin >> response;
    
    
    //while loop allows the player to play the game as long as they answer 'y' for "yes"
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
    return 0;
}






/*  This function operates the game by first declaring the variables used to play the game, namely the program's guess and the lower and upper bounds of the range in which the guess is contained.  It has a post-check loop that contains a conditional statement which is used to reduce the range in which the guess is made by half after each preceding incorrect guess.  This is a type of guess-and-check method called bisection search.  */

void playOneGame () {
    
    char userHint;
    int lowValue;
    int highValue;
    int guess;
    
    
    //asks the player to pick a number in a predefined range
    cout << "Think of a number between " << LOWEST << " and " << HIGHEST << "." << endl;
    guess = getMidpoint(LOWEST, HIGHEST);
    lowValue = LOWEST;
    highValue = HIGHEST;
    
    
    
    /*  This do-while loop contains a conditional statement that will reduce the range in which the program's guess is made by half each time based on whether or not the number chosen by the player is lower or higher than the previous guess.  It stops when the number is guessed correctly.  */
    do {
        getUserResponseToGuess(guess, userHint);
        if (userHint == 'l') {
            highValue = guess;
            guess = getMidpoint(lowValue, highValue);
        } else {
            lowValue = guess;
            guess = getMidpoint(lowValue, highValue);
        }
    } while (userHint != 'c');
}






/*  This function lets the user know the program's guess and then asks the if the guess is higher than the number, lower than the number, or is correct.  It accepts the player's answer and then uses pass-by-reference to control the conditional statement in the playOneGame function.  */

void getUserResponseToGuess(int guess, char& result) {
    
    cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin >> result;
    }






/*  This is a function that is used to find the midpoint value for a bounded range that is created initially and after each guess by the program.  It returns the nearest whole number rounded down. */

int getMidpoint(int low, int high) {
    
    int answer;
    
    answer = floor((low + high)/2);
    
    return answer;
}


/*Ready to play (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 87. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 93. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 90. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 91. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 37. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 43. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 46. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 44. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 45. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
Great! Do you want to play again (y/n)? n
Program ended with exit code: 0
 */
