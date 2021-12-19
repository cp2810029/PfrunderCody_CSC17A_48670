/* 
 * File:   Dealer.h
 * Author: codyp
 * Purpose: Dealer class spec.
 */

#ifndef DEALER_H
#define DEALER_H

#include "Players.h"
#include "Deck.h"

//Inherits from Players
class Dealer:public Players{
    protected:
        Deck *deck; //Dealer holds the deck   
    public:
        unsigned char nDeal;
        //Dealer gets components dealing, shuffling, etc.
        Dealer(string name,unsigned nCards, 
               unsigned nDeal):Players(name){
            deck = new Deck(nCards);
            this->nDeal=nDeal;
        };
        ~Dealer(){
            delete deck;
        }
        Hand *deal(){
            Hand *hand = new Hand(deck->deal(nDeal), nDeal);
            return hand;
        }
        void display(){
            deck->display();
        }
        void shuffle(){
            deck->shuffle();
        }
};

#endif /* DEALER_H */