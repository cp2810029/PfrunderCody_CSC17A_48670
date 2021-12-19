/* 
 * File:   Cards.cpp
 * Author: codyp
 * Purpose: Cards class implementation
 */

#include "Cards.h"

//Card numbers initialized at 0 to process throughout functions
Cards::Cards(unsigned char i){
    crdNum = (i > 0 ? i : 0);
}
//Value for each individual card (52 card deck)
char Cards::crdVal(){
    int i = crdNum;
    i >= 0 ? i %= 13 : 0;
    i++;
    if(i > 10)
        i = 10;
    return i;
}
//Assign each card a face to its value
char Cards::crdFace(){
    int i = crdNum;
    i >= 0 ? i %= 52 : 0;
    char face[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J',
                   'Q', 'K'};
    return face[i % 13];
}
//Each card belongs to a suit i.e. "Clubs" , "Hearts" , "Spades" , "Diamonds"
char Cards::crdSuit(){
    int i = crdNum;
    i >= 0 ? i %= 52 : 0;
    char suit[] = {'S', 'D', 'H', 'C'};
    return suit[i / 13];
}