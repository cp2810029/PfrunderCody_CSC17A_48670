/*
    Author: Cody Pfrunder
    Date:   October 30, 2021
    Purpose:Blackjack Game - Basic version w/out checklist incorporation
            Version 1: Take in bets, dist. two player cards, dealer gets cards, 
            prompt for hit/stand.
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation
#include <string>      //String Library
#include <vector>      //Vector Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
bool decide(char);
int calcHnd(int&);
void prntCrd(int&, int, string, string, string, string);

//void prntCrd(int, int, string, string, string, string);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    const int SIZE = 4;     //4 Players
    int card1, card2, card3, card4, cardOne, cardTwo, cardThree,
        cardFour = 0; //Distributed cards for player and dealer
                      //Variables with digits are for players
    int tenVal;   //Cards valued at 10
    char choice;  //Would you like to play?
    string king,  
           queen,
           jack,
           ten;
    char choices[SIZE];
    
    //Initialize variables
    
    vector<int> bets(SIZE); //4 players bet
    int bet;
    int dSum = 0; //Dealer sum (hand value)
    int sumPlyr[SIZE] = {0, 0, 0, 0};
    int valid = 0;
    king = "KING",   //King card
    queen = "QUEEN", //Queen card
    jack = "JACK",   //Jack card
    ten = "TEN";     //Ten card
    
    //Process, map inputs to outputs
    //Validate option to play or not
    do{
        cout << "Would you four ladies and gents like to play BLACKJACK? "
             << "(y or n)\n";
        cin >> choice;
        if(decide(choice)){
            valid++;
        }
    }while(valid < 1);
    
    //Prompt players to bet after sitting at table
    cout << "Take a seat happy gamblers! Each player, PLACE YOUR BETS.\n";
    cout << "Only whole bills are allowed, no coins or change.\n";
    for (int k = 0; k < SIZE; k++){
        cin >> bet; 
        bets[k] = bet;
        cout << fixed << setprecision(2) << showpoint;
        cout << "Player " << k+1 << " placed a bet of $"
             << static_cast<float>(bets[k])<<endl; 
        cout << "-------------------------------------------\n";
    }
    
    //Player receives first two cards
    for(int i = 0; i < SIZE; i++){
        calcHnd(card1); //Player's first card
        calcHnd(card2); //Player's second card
        
        cout << "Player " << i + 1 << " your first card is"; 
        prntCrd(card1, tenVal, queen, jack, king, ten); 
        cout << endl;
        
        cout << "Player " << i + 1 << " your second card is"; 
        prntCrd(card2, tenVal, queen, jack, king, ten); 
        cout << endl;
        
        sumPlyr[i] = card1 + card2;  
        cout << "Hand total: " << sumPlyr[i] << "\n\n";
    }
  
    //Calculate first two cards for dealer (one face down)
    calcHnd(cardOne);
    calcHnd(cardTwo);
    
    dSum = cardOne + cardTwo;
    
    cout << "The dealer received his or her first card, "; 
    prntCrd(cardOne, tenVal, queen, jack, king, ten); 
    cout << endl;
    cout << "Dealer's second card is disclosed until each player decides to hit"
         << " or stand.\n\n";
    
    //Prompt player to stand with current hand or get a third card
    cout << "Would you like to stand, or hit again? Type(s for stand "
         <<   "or h for hit)\n\n";
        
    //Assign choice (s for stand/h for hit) to each player
    for(int x = 0; x < SIZE; x++){
        cin >> choice; 
        choices[x] = choice;
        cout << "Player "<< x+1 << " decided: " << choices[x] << endl; 
        cout << "----------------------------\n";
    }
    cout << endl;
    
    //Player operations for a stand or hit
    for(int x = 0; x < SIZE; x++){
        if(choices[x] == 's' || choices[x] == 'S'){
            cout << "Player " << x + 1 << " you stand with the hand valued: "
                 << sumPlyr[x] << "\n---------------------------------------\n";  
        } 
        if(choices[x] == 'h' || choices[x] == 'H'){
            calcHnd(card3);
            cout << "Player " << x + 1 << " your third card is";
            prntCrd(card3, tenVal, queen, jack, king, ten); 
            cout << endl;
            sumPlyr[x] += card3;
            cout << "Player " << x + 1 << " you stand with the hand valued: "
                 << sumPlyr[x] << "\n---------------------------------------\n";
        }
    }        
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

//Validate desire to play
bool decide(char x){
    if(x == 'n' || x == 'N'){
        return false;
    }
    else if(x == 'y' || x == 'Y'){
        return true;
    }
    else{
        cout << "Invalid input. (Y for yes or N for no)\n";
        return false;
    }
}

//Calculate the card and sum for a player or dealer
int calcHnd(int &x){
    //Calculate card for player or dealer
    x = rand()%10+1;  //[1, 10]
    return x;
}

//Print card with English instead of digit value
void prntCrd(int &x, int tenVal, string queen, string jack, string king, 
             string ten){
    //Name card type
    switch(x){
        case 1: cout << " a ONE\n";break;
        case 2: cout << " a TWO\n";break;
        case 3: cout << " a THREE\n";break;
        case 4: cout << " a FOUR\n";break;
        case 5: cout << " a FIVE\n";break;
        case 6: cout << " a SIX\n";break;
        case 7: cout << " a SEVEN\n";break;
        case 8: cout << " an EIGHT\n";break;
        case 9: cout << " a NINE\n";break;
        case 10: //Special case - cards with value 10
            if(x == 10){
                tenVal = rand()%4+1;
                switch(tenVal){
                    case 1: cout << " is a " << queen << endl;break;
                    case 2: cout << " is a " << jack << endl;break;
                    case 3: cout << " is a " << king << endl;break;
                    case 4: cout << " is a " << ten << endl;break;
                }
            }break;        
    }
}
