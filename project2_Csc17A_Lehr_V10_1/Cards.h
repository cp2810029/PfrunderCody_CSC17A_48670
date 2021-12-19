/* 
 * File:   Cards.h
 * Author: codyp
 * Purpose: Cards class spec.
 */

#ifndef CARDS_H
#define CARDS_H

class Cards {
    private:
        unsigned char crdNum;
        //unsigned char handTtl = 0; //Total card value
    public:
        Cards(unsigned char);
        char crdVal();
        char crdFace();
        char crdSuit();
};

#endif /* CARDS_H */