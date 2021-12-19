/* 
 * File:   BetCnt.cpp
 * Author: codyp
 * Purpose: BetCnt Implementation
 */

#include "BetCnt.h"

int BetCnt::bCount = 0;

void BetCnt::bCntTtl(){
    cout << endl << bCount << " player(s) have made a bet.\n\n";
}