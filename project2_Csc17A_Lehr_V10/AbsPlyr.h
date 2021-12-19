/* 
 * File:   AbsPlyr.h
 * Author: codyp
 * Purpose: Abstract Player class spec.
 */

#ifndef ABSPLYR_H
#define ABSPLYR_H

#include <string>
using namespace std;

#include "Hand.h"

class AbsPlyr {
    public:
        virtual void setHand(Hand*) = 0;
        virtual string getName() = 0;
        virtual void prntHnd() = 0;
};

#endif /* ABSPLYR_H */