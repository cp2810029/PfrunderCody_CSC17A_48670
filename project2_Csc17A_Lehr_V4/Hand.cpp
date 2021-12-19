/* 
 * File:   Hand.cpp
 * Author: codyp
 * Purpose: Hand class implementation
 */

#include "Hand.h"
#include "Cards.h"
#include <iostream>
using namespace std;

//Number of cards in the hand; what they are
Hand::Hand(unsigned char *crd, unsigned char n){
    cards = crd;
    nCards = n;
}

//Destroy
Hand::~Hand(){
    delete [] cards;
}

void Hand::display(){
    for(char crd = 0; crd < nCards; crd++){
        Cards card(cards[crd]);
        cout << "Card #" << static_cast<int>(cards[crd]) << " of 52: " 
             << card.crdFace() << card.crdSuit() << " " 
             << static_cast<int>(card.crdVal()) << endl;
    }
}