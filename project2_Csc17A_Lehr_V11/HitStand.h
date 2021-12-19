/* 
 * File:   HitStand.h
 * Author: codyp
 * Purpose: Hit or stand class spec.
 */

#ifndef HITSTAND_H
#define HITSTAND_H

#include <iostream>
using namespace std;

class HitStand{
    private:
        int valid = 0; //Validity check
    public:
        char choice;
        char hOrSInp();
        bool validCh(char);
};

#endif /* HITSTAND_H */