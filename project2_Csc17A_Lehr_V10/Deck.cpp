/* 
 * File:   Deck.cpp
 * Author: codyp
 * Purpose: Deck class implementation
 */

#include "Deck.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Deck::Deck(unsigned char n){
    //Random number seed generator
    srand(static_cast<unsigned int>(time(0)));
    //All properties of the class get initialized
    nCards = n >= 0 ? n : 52;
    nShuff = 7;
    nDelt = 0;
    //index to cards
    index = new unsigned char[nCards];
    card = new Cards*[nCards]; //Array of 52 card pointers
    //Create each card individually
    for(unsigned char crd = 0; crd < nCards; crd++){
        card[crd] = new Cards(crd);
        index[crd] = crd;
    }
}

//Delete array of pointers
Deck::~Deck(){
    delete [] index;
    for(unsigned char crd = 0; crd < nCards; crd++){
        delete card[crd]; //Destruct each individual card
    }
    delete [] card; //Destruct array of card pointers
    
}

//Shuffle deck using random temporary and temp with index
void Deck::shuffle(){
    for(int i = 1; i <= nShuff; i++){
        for(int j = 0; j < nShuff; j++){
            unsigned char tempR = rand()%nCards;
            unsigned char temp = index[j];
            index[j] = index[tempR];
            index[tempR] = temp;
        }
    }
}

//Deal and shuffle once too low
unsigned char *Deck::deal(unsigned char nDeal){
    //Create hand here
    if(nDeal >= nCards - nDelt){
        shuffle();
        nDelt = 0;
    }
    unsigned char *hand = new unsigned char[nDeal];
    for(unsigned char i = 0; i < nDeal; i++){
        hand[i] = index[nDelt++];
    }
    return hand;
}

void Deck::display(){
    for(unsigned char crd = 0; crd < nCards; crd++){
        cout<<static_cast<int>(index[crd])<<" "<<card[index[crd]]->crdFace()
                <<card[index[crd]]->crdSuit()<<" "
                <<static_cast<int>(card[index[crd]]->crdVal())<<endl;
    }
}

