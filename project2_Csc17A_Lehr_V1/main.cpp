/*
    Author: Cody Pfrunder
    Date:   November 28, 2021
    Purpose:Project Two - Blackjack, just starting.
            Displaying expertise covering classes,
            inheritance, operator overloading, polymorphism
            and templates. 
            V1 Creating a class for a deck of cards that can be shuffled the 
            most efficient and correct way. reference Professor Lehr's 
            lecture 11/28/21. 
            
 */

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries
#include "Cards.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    Cards **crdDeck; //Creating on object to hold a deck of cards
                     //Double pointer to create each individual card
 
    //Initialize variables
    int nCards = 52; //52 Cards in a deck
    crdDeck = new Cards*[nCards]; //Creating an array of 52 Card Pointers
    //Instantiate each card into the deck
    for(int i = 0; i < nCards; i++){
        crdDeck[i] = new Cards(i);
    }
    
    //Process, map inputs to outputs
    for(int i = 0; i < 52; i++){
        cout << "Card #" << i + 1 << ": " << crdDeck[i]->crdFace() << " of " 
             << crdDeck[i]->crdSuit() 
             << " " << static_cast<int>(crdDeck[i]->crdVal()) 
             << endl;
    }
    
    //Display your initial conditions as well as outputs.
    
    //Reallocate memory
    for(int i = 0; i < nCards; i++){
        delete crdDeck[i]; //Destruct each individual card
    }
    delete [] crdDeck; //Destruct array of card pointers
    
    //Exit stage right
    return 0;
}