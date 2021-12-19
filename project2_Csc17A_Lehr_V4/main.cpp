/*
    Author: Cody Pfrunder
    Date:   November 28, 2021
    Purpose:Project Two - Blackjack
            V4 Creating a hand class that passes in the hand obtained, 
            deconstructs it and gives a display. 
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation
#include <ctime>       //ctime Library
using namespace std;   //Library Name-space

//User Libraries
#include "Deck.h"
#include "Hand.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int nCards = 52; //52 Cards in a deck
    Deck crdDeck(nCards);
    
    //Process, map inputs to outputs
    //Shuffle the deck for each player to receive
    crdDeck.shuffle();
    
    //Create and print player's first hand of two cards
    unsigned char nHands = 4; //4 hands being delt
    unsigned char nDelt = 2;  //2 cards delt
    
    for(unsigned char handNum = 1; handNum <= nHands; handNum++){
        cout << "Player " << static_cast<int>(handNum) << " hand: "
             << endl;
        Hand hand(crdDeck.deal(nDelt), nDelt);
        hand.display();
        cout << endl;
    }
    
    //Exit stage right
    return 0;
}