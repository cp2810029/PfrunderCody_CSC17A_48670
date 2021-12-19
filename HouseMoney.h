/* 
 * File:   PlyHandEqual.h
 * Author: codyp
 * Purpose: PlyHandEqual class specification, determine if player's hands are
 *          equal using overloaded operator
 */

#ifndef PLYHANDEQUAL_H
#define PLYHANDEQUAL_H

class HouseMoney{
    public:
        int *bets;
        int b1 = bets[0];
        int b2 = bets[1];
        int b3 = bets[2];
        int b4 = bets[3];
        HouseMoney operator + (HouseMoney x){
            HouseMoney newAmt;
            newAmt.b1 = b1 + x.b2;
            newAmt.b1 += x.b3;
            newAmt.b3 += x.b4;
            return newAmt;
        }
};

#endif /* PLYHANDEQUAL_H */

