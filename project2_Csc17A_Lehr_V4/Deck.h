/* 
 * File:   Deck.h
 * Author: codyp
 * Purpose: Deck class
 */

#ifndef DECK_H
#define DECK_H

#include "Cards.h"

class Deck{
    private:
        unsigned char nCards;
        unsigned char nShuff;
        unsigned char nDeal;
        unsigned char *index;
        Cards **card;
    public:
        Deck(unsigned char);
        ~Deck();
        void shuffle();
        unsigned char *deal(unsigned char);
        void display();
};

#endif /* DECK_H */

