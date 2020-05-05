//  Course Name: CS110B Spring 2020
//  Lab Name: a5.2
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Description:    This is a program that will use two dynamic arrays to store a series of strings and numbers which correspond to players and their scores from a game.  It will ask the user how many scores they will enter (in other words, how many players there are) and then it will arrange the players and their scores from highest to lowest and display the result. */


#include <iostream>

using namespace std;



//function headers
void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);



int main () {
    
    // holds value for array size
    int total_scores;
    
    cout << "How many scores will you enter?: ";
    cin >> total_scores;
    
    //create two new dynamic arrays, one for string names and one for integer scores
    string* playerNames = new string[total_scores];
    int* playerScores = new int[total_scores];
    
    
    /*
     This function block reads the players' names and their scores as entered by the user and then sorts them from highest to lowest score and finally displays the result from highest to lowest score.
     */
    readData(playerNames, playerScores, total_scores);
    sortData(playerNames, playerScores, total_scores);
    displayData(playerNames, playerScores, total_scores);
    
    
    //deallocating the arrays
    delete [] playerNames;
    delete [] playerScores;
    
    return 0;
    
}
/*
 This function prompts the user the enter the name of each player and their score, ending only when the user has entered in the max amount of the players as previously defined in the main function.  It will store the results into two dynamic arrays.
 */
void readData(string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for player #" << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter the score for player #" << i + 1 << ": ";
        cin >> scores[i];
    }
}
/*
 This function uses a nested loop to sort through each of the elements in the "scores" array which contains the value of the scores previously entered by the user.  If a score that is being checked against the other scores in the array is less than those scores, it will eventually be the last item in the array and the first item in the array will be the highest score.
 */
void sortData(string names[], int scores[], int size) {
    
    //nested loop structure checks all scores against each other
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            
            
            //conditional statements sorts name an score elements in array by swap function
            if (scores[i] > scores[j]) {
                swap(scores[i], scores[j]);
                swap(names[i], names[j]);
            }
        }
    }
}
/*
 Once the dynamic arrays have been sorted, then this final function will display the result of the players and their scores as a list in descending order of highest to lowest scores.
 */
void displayData(const string names[], const int scores[], int size) {
    cout << "||Top Scorers||" << endl;
    
    for (int i = 0; i < size; i++) {
        cout << names[i] << ": " << scores[i] << endl;
        
    }
}
