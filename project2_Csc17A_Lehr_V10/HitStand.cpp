/* 
 * File:   HitStand.cpp
 * Author: codyp
 * Purpose: Hit or stand class implementation
 */

#include "HitStand.h"

char HitStand::hOrSInp(){
    //Assign choice (s for stand/h for hit) to each player
    do{
        valid = 0;
        cin >> choice;
        cin.ignore();
        if(validCh(choice)){
            valid++;
        }
    }while(valid < 1);
    return choice;
}

bool HitStand::validCh(char x){
    if(x == 'h' || x == 'H' || x == 's' || x == 'S'){
        return true;
    }
    else
        cout << "Invalid. Enter s/S for Stand or h/H for Hit\n";
        return false;
}