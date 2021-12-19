/*
    Author: Cody Pfrunder
    Date:   November 28, 2021
    Purpose:Project Two - Blackjack
            V5 Create player class and instantiate from abstract player class to 
            include name, a hand, and print func. Next we will add a dealer to 
            commit all of the procedures pertaining to dealing to 4 players
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation
#include <ctime>       //ctime Library
using namespace std;   //Library Name-space

//User Libraries
#include "Dealer.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int nCards = 52;      //52 Cards in a deck
    unsigned char nDeal = 2;  //# of cards delt
    Dealer dlr("Dealer", nCards, nDeal); 
    
    //Dealer shuffles deck of cards
    dlr.shuffle();
    
    //Initialize variables
    unsigned char nHands = 1; //4 player being delt 1 hand
    
    //Process, map inputs to outputs
    //Create and print player's first hand of two cards
    Players p1("Player 1"); //p1 - Player 1
    Players p2("Player 2"); //p2 - Player 2
    Players p3("Player 3"); //p3 - Player 3
    Players p4("Player 4"); //p4 - Player 4
    
    for(unsigned char handNum = 1; handNum <= nHands; handNum++){
        //Dealer deals player 1 hand
        p1.setHand(dlr.deal());
        //hand.display()
        cout << p1.getName() << "'s hand:" << endl;
        p1.prntHnd();
        cout << endl;
        
        //Dealer deals player 2 hand
        p2.setHand(dlr.deal());
        //hand.display()
        cout << p2.getName() << "'s hand:" << endl;
        p2.prntHnd();
        cout << endl;
        
        //Dealer deals player 3 hand
        p3.setHand(dlr.deal());
        //hand.display()
        cout << p3.getName() << "'s hand:" << endl;
        p3.prntHnd();
        cout << endl;
        
        //Dealer deals player 4 hand
        p4.setHand(dlr.deal());
        //hand.display()
        cout << p4.getName() << "'s hand:" << endl;
        p4.prntHnd(); 
        cout << endl;
    }
    
    //Dealer deals his/her own hand
    dlr.setHand(dlr.deal());
    //hand.display()
    cout << dlr.getName() << "'s hand:" << endl;
    dlr.prntHnd();
    cout << endl;
    
    //Exit stage right
    return 0;
}