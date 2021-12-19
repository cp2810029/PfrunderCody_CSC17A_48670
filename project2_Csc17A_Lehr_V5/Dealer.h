/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
        unsigned char nDeal;
    public:
        //Dealer gets components dealing, shuffling, etc.
        Dealer(string pName,unsigned nCards, 
               unsigned nDeal):Players(pName){
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