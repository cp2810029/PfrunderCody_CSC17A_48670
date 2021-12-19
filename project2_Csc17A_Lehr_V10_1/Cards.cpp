/* 
 * File:   Cards.cpp
 * Author: codyp
 * Purpose: Cards class implementation
 */

#include "Cards.h"

//Card numbers initialized at 0 to process throughout functions
Cards::Cards(unsigned char i){
    crdNum = (i%52);
}
//Value for each individual card (52 card deck)
char Cards::crdVal(){
    unsigned char i = crdNum % 13;
    i++;
    return i>10?10:i;
}
//Assign each card a face to its value
char Cards::crdFace(){
    char face[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J',
                   'Q', 'K'};
    unsigned char i = crdNum % 13;
    return face[i];
}
//Each card belongs to a suit i.e. "Clubs" , "Hearts" , "Spades" , "Diamonds"
char Cards::crdSuit(){
    char suit[] = {'S', 'D', 'H', 'C'};
    unsigned char i = crdNum /13;
    return suit[i];
}
