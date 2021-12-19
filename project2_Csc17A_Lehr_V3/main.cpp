/*
    Author: Cody Pfrunder
    Date:   November 28, 2021
    Purpose:Project Two - Blackjack
            V3 A shuffle has been incorporated into the program for 52 cards.
            Now I want to deal the first two cards to each player using a Deck
            class that will run off of the Cards class. Dealing instantiated.         
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation
#include <ctime>       //ctime Library
using namespace std;   //Library Name-space

//User Libraries
#include "Deck.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int nCards = 52; //52 Cards in a deck
    Deck crdDeck(nCards);
   
    //Initialize variables
    const int PLAYERS = 4;
    
    //Process, map inputs to outputs
    crdDeck.shuffle();
    
    //Deal set of two cards
    int nDeal = 2;
    int *hand;
    
    //Display hand / first two cards to start off the game
    for(int i = 1; i <= PLAYERS; i++){
        hand = crdDeck.deal(nDeal);
        cout << endl << "Player " << i << ", your hand holds: \n";
        for(int j = 0; j < nDeal; j++){
            Cards card(hand[j]);
            cout << "(Card " << hand[j] << " of 52) " << card.crdFace() 
                 << card.crdSuit() << " " << setw(2) 
                 << static_cast<int>(card.crdVal()) << endl;
        }       
        delete [] hand;
    }
    //Exit stage right
    return 0;
}