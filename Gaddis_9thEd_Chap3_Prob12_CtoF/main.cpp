/*
    Author: Cody Pfrunder
    Date:   4 September 2021 1:15 p.m.
    Purpose:Convert degrees in Celsius
            to Fahrenheit
*/

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float cels, //Celsius input
          fahr; //Fahrenheit conversion
    
    //Initialize variables
    cout << "Input degrees Celsius.\n";
    cin >> cels;
    
    //Process, map inputs to outputs
    fahr = ((1.8 * cels) + 32); //F = (9/5 * C) + 32
    
    //Display your initial conditions as well as outputs.
    cout << fixed << setprecision(1) << showpoint;
    cout << "The degrees in Celsius that you input is: " << cels << " C.\n\n";
    cout << "CONVERTED to Fahrenheit is: " << fahr << "F.\n";
    
    //Exit stage right
    return 0;
}