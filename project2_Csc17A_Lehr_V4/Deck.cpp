/* 
 * File:   Deck.cpp
 * Author: codyp
 * Purpose: Deck class implementation
 */

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Deck.h"

Deck::Deck(unsigned char n){
    //Random number seed generator
    srand(static_cast<unsigned int>(time(0)));
    //All properties of the class get initialized
    nCards = (n >= 0 ? n : 52);
    nShuff = 7;
    nDeal = 0;
    index = new unsigned char[nCards];
    card = new Cards*[nCards]; //Array of 52 card pointers
    for(unsigned char i = 0; i < nCards; i++){
        card[i] = new Cards(i); //Create each card individually
        index[i] = i;
    }
}

Deck::~Deck(){
    delete [] index;
    for(unsigned char crd = 0; crd < nCards; crd++){
        delete card[crd]; //Destruct each individual card
    }
    delete [] card; //Destruct array of card pointers
    
}

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

unsigned char *Deck::deal(unsigned char nDelt){
    //Create hand here
    if(nDelt >= nCards - nDeal){
        shuffle();
        nDeal = 0;
    }
    unsigned char *hand = new unsigned char[nDelt];
    for(unsigned char i = 0; i < nDelt; i++){
        hand[i] = index[nDeal++];
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

