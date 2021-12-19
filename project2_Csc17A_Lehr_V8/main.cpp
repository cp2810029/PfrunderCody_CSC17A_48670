/*
    Author: Cody Pfrunder
    Date:   November 28, 2021
    Purpose:Project Two - Blackjack
            V8 Calculate dealers following cards after players hit and stand.
               Add to total in the array for the dealer until soft hand 17 is 
               reached. 
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation
#include <ctime>       //ctime Library
#include <vector>      //Vector Library
using namespace std;   //Library name space

//User Libraries
#include "Dealer.h"
#include "PlyrBet.h"
#include "PlyCrdV.h"
#include "HitStand.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int nCards = 52;                     //52 Cards in a deck
    unsigned char nDeal = 1;             //# of cards delt
    Dealer dlr("Dealer", nCards, nDeal); //Dealer object
    PlyCrdV pCrdV;                       //Player card value object
    PlyrBet pBet;                        //PlyrBet class object
    HitStand hOrS;                       //HitStand class object
    int blckJck[4] = {0, 0, 0, 0};       //Keeps track of possible ace and 
                                         //10, K, Q card on initial hand
                                         //(This would be blackjack)
                            
    //Initialize variables
    unsigned char nHands = 1; //4 player being delt 1 hand
    unsigned char nPlyrs = 5; //4 Players, 1 dealer
    int cVal = 0;             //Individual card value taken into account for a 
                              //hand sum
    int valid = 0;            //Validity check
    int handTtl[5] = {0, 0, 0, 0, 0}; //hand total starts at 0
    char choices[4];
    char pChoice;
    
    //Process, map inputs to outputs
    //Create and print player's first hand of two cards
    Players **plyr = new Players*[nPlyrs];
    plyr[0] = new Players("Player 1");
    plyr[1] = new Players("Player 2");
    plyr[2] = new Players("Player 3");
    plyr[3] = new Players("Player 4");        
    plyr[4] = &dlr; //Polymorphic behavior in action
                    //Dealer is treated like a player but has other abilities
    
    //Dealer shuffles and display deck of cards
    cout << "Here is the deck of cards being used. You can see it is shuffled!";
    cout << endl;
    dlr.shuffle();
    dlr.display();
    
    //Prompt players to bet after sitting at table
    cout << "Take a seat happy gamblers! Each player, PLACE YOUR BETS.\n";
    cout << "Only whole bills are allowed, no coins or change.\n";
    pBet.pBets();
    pBet.prntBet();

    //Set hand for each player and print
    for(unsigned char handNum = 1; handNum <= nHands; handNum++){
        for(unsigned char ply = 0; ply < nPlyrs; ply++){
            plyr[ply]->setHand(dlr.deal());
            //hand.display();
            cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
            plyr[ply]->prntHnd();
            //card 2
            plyr[ply]->setHand(dlr.deal());
            if(ply <= 0 || ply < 4){
                plyr[ply]->prntHnd();
            }
            cout << endl;
        }
    }
    
    //Allow each player to enter card values for a total
    for(int i = 0; i < 5; i++){
        cout << plyr[i]->getName() << ", you have received your first "
             << "card(s).\n";
        cout << "Enter card 1 value: ";
        cVal = pCrdV.cdVlInp();
        if(cVal == 1 || cVal == 10){
            blckJck[i]++;
        }
        handTtl[i] += cVal;
        //Only second card input for players not dealer
        //After the player decides to hit/stand, the dealers second card is
        //revealed
        if(i <= 0 || i < 4){
            cout << "Enter card 2 value: ";
            cVal = pCrdV.cdVlInp();
            handTtl[i] += cVal;
            if(blckJck[i] == 1 && handTtl[i] == 11){
                blckJck[i]++;
            }
        }
        cout << plyr[i]->getName() << " you currently hold the hand valued "
             << "at: " << handTtl[i] << endl << endl;
    } 
    
    //Check for blackjack. All players without hand total (Blackjack) will be
    //prompted to stand or hit for another card.
    cout << "The dealers second card is disclosed until players decide to "
         << "hit or stand.\n";
    
    //Prompt player to stand with current hand or hit for another card
    cout << "Would you like to stand, or hit? Type(s/S for stand "
         << "or h/H for hit) IF YOU HOLD an ACE and 10 valued card you have"
         << " BLACKJACK. No need to hit or stand.\n\n";
    
    //Call class function for players decision to hit or stand
    for(int i = 0; i < 4; i++){
        cout << "Player " << i + 1 << ": \n";
        if(blckJck[i] != 2){
            pChoice = hOrS.hOrSInp();
            cout << "Player "<< i + 1 << " decided " << pChoice << endl; 
            cout << "-----------------------\n";
            choices[i] = pChoice;  
        }   
    }
    
    //Players hit or stand until satisfied up to a fifth card
    for(unsigned char handNum = 1; handNum <= nHands; handNum++){
        for(unsigned char ply = 0; ply < nPlyrs; ply++){
            //Display hand if player chose to stand
            if(choices[ply] == 's' || choices[ply] == 'S'){
                cout << "Player " << ply + 1 << " you stand with the hand "
                     << "valued: " << handTtl[ply]
                     << "\n---------------------------------\n";  
            }
            //Player chooses to hit - display new card and get input
            if(choices[ply] == 'h' || choices[ply] == 'H'){
                plyr[ply]->setHand(dlr.deal());
                //hand.display();
                cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
                plyr[ply]->prntHnd();
                //Input card value
                if(ply <= 0 || ply < 4){
                    cout << "Enter card value: ";
                    cVal = pCrdV.cdVlInp();
                    handTtl[ply] += cVal;
                }
                cout << plyr[ply]->getName() << " you now hold the hand "
                     << "valued at: " << handTtl[ply] << endl << endl;
                if(handTtl[ply] < 21){
                    //Prompt for a fourth card
                    cout << "You received your third card, would you like to "
                         << "hit again, or stand? Type(s/S for stand or h/H for"
                         << " hit)\n";
                    pChoice = hOrS.hOrSInp();
                    choices[ply] = pChoice;
                    //Display hand if player chose to stand
                    if(choices[ply] == 's' || choices[ply] == 'S'){
                        cout << "Player " << ply + 1 
                             << " you stand with the hand valued: " 
                             << handTtl[ply]
                             << "\n---------------------------------\n";  
                    }
                    //Player chooses to hit - display new card and get input
                    if(choices[ply] == 'h' || choices[ply] == 'H'){
                        plyr[ply]->setHand(dlr.deal());
                        //hand.display();
                        cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
                        plyr[ply]->prntHnd();
                        //Input card value
                        if(ply <= 0 || ply < 4){
                            cout << "Enter card value: ";
                            cVal = pCrdV.cdVlInp();
                            handTtl[ply] += cVal;
                        }
                        cout << plyr[ply]->getName() << " you now hold the hand"
                             << " valued at: " << handTtl[ply] << endl << endl;
                        if(handTtl[ply] < 21){
                            //Prompt for a fifth card
                            cout << "You received your fourth card, would you "
                                 << "like to hit again, or stand? Type(s/S for "
                                 << "stand or h/H for hit)\n";
                            pChoice = hOrS.hOrSInp();
                            choices[ply] = pChoice;
                            //Display hand if player chose to stand
                            if(choices[ply] == 's' || choices[ply] == 'S'){
                                cout << "Player " << ply + 1 
                                     << " you stand with the hand valued: " 
                                     << handTtl[ply]
                                     << "\n---------------------------------\n";  
                            }
                            //Player chooses to hit - display new card and get 
                            //input
                            if(choices[ply] == 'h' || choices[ply] == 'H'){
                                plyr[ply]->setHand(dlr.deal());
                                //hand.display();
                                cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
                                plyr[ply]->prntHnd();
                                //Input card value
                                if(ply <= 0 || ply < 4){
                                    cout << "Enter card value: ";
                                    cVal = pCrdV.cdVlInp();
                                    handTtl[ply] += cVal;
                                }
                                cout << plyr[ply]->getName() << " you now hold "
                                     << "the hand valued at: " << handTtl[ply] 
                                     << endl << endl;
                            }
                        }
                    }
                }    
            }
        }
    }
    
    //Dealers hand after receiving first card in beginning of game.
    //The dealer only gets one card at first so the players have mystery 
    //pertaining to a win while hitting/standing based on their hand total
    //Dealers second card -
    for(unsigned char handNum = 1; handNum <= nHands; handNum++){
        for(unsigned char ply = 4; ply <= nPlyrs; ply++){
            plyr[ply]->setHand(dlr.deal());
            //hand.display();
            cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
            plyr[ply]->prntHnd();
            cout << "Enter card value: ";
            cVal = pCrdV.cdVlInp();
            handTtl[ply] += cVal;
            if(blckJck[ply] == 1 && handTtl[ply] == 11){
                blckJck[ply]++;
            }
            cout << plyr[ply]->getName() << " you hold "
                 << "the hand valued at: " << handTtl[ply] 
                 << endl << endl;
            //Dealers possible third card
            if(blckJck[ply] != 2 && handTtl[ply] < 17){
                plyr[ply]->setHand(dlr.deal());
                //hand.display();
                cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
                plyr[ply]->prntHnd();
                cout << "Enter card value: ";
                cVal = pCrdV.cdVlInp();
                handTtl[ply] += cVal;
                cout << plyr[ply]->getName() << " you hold "
                 << "the hand valued at: " << handTtl[ply] 
                 << endl << endl;
                if(handTtl[ply] == 21){
                    blckJck[ply] = 2;
                }
            }
            //Dealers possible fourth card
            if(blckJck[ply] != 2 && handTtl[ply] < 17){
                plyr[ply]->setHand(dlr.deal());
                //hand.display();
                cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
                plyr[ply]->prntHnd();
                cout << "Enter card value: ";
                cVal = pCrdV.cdVlInp();
                handTtl[ply] += cVal;
                cout << plyr[ply]->getName() << " you hold "
                 << "the hand valued at: " << handTtl[ply] 
                 << endl << endl;
                if(handTtl[ply] == 21){
                    blckJck[ply] = 2;
                }
            }
            //Dealers possible fifth card
            if(blckJck[ply] != 2 && handTtl[ply] < 17){
                plyr[ply]->setHand(dlr.deal());
                //hand.display();
                cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
                plyr[ply]->prntHnd();
                cout << "Enter card value: ";
                cVal = pCrdV.cdVlInp();
                handTtl[ply] += cVal;
                cout << plyr[ply]->getName() << " you hold "
                 << "the hand valued at: " << handTtl[ply] 
                 << endl << endl;
                if(handTtl[ply] == 21){
                    blckJck[ply] = 2;
                }
            }
        }
    }
    
    //Recover memory
    for(unsigned char ply =0; ply < nPlyrs-1; ply++){
        delete plyr[ply];
    }
    delete []plyr;
    
    //Exit stage right
    return 0;
}

