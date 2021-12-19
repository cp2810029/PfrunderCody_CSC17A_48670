/* 
 * File:   PlyCrdV.cpp
 * Author: codyp
 * Purpose: Player card value class implementation
 */

#include "PlyCrdV.h"

int PlyCrdV::cdVlInp(){
    do{
        valid = 0;
        cin >> cVal;
        if(inRange(cVal)){
            valid++;
        }
        while(!cin){ //Check for integer input
            cout << "That was no integer! Please enter an integer: ";
            cin.clear();
            cin.ignore();
            cin >> cVal;
            if(inRange(cVal)){
                valid++;
            }
        }
    }while(valid < 1);
    return cVal;
}

//Check if card value input is 1 through 10
bool PlyCrdV::inRange(int x){
    if(x < 1 || x > 10){
        return false;
    }
    else if(x >= 1 && x <= 10){
        return true;
    }
}