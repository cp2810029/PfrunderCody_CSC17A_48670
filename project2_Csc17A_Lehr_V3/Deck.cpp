/* 
 * File:   Deck.cpp
 * Author: codyp
 * Purpose: Deck class implementation
 */

#include <ctime>
#include <cstdlib>

#include "Deck.h"

Deck::Deck(int n){
    //Random number seed generator
    srand(static_cast<unsigned int>(time(0)));
    //All properties of the class get initialized
    nCards = (n >= 0 ? n : 52);
    nShuff = 7;
    nDeal = 0;
    index = new int[nCards];
    card = new Cards*[nCards]; //Array of 52 card pointers
    for(int i = 0; i < nCards; i++){
        card[i] = new Cards(i); //Create each card individually
        index[i] = i;
    }
}

Deck::~Deck(){
    for(int i = 0; i < nCards; i++){
        delete card[i]; //Destruct each individual card
    }
    delete [] card; //Destruct array of card pointers
    delete [] index;
}

void Deck::shuffle(){
    for(int i = 1; i <= nShuff; i++){
        for(int j = 0; j < nCards; j++){
            int temp = rand()%nCards;
            int card = index[j];
            index[j] = index[temp];
            index[temp] = card;
        }
    }
}

int *Deck::deal(int n){
    int handNum = n > 0 ? n : 5;
    int *hand = new int[handNum];
    if(handNum > nCards - nDeal){
        shuffle();
        nDeal = 0;
    }
    for(int i = 0; i < handNum; i++){
        hand[i] = index[nDeal++];
    }
    return hand;
}

