/*
    Author: Cody Pfrunder
    Date:   November 28, 2021
    Purpose:Project Two - Blackjack
            V2 After creating an initial class for deck of cards, create a map/
            index that will keep the program from throwing around huge objects.
            The index will be used to shuffle around each card instead of just 
            dealing out each individual card. This is preparation for a real 
            game with players to take place - what is happening behind the 
            scenes pertaining to the dealer.           
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation
using namespace std;   //Library Name-space

//User Libraries
#include "Cards.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void shuffle(int *, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    Cards **crdDeck; //Creating on object to hold a deck of cards
                     //Double pointer to create each individual card
    int nCards = 52; //52 Cards in a deck
    
    //Initialize variables
    int *index = new int[nCards]; //Initialize an index for shuffling
    crdDeck = new Cards*[nCards]; //Creating an array of 52 Card Pointers
    //Instantiate each card into the deck
    for(int i = 0; i < nCards; i++){
        crdDeck[i] = new Cards(i);
        index[i] = i;
    }
    
    //Process, map inputs to outputs
    //Shuffle index five times representing 52 cards
    shuffle(index, nCards, 5);
    for(int i = 0; i < nCards; i++){
        cout << "Card #" << index[i] << ":";
        if(index[i] < 10)  //A bit of formatting
            cout << setw(3);
        else
            cout << setw(2);
        cout << crdDeck[index[i]]->crdFace() << " of " 
             << crdDeck[index[i]]->crdSuit() << " " 
             << static_cast<int>(crdDeck[index[i]]->crdVal()) 
             << endl;
    }
    
    //Reallocate memory
    for(int i = 0; i < nCards; i++){
        delete crdDeck[i]; //Destruct each individual card
    }
    delete [] crdDeck; //Destruct array of card pointers
    delete [] index;
    
    //Exit stage right
    return 0;
}

//Shuffle function - takes index and shuffles it (moves integers around)
void shuffle(int *index, int n, int nShuff){
    for(int i = 0; i < nShuff; i++){
        for(int j = 0; j < n; j++){
            int temp = rand()%n;
            int card = index[j];
            index[j] = index[temp];
            index[temp] = card;
        }
    }
}