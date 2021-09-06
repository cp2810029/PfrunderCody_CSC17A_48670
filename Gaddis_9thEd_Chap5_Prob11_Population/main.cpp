/*
    Author: Cody Pfrunder
    Date:   4 September 2021 4:27 p.m.
    Purpose:Calculate Population Fluctuation
*/

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int popNum,
        days;
    
    float popInc;
    
    //Initialize variables
    cout << "Enter the starting population count (GREATER THAN or = to 2) :\n";
    cin >> popNum;
    
    cout << "Enter the number of days the population increases (1 or GREATER)"
         << " :\n";
    cin >> days;
    
    cout << "Enter the percentage increase PER DAY (POSITIVE NUMBER) :\n";
    cin >> popInc;
    
    //Process, map inputs to outputs
    if(popNum >= 2 && days >= 1 && popInc > 0){
        for(int i = 1; i <= days; i++){
            popNum = popNum + (popNum * popInc);
            cout << "Day " << i << ": " << popNum;
            cout << endl;
        }
    }
    else{
        cout << "INVALID INPUT - RERUN PROGRAM\n";
    }
    
    //Exit stage right
    return 0;
}