/*
    Author: Cody Pfrunder
    Date:   4 September 2021 5:45 p.m.
    Purpose:Celsius Temperature Table
*/

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
float celsius(float); //celsius function

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int initial, //start of table at 0
        final;   //end of table at 20
    
    float cels;  //converted celsius
    
    //Initialize variables
    initial = 0;
    final = 20;
    
    //Process, map inputs to outputs
    //Table layout
    cout << "--------------------------------------------\n";
    cout << "Fahrenheit        |  Celsius\n";
    cout << "--------------------------------------------\n";
    
    //for loop to calculate table 0 -> 20
    //initialize F (fahrenheit)
    for(int F = initial; F <= final; F++){
        cels = celsius(F);
        cout << F << "                 ";
        cout << cels << endl;
    }
    
    //Exit stage right
    return 0;
}
//Celsius Function - Calc degrees from fahrenheit to celsius
float celsius(float F){
    return ((5.0 / 9.0) * (F - 32.0));
}