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
        //Player name
        string name; 
        Hand *hand;
    public:
        Players(string);
        //set player hand
        void setHand(Hand *);
        //name getter
        string getName()
            {return name;}
        //Print card(s)
        void prntHnd();
        //Sum of cards stored as game progress
        int sumHand();
};

#endif /* PLAYERS_H */