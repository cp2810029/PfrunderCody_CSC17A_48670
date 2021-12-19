/* 
 * File:   Hand.h
 * Author: codyp
 * Purpose: Hand class spec.
 */

#ifndef HAND_H
#define HAND_H

class Hand{
    private:
        unsigned char nCards; //no. of cards
        unsigned char *cards; //card representation int array
    public:
        Hand(unsigned char *, unsigned char);
        ~Hand();
        void display();
};

#endif /* HAND_H */

