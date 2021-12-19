/* 
 * File:   PlyrBet.cpp
 * Author: codyp
 * Purpose: Player bet class implementation
 */

#include "PlyrBet.h"

int PlyrBet::pBets(){
        do{
            valid = 0;
            cin >> bet;
            if(inRange(bet)){
                valid++;
            }
            //Check for integer input
            while(!cin){ 
                cout << "That was no integer! Please enter an integer: ";
                cin.clear();
                cin.ignore();
                cin >> bet;
                if(inRange(bet)){
                    valid++;
                }
            }
        }while(valid<1);
    return bet;
}

void PlyrBet::prntBet(){
    //for (int k = 0; k < 4; k++){
        cout << fixed << setprecision(2) << showpoint;
        cout << static_cast<float>(bet)<<endl; 
        cout << "-------------------------------------------\n";
    //}
}

//Check if card value input is 1 through 10
bool PlyrBet::inRange(int x){
    if(x < 1){
        return false;
    }
    else if(x > 1){
        return true;
    }
}