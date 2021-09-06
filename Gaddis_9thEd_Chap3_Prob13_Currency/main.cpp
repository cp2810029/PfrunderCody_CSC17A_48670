/*
    Author: Cody Pfrunder
    Date:   4 September 2021 2:00 p.m.
    Purpose:International Currency Exchange
*/

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>    //Input/Output Manipulation Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only
const float YEN_PER_DOLLAR = 98.93;
const float EUROS_PER_DOLLAR = 0.74;

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float usCred,  //Cash amt in US Dollars $
          yenPay,  //Amount in Yen
          euroPay; //Amount in Euros
    
    //Initialize variables
    cout << "Please input your amount of US Dollars that you would like to "
         << "exchange.\n";
    
    cin >> usCred;
    
    //Process, map inputs to outputs
    yenPay = (usCred * YEN_PER_DOLLAR);
    euroPay = (usCred * EUROS_PER_DOLLAR);
    
    //Display your initial conditions as well as outputs.
    cout << fixed << setprecision(2) << showpoint;
    cout << "Total US Currency: $" << usCred << endl << endl;
    cout << "Total Yen per dollar: " << yenPay << " YEN.\n";
    cout << "Total Euros per dollar: " << euroPay << " EUROS.\n";
    
    //Exit stage right
    return 0;
}