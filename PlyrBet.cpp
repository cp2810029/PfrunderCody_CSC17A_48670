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
            try{
                if(bet == 0){
                    throw bet;
                }
                bet = bet;
            }
            //Exception
            catch(int exc){
                cout << "Exception: Input for a player's bet cannot be zero. -" 
                     << " " << exc;
            } 
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
    cout << fixed << setprecision(2) << showpoint;
    cout << static_cast<float>(bet)<<endl; 
    cout << "-------------------------------------------\n";
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