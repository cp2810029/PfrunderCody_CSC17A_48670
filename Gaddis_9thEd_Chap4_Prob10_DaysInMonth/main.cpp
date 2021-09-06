/*
    Author: Cody Pfrunder
    Date:   4 September 2021 3:15 p.m.
    Purpose:Calculate the days in a particular month
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
    int month,
        year;
    
    //Initialize variables
    cout << "This program will tell you the days in a particular month"
         << " of a particular year.\n";
    cout << "Enter MONTH (1 - 12):\n";
    cin >> month;
    cout << endl;
    
    cout << "Enter YEAR (1 - 9999):\n";
    cin >> year;
    cout << endl;
    
    //Process, map inputs to outputs
    if(year >= 0 && year <= 9999)
    {
        switch(month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                cout << "31 days...\n";
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                cout << "30 days...\n";
                break;
            case 2:
                if(year % 100 == 0){
                    if(year % 400 == 0)
                        cout << "29 days...\n";
                    else
                        cout << "28 days...\n";            
                }
                else if(year % 100 != 0){
                    if(year % 4 == 0)
                        cout << "29 days...\n";
                    else
                        cout << "28 days...\n";
                }
                break;
            default:
                cout << "Invalid month - RERUN PROGRAM.\n";
        }
                
    }
    else{
        cout << "Invalid year - RERUN PROGRAM.\n";
    }
    cout << endl << endl;
    
    //Exit stage right
    return 0;
}