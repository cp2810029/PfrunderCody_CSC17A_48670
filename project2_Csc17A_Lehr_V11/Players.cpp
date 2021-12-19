/* 
 * File:   Players.cpp
 * Author: codyp
 * Purpose: Players class implementation
 */

#include "Players.h"

Players::Players(string n){
    pName = n;
}

void Players::setHand(Hand *h){
    hand = h;
}

void Players::prntHnd(){
    hand->display();
}

int Players::sumHand(){
    hand->sumHand();
}