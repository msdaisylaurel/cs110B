//  Course Name: CS110B Spring 2020
//  Lab Name: a7.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Description:  This is a program that accepts a list of player names and their scores and then saves them in a struct called playerList.  It uses one function to accept the information and store it, and then another function to sort the player's by score with the highest score being 1st place.  The final function displays the players' names, scores, and their placing from highest score to lowest.     */




//includes and namespaces
#include <iostream>
#include <istream>
using namespace std;



//restricts the size of the players' names to 23 characters
const int ARRAY_SIZE = 24;



//a structure used to store players' names and scores
struct Highscore {
    int score;
    char* name = new char[ARRAY_SIZE];
};



//function headers
void readData(Highscore scores[], int size);
void sortData(Highscore scores[], int size);
void displayData(const Highscore scores[], int size);




//main function
int main () {
    
    //variable to store how many players will be recorded
    int totalEntries;
    
    
    //asks for the number of players to be recorded
    cout << "How many players will you enter?: ";
    cin >> totalEntries;
        
    
    //struct to store players' names and scores
    Highscore playerList[totalEntries];
        
        
    
        /*
         These three functions first (1) read each of the players' names and their scores as entered by the user and then (2) sorts them from highest to lowest score and finally (3) displays the result from highest to lowest score.
         */
        readData(playerList, totalEntries);
        sortData(playerList, totalEntries);
        displayData(playerList, totalEntries);
        
        
        //end main
        return 0;
}





/*
 This is a function that accepts user entries for player names and scores and then stores them into a struct.
 */
void readData(Highscore scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for player #" << i + 1 << ": ";
        cin >> scores[i].name;
        cout << "Enter the score for player #" << i + 1 << ": ";
        cin >> scores[i].score;
    }
}





/*
 This function uses a nested loop to sort through each of the score elements in the playerList struct. If a score that is being checked against the other scores is less than those scores, it will eventually be the last score in the struct and the first score in the struct will be the highest score.
 */
void sortData(Highscore scores[], int size) {
    
    
    //nested loop structure checks all scores against each other
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            
            
            //conditional statements sorts score struct elements using swap function
            if (scores[i].score > scores[j].score) {
                swap(scores[i], scores[j]);
            }
        }
    }
}





/*
 Once the struct has been sorted, then this final function will display the result of the players and their scores as a list in descending order of highest to lowest scores.
 */
void displayData(const Highscore scores[], int size) {
    cout << "||Top Scorers||" << endl;
    
    //conditional statement to for accurate ordinal numbers
    for (int i = 0; i < size; i++) {
        if (i != 10 && i % 10 == 0) {
            cout << i + 1 << "st place: " << scores[i].name << " (" << scores[i].score << ")" << endl;
        } else if (i != 11 && i % 10 == 1) {
            cout << i + 1 << "nd place: " << scores[i].name << " (" << scores[i].score << ")" << endl;
        } else if (i != 12 && i % 10 == 2) {
            cout << i + 1 << "rd place: " << scores[i].name << " (" << scores[i].score << ")" << endl;
        } else {
            cout << i + 1 << "th place: " << scores[i].name << " (" << scores[i].score << ")" << endl;
        }
    }
}

