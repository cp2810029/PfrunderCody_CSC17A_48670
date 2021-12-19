/* 
 * File:   Hand.h
 * Author: codyp
 * Purpose: Hand class spec.
 */

#ifndef HAND_H
#define HAND_H

class Hand{
    private:
        unsigned char *cards; //card representation int array
        unsigned char nCards; //no. of cards
    public:
        Hand(unsigned char *, unsigned char);
        ~Hand();
        void display();
        int sumHand();
};

#endif /* HAND_H */

