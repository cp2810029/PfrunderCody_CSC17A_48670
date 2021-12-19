/* 
 * File:   PlyCrdV.h
 * Author: codyp
 * Purpose: Player card value class spec
 */

#ifndef PLYCRDV_H
#define PLYCRDV_H

#include <iostream>
using namespace std;

class PlyCrdV{
    private:
        int value;
    public:
        int valid = 0; //Validity check
        int cVal = 0;  //Individual card value taken into account for 
                       //a hand sum
        int cdVlInp();     //Card value input function
        bool inRange(int); //Check if card value input is 1 through 10
};

#endif /* PLYCRDV_H */