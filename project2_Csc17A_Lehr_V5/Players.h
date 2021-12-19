/* 
 * File:   Players.h
 * Author: codyp
 * Purpose: Player class spec.
 */

#ifndef PLAYERS_H
#define PLAYERS_H

#include "AbsPlyr.h"

class Players:public AbsPlyr{
    protected:
        string pName; //Players identification
        Hand *hand;
        
    public:
        Players(string);
        void setHand(Hand *);
        string getName(){
            return pName;
        }
        void prntHnd();
};

#endif /* PLAYERS_H */

