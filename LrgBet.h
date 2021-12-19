/* 
 * File:   LrgBet.h
 * Author: codyp
 * Purpose: LrgBet Class/Template specification
 */

#ifndef LRGBET_H
#define LRGBET_H

#include <iostream>
using namespace std;

template <class T>
class LrgBet{
    T bOne, bTwo; //Two bets to compare
    public:
        LrgBet(T b1, T b2){
            //Initialize
            bOne = b1;
            bTwo = b2;
        }
        T bigger();
};

template <class T>
T LrgBet<T>::bigger(){ //Bigger function to determine which bet is largest
    return(bOne>bTwo?bOne:bTwo);
}

#endif /* LRGBET_H */

