/* 
 * File:   BetCnt.h
 * Author: codyp
 * Purpose: BetCnt Class Specification
 */
#include "iostream"
using namespace std;

#ifndef BETCNT_H
#define BETCNT_H

class BetCnt {
    public:
        static int bCount;
        BetCnt(){
            bCount++;
        }
        void bCntTtl();
};

#endif /* BETCNT_H */

