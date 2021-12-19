/* 
 * File:   PlyrBet.h
 * Author: codyp
 * Purpose: Player bet class spec.
 */

#ifndef PLYRBET_H
#define PLYRBET_H
#include <iostream>
#include <iomanip>

using namespace std;

class PlyrBet{
    private:
        int valid;
    public:
        int bet;
        int bets[4] = {0, 0, 0, 0};
        int pBets();
        void prntBet();
        bool inRange(int);
};

#endif /* PLYRBET_H */

