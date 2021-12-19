/* 
 * File:   Hand.cpp
 * Author: codyp
 * Purpose: Hand class implementation
 */

#include "Hand.h"
#include "Cards.h"
#include <iostream>
using namespace std;

//Calculate the sum of each player's hand. If a player gets an ace card, the 
//card will either be scored an 11 or 1, whichever is most beneficial to the 
//player
int Hand::sumHand(){
    int sum = 0;
    int aces = 0;
    char i = 0;
    for(i; i < nCards; i++){
        Cards card(cards[i]);
        if(card.crdVal()==1){
            aces++;
            sum+=11;
        }
        else{
            sum += card.crdVal();
        }
    }
    while(sum > 21 && aces > 0){
        sum -= 10;
        aces--;
    }
    return sum;
}

//Number of cards in the hand; what they are
Hand::Hand(unsigned char *crd, unsigned char n){
    cards = crd;
    nCards = n;
}

//Destroy
Hand::~Hand(){
    delete [] cards;
}

//Hand display
void Hand::display(){
    for(char crd = 0; crd < nCards; crd++){
        Cards card(cards[crd]);
        cout << "Card #" << static_cast<int>(cards[crd]) << " of 52: " 
             << card.crdFace() << card.crdSuit() << " " 
             << static_cast<int>(card.crdVal()) << endl;
    }
}