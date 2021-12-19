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
        int nCards;
        int nShuff;
        int nDeal;
        int *index;
        Cards **card;
    public:
        Deck(int n);
        ~Deck();
        void shuffle();
        int *deal(int);
};

#endif /* DECK_H */

