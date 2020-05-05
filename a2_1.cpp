//  Course Name: CS110B Spring 2020
//  Lab Name: a2.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682
/*  Description: This is a game that is similar to blackjack in that it will deal you two initial cards as your "hand" and confirm the total value of your hand to you based on the value of the two random cards.  It will then ask you if you wish to be dealt another card and based on your response will either end the game and ask if you wish to play again or it will deal you another card.  It will re-compute your hand total based on the new value of the card and if you are over the maximum value of 21, it will end the round stating "bust" and ask if you wish to play again or it will deal you another card.  The game will continue until you either get over 21 and bust, or you win and it congratulates you, or you choose not to take another card.  At the end of each round it asks if you would like to play again. */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main() {
    
    
    srand(static_cast<unsigned>(time(nullptr))); //randomizes cards based on timestamp
    
    
    char playerDecision; // loop control

    
    cout << "Welcome to a simple version of blackjack." << endl; //game introduction
    
    
    
    /*This is a post-check loop that will ensure the game continues until such time as the user chooses to end the game.*/
    
    do {
        
        //declarations and initialisations
        int firstCard = (rand() % 10) + 1;
        int nextCard = (rand() % 10) + 1;
        int handTotal = firstCard + nextCard;
        
        /*This group of I/O statements tells the player their initial hand, the total value of the hand, and asks them if they would like to be dealt a new card.*/
        
        cout << "First cards: " << firstCard << ", " << nextCard << endl;
        cout << "Total: " << handTotal << endl;
        cout << "Do you want another card? (y/n): ";
        cin >> playerDecision;
    
        
        
        /*If the player chooses to get another card, then this loop runs to give them another card.*/
        
        while (playerDecision == 'y') {
            
            
            //generating new card, adding it to hand's total, and letting the player know
            
            nextCard = (rand() % 10) + 1;
            handTotal += nextCard;
            cout << "New Card: " << nextCard << endl;
            
            
            
            
        /*This conditional statement lets the player know if they had gone over the maximum value of 21 and prints "bust" OR lets them know they hit 21 and congratulates them OR asks them if they want to take another card for their hand.*/
            
            if (handTotal > 21) {
                cout << "Hand Total: " << handTotal << endl;
                cout << "Bust." << endl;
                playerDecision = 'n';
            } else if (handTotal == 21) {
                cout << "Hand Total: " << handTotal << endl;
                cout << "Congratulations!" << endl;
                playerDecision = 'n';
            } else {
                cout << "Hand Total: " << handTotal << endl;
                cout << "Do you want another card? (y/n): ";
                cin >> playerDecision;
            }
        }
        
        
        
        
        /*Once the player has completely stopped choosing to take a card, has won the game, or has gone bust, this will ask them if they want to play again.*/
        
        cout << "Do you want to play again? (y/n): ";
        cin >> playerDecision;
    } while (playerDecision == 'y'); //post check
    
    return 0;
}




/*
 Welcome to a simple version of blackjack.
 First cards: 6, 7
 Total: 13
 Do you want another card? (y/n): y
 New Card: 5
 Hand Total: 18
 Do you want another card? (y/n): y
 New Card: 6
 Hand Total: 24
 Bust.
 Do you want to play again? (y/n): y
 First cards: 7, 4
 Total: 11
 Do you want another card? (y/n): y
 New Card: 6
 Hand Total: 17
 Do you want another card? (y/n): y
 New Card: 5
 Hand Total: 22
 Bust.
 Do you want to play again? (y/n): y
 First cards: 6, 8
 Total: 14
 Do you want another card? (y/n): y
 New Card: 7
 Hand Total: 21
 Congratulations!
 Do you want to play again? (y/n): y
 First cards: 6, 7
 Total: 13
 Do you want another card? (y/n): y
 New Card: 7
 Hand Total: 20
 Do you want another card? (y/n): n
 Do you want to play again? (y/n): n
 Program ended with exit code: 0
 */
