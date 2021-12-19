/*
    Author: Cody Pfrunder
    Date:   November 28, 2021 10:00 p.m.
    Purpose:Project Two - Blackjack
            V10 - Making a template class.
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation
#include <ctime>       //ctime Library

using namespace std;   //Library name space

//User Libraries
#include "Dealer.h"
#include "PlyrBet.h"
#include "PlyCrdV.h"
#include "HitStand.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void ptReslt(int [], int [], int []);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int nCards = 52;                     //52 Cards in a deck
    unsigned char nDeal = 1;             //# of cards delt
    Dealer dlr("Dealer", nCards, nDeal); //Dealer object
    PlyCrdV pCrdV;                       //Player card value object
    PlyrBet pBet;                        //PlyrBet class object
    HitStand hOrS;                       //HitStand class object
    
                            
    //Initialize variables
    unsigned char nHands = 1; //4 player being delt 1 hand
    unsigned char nPlyrs = 5; //4 Players, 1 dealer
    int cVal = 0;             //Individual card value taken into account for a 
                              //hand sum
    int handTtl[5] = {0, 0, 0, 0, 0}; //hand total starts at 0
    int bet;
    int bets[4] = {0, 0, 0, 0};       //4 players bet
    char choices[4]; //Array keeping players 1 - 4 choice to hit/stand
    char pChoice;    //Players choice
    int blckJck[4] = {0, 0, 0, 0};       //Keeps track of possible ace and 
                                         //10, K, Q card on initial hand
                                         //(This would be blackjack)
    
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
    for(int i = 0; i < 4; i++){
        cout << "Player " << i+1 << ": \n";
        bet = pBet.pBets();
        cout << "Player " << i+1 << " placed a bet of $";
        pBet.prntBet();
        bets[i] += bet;
    }
    

    //Set hand for each player and print
    for(unsigned char handNum = 1; handNum <= nHands; handNum++){
        for(unsigned char ply = 0; ply < nPlyrs; ply++){
            plyr[ply]->setHand(dlr.deal());
            //hand.display();
            cout<< plyr[ply]->getName()<<"'s Hand"<<endl;
            //Print hand
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
        //Display hand total
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
                //Print hand
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
                        //Print hand
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
                                //Print hand
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
            plyr[4]->setHand(dlr.deal());
            //hand.display();
            cout<< plyr[4]->getName()<<"'s Hand"<<endl;
            //Print hand
            plyr[4]->prntHnd();
            cout << "Enter card value: ";
            cVal = pCrdV.cdVlInp();
            handTtl[4] += cVal;
            //if dealer got an ace or 10 for the first card, and either an ace
            //to match with a 10, or 10 with an ace on this second card
            if(blckJck[4] == 1 && handTtl[4] == 11){
                blckJck[4]++;
            }
            cout << plyr[4]->getName() << " you hold "
                 << "the hand valued at: " << handTtl[4] 
                 << endl << endl;
            //Dealers possible next cards
            do{
                plyr[4]->setHand(dlr.deal());
                //hand.display();
                cout<< plyr[4]->getName()<<"'s Hand"<<endl;
                //Print hand
                plyr[4]->prntHnd();
                cout << "Enter card value: ";
                cVal = pCrdV.cdVlInp();
                handTtl[4] += cVal;
                cout << plyr[4]->getName() << " you hold "
                     << "the hand valued at: " << handTtl[4] 
                     << endl << endl;
                //Total is equal to 21 blackjack, when blckJck[] = 2, 
                //the player or dealer have a blackjack
                if(handTtl[4] == 21){
                    blckJck[4] = 2;
                }
            }while((blckJck[4] < 2) || (handTtl[4] < 17));
    }
    
    ptReslt(handTtl, bets, blckJck);
    
    //Recover memory
    for(unsigned char ply =0; ply < nPlyrs-1; ply++){
        delete plyr[ply];
    }
    delete []plyr;
    
    //Exit stage right
    return 0;
}

//Print final winning/losing results
void ptReslt(int handTtl[], int bets[], int blckJck[]){
    for(int k = 0; k < 4; k++){
        cout << "Player " << k + 1 <<": \n";
        //Dealer wins by greater
        if(handTtl[4] > handTtl[k] && (handTtl[4] < 21 && blckJck[k] != 2)){
            cout << "You lose...\n";
            cout << "Dealer wins with value of " << handTtl[4] <<".\n\n";
        }
        //Player bust
        else if(handTtl[k] > 21 && handTtl[4] <= 21){
            cout << "Your hand holds the total value: " << handTtl[k] << ".\n";
            cout << "You lose with a busted hand. Dealer wins.\n\n";
        }
        //Dealer bust
        else if(handTtl[4] > 21 && (handTtl[k] < 21 && blckJck[k] != 2)){
            cout << "Dealer has a hand with total value: " 
                 << handTtl[4] << ".\n";
            cout << "You win! the dealer busts.\n";
            (bets[k]) *= 2.0;
            cout << "Your winnings are: $" << bets[k] << endl << endl;
        }
        //Player and dealer have same hand
        else if(handTtl[k] == handTtl[4] && handTtl[k] <= 21){
            cout << "Dealer has a hand with total value: "<< handTtl[4] << ".\n"
                 << "You and the dealer have the same hand.\n"
                 << "You get your money back with no damage done!\n\n";
        }
        //Player wins
        else if(handTtl[k] > handTtl[4] && handTtl[k] < 21){
            cout << "You win!\n"
                 << "Dealer has a hand with total value: "<< handTtl[4] << ".\n"
                 << "Your winnings are: $" << (bets[k]*2.0) << endl << endl;
        }
        //Player got blackjack
        else if((handTtl[k] = 21) || (blckJck[k] = 2) 
                && (handTtl[k] > handTtl[4])){
            cout << "The total value of your hand is " << handTtl[k] << ".\n"
                 << "You got BLACKJACK!\n"
                 << "Dealer has a hand with total value: " 
                 << handTtl[4] << ".\n"
                 << "Because you got BLACKJACK your winnings are "
                 << "increased by 1.25x.\n";
            bets[k] = bets[k] + (bets[k]*(1.25));
            cout << fixed << showpoint << setprecision(2);
            cout << "Your winnings are: $" << bets[k] << endl << endl;
        }
        //Player got blackjack and dealer busts
        else if((handTtl[k] == 21) || (blckJck[k] == 2) && (handTtl[4] > 21)){
            cout << "The total value of your hand is " << handTtl[k] << ".\n"
                 << "You got BLACKJACK!\n"
                 << "Dealer has a hand with total value: " << handTtl[4] 
                 << ".\n"
                 << "Because you got BLACKJACK your winnings are "
                 << "increased by 1.25x.\n";
            bets[k] = bets[k] + (bets[k]*1.25);
            cout << "Your winnings are: $" << bets[k] << endl << endl;
        }
        //Dealer and Player got blackjack
        else if((handTtl[k] == 21) || (blckJck[k] == 2) && (handTtl[4] == 21) || 
                (blckJck[4] == 2)){                                
            cout << "The total value of your hand is " << handTtl[k] << ".\n";
            cout << "You and the dealer both got Blackjack!\n"
                 << "You get your money back with no damage done.\n\n";
        }
        //Dealer wins by blackjack
        else if((handTtl[4] == 21) || (blckJck[4] == 2) && 
                ((handTtl[k] < handTtl[4]) && (blckJck[k] != 2))){
            cout << "The dealer's hand is valued " << handTtl[4] << ".\n"
                 << "The dealer got BLACKJACK\n"
                 << "Sorry, you lose, better luck next time.\n\n";
        }
        //Dealer and player both bust
        else if(handTtl[4] > 21 && handTtl[k] > 21){
            cout << "No harm done. You get your money back.\n"
                 << "You hand the dealer both went bust!\n\n";
        }
    }
}