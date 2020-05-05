//  Course Name: CS110B Spring 2020
//  Lab Name: a4.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Description:   This is a program that will tell a player if the cards they have in their hand amount to a complete "poker hand" (eg. straight, flush, pair, two pair, etc.) that consists of a set of five cards with the values between 2 and 9 provided by the player.  It uses a "waterfall" system of logic gates to only provide the highest hand value for the combined cards input by the player.  */



//includes and namespaces
#include <iostream>
using namespace std;



//function declarations
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);
int duplicateCardCheck(const int hand[]);
int reLoopDupeCardCheck(const int hand[], int j);
int aStraightCheck(const int hand[]);
int reLoopStraightCheck(const int hand[], int j);



//global constant for the player's total cards in hand
int const ARRAY_SIZE = 5;



//begin main function
int main() {
    
    //create array for player's hand
    int playerHand[ARRAY_SIZE];
    
    //asks the player for the card values in their hand
    cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;
    
    
    //loop to iterate through array for player's hand of cards
    for (int i = 0;i < ARRAY_SIZE;i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> playerHand[i];
    }
    
    
    
    
    
    /* This is a waterfall logic gate that ensures only the highest hand value will be output by the program based on the individual card values in the player's hand.  The check for a straight (5 consecutive card values) happens at the end because logically, there is no way for a straight to exist if the player has any of the other hands as each of the other hands requires the player to have at least two cards with the same value.  If the player has none of these, then the only hand they could have higher than a high card hand is a straight.*/
    if (containsFourOfaKind(playerHand)) {
        cout << "contains a four of a kind!" << endl;
    } else if (containsFullHouse(playerHand)) {
       cout << "contains a full house!" << endl;
    } else if (containsThreeOfaKind(playerHand)) {
        cout << "contains a three of a kind!" << endl;
    } else if (containsTwoPair(playerHand)) {
        cout << "contains two pair!" << endl;
    } else if (containsPair(playerHand)) {
        cout << "contains a pair!" << endl;
    } else if (containsStraight(playerHand)) {
       cout << "contains a straight!" << endl;
    } else {
        cout << "contains a high card!" << endl;
    }
    return 0;  //end main
}






/* This is the first iteration for cards being checked to see if there are any duplicates - it iterates through each card number and passes that value to a second interative function.  It returns the total number of card checks where a duplicate was found.*/
int duplicateCardCheck(const int hand[]) {
    int count = 0;
    for (int i = 0;i < ARRAY_SIZE; i++) {
        count += reLoopDupeCardCheck(hand, i);
    }
    return count;
}





/* This is the second part of the duplicate card check. It iterates through the cards in the player's hand checking each cards' value against the value of the other cards and if a duplicate is found, it adds it to the total number of duplicates found and returns the total back to the first duplicate card check.  Quite practically, this function exists solely to circumvent the implementation of a nested loop structure.  */
int reLoopDupeCardCheck(const int hand[], int j) {
    int count = 0;
    for (int i = j + 1; i < ARRAY_SIZE; i++) {
        if (hand[i] == hand[j]) {
            count++;
        }
    }
    return count;
}





/* This is a first iteration to check a player's hand for a straight - it is only called if there are no duplicate cards found in the hand from the previous functions calls. it will iterate through each card and pass it on to the second iteration that checks the cards' values against the values of the other cards.*/
int aStraightCheck(const int hand[]) {
    int count = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        count += reLoopStraightCheck(hand, i);
    }
    return count;
}




/* This second loop will check each cards' value against the other cards.  It will check and see if the values of the cards are exactly one digit apart from each other and if so, it will add to the total number of times this happens.  If the total count is equal to 4, it confirms that a straight exists in the hand.  This function exists solely to circumvent a nested loop structure in the previous function.*/
int reLoopStraightCheck(const int hand[], int j) {
    int count = 0;
    for (int i = j + 1; i < ARRAY_SIZE; i++) {
        if (hand[j] + 1 == hand[i]) {
            count++;
        } else if (hand[j] - 1 == hand[i]) {
            count ++;
        } else {
            count = count;
        }
    }
    return count;
}



//this function returns true if there is a pair of cards in the hand
bool containsPair(const int hand[]) {
    return (duplicateCardCheck(hand) == 1);
}



//this function returns true if there is two pairs of cards in the hand
bool containsTwoPair(const int hand[]) {
    return (duplicateCardCheck(hand) == 2);
}



//this function returns true if there is a three of a kind in the hand
bool containsThreeOfaKind(const int hand[]) {
    return (duplicateCardCheck(hand) == 3);
}




//this function returns true if there is a straight in the hand
bool containsStraight(const int hand[]) {
    return (aStraightCheck(hand) == 4);
}




//this function returns true if there is a full house in the hand
bool containsFullHouse(const int hand[]) {
    return (duplicateCardCheck(hand) == 4);
}




//this function returns true if there is a four of a kind in the hand
bool containsFourOfaKind(const int hand[]) {
    return (duplicateCardCheck(hand) == 6);
}
