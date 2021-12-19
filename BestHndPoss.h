/* 
 * File:   DoubleBet.h
 * Author: codyp
 * Purpose: Best hand possible class specification
 *          Use of operator overloading
 */

#ifndef DOUBLEBET_H
#define DOUBLEBET_H

class BestHndPoss{
    public:
        float x = 10.5;
        BestHndPoss operator + (BestHndPoss doub){
            BestHndPoss hndBest;
            hndBest.x = x + doub.x;
            return hndBest;
        }
};

#endif /* DOUBLEBET_H */

