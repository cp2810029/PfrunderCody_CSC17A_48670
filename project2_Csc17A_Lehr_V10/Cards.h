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
    public:
        Cards(unsigned char);
        char crdVal();
        char crdFace();
        char crdSuit();
        char getCrdN(){
            return crdNum;
        }
};

#endif /* CARDS_H */