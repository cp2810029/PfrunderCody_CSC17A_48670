/*
    Author: Cody Pfrunder
    Date:   October 30, 2021
    Purpose:Blackjack Game - Basic version w/out checklist incorporation
            Version 4: Creating a static structure!
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Input/Output Manipulation
#include <string>      //String Library
#include <vector>      //Vector Library
using namespace std;   //Library Name-space

//User Libraries
const int SIZE = 81; //Only way to size a static char array in structure.
struct PlayerDat{
    char choices[SIZE];
    int bet;
    int sumPlyr[4];
};
//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
bool decide(char);
int calcHnd(int&);
void prntCrd(int&, int, string, string, string, string);
void ptReslt(int [], int, vector<int> &, int, const float);

//void prntCrd(int, int, string, string, string, string);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    const int SIZE = 4;      //4 Players
    PlayerDat plyInfo[SIZE]; //Static Array of structures
    int card1, card2, card3, card4, card5, cardOne, cardTwo, cardThree,
        cardFour, cardFive = 0; //Distributed cards for player and dealer
                                //Variables with digits are for players
    int tenVal;   //Cards valued at 10
    char choice;  //Would you like to play?
    string king,  
           queen,
           jack,
           ten;
    char choices[SIZE];
    
    //Initialize variables
    const float BLACKJACK = 1.25; //Pay increase for a blackjack
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
    cout << "Would you like to stand, or hit again? Type(s/S for stand "
         << "or h/H for hit)\n\n";
        
    //Assign choice (s for stand/h for hit) to each player
    for(int x = 0; x < SIZE; x++){
        cin >> choice; 
        choices[x] = choice;
        cout << "Player "<< x+1 << " decided: " << choices[x] << endl; 
        cout << "----------------------------\n";
    }
    cout << endl;
    
    //Player operations for a stand or hit up to a fifth card
    for(int x = 0; x < SIZE; x++){
        //Stand with two cards
        if(choices[x] == 's' || choices[x] == 'S'){
            cout << "Player " << x + 1 << " you stand with the hand valued: "
                 << sumPlyr[x] << "\n---------------------------------------\n";  
        } 
        //Hit for a third card
        else if(choices[x] == 'h' || choices[x] == 'H'){
            calcHnd(card3);
            cout << "Player " << x + 1 << " your third card is";
            prntCrd(card3, tenVal, queen, jack, king, ten); 
            cout << endl;
            sumPlyr[x] += card3;
            cout << "Player " << x + 1 << " you hold the hand valued: "
                 << sumPlyr[x] << "\n";
            //Prompt to hit or stand after receiving third card
            cout << "Would you like to stand, or hit again? Type(s/S for stand "
                 << "or h/H for hit)\n\n";
            cin >> choice; 
            choices[x] = choice;
            //Stand with three cards
            if(choices[x] == 's' || choices[x] == 'S'){
            cout << "Player " << x + 1 << " you stand with the hand valued: "
                 << sumPlyr[x] << "\n---------------------------------------\n";  
            }
            //Hit for a fourth card
            else if(choices[x] == 'h' || choices[x] == 'H'){
                calcHnd(card4);
                cout << "Player " << x + 1 << " your fourth card is";
                prntCrd(card4, tenVal, queen, jack, king, ten); 
                cout << endl;
                sumPlyr[x] += card4;
                cout << "Player " << x + 1 << " you hold the hand valued: "
                     << sumPlyr[x] << "\n";
                //Prompt to hit or stand after receiving fourth card
                cout << "Would you like to stand, or hit again? Type(s/S for stand "
                     << "or h/H for hit)\n\n";
                cin >> choice; 
                choices[x] = choice;
                //Stand with four cards
                if(choices[x] == 's' || choices[x] == 'S'){
                    cout << "Player " << x + 1 
                         << " you stand with the hand valued: "
                         << sumPlyr[x] 
                         << "\n---------------------------------------\n";  
                }
                //Hit for a fifth card
                else if(choices[x] == 'h' || choices[x] == 'H'){
                    calcHnd(card5);
                    cout << "Player " << x + 1 << " your fifth card is";
                    prntCrd(card5, tenVal, queen, jack, king, ten); 
                    cout << endl;
                    sumPlyr[x] += card5;
                    cout << "Player " << x + 1 
                         << " you hold the hand valued: "
                         << sumPlyr[x] 
                         << "\n---------------------------------------\n";
                }
            }
        }
    }
    
    //Dealer hand
    cout << "The dealers revealed card was a ";
    prntCrd(cardOne, tenVal, queen, jack, king, ten);
    cout << endl << "The dealers second card is a ";
    prntCrd(cardTwo, tenVal, queen, jack, king, ten);
    cout << endl;
    if(dSum < 17){
        calcHnd(cardThree);
        cout << "The dealers third card is";
        prntCrd(cardThree, tenVal, queen, jack, king, ten);
        cout << endl;
        dSum += cardThree;
    }
    if(dSum < 17){
        calcHnd(cardFour);
        cout << "The dealers fourth card is";
        prntCrd(cardFour, tenVal, queen, jack, king, ten);
        cout << endl;
        dSum += cardFour;
    }
    if(dSum < 17){
        calcHnd(cardFive);
        cout << "The dealers fifth card is";
        prntCrd(cardFive, tenVal, queen, jack, king, ten);
        cout << endl;
        dSum += cardFive;
    }
    cout << endl << endl;
    
    //Display your initial conditions as well as outputs.
    //Print results
    for(int k = 0; k < SIZE; k++){
        ptReslt(sumPlyr, dSum, bets, k, BLACKJACK);
    }
    
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

//Print final winning/losing results
void ptReslt(int sumPlyr[], int dSum, vector<int> &bets, int k, 
        const float BLACKJACK){
    cout << "Player " << k + 1 <<": \n";
    //Dealer wins by greater
    if(dSum > sumPlyr[k] && dSum < 21){
        cout << "You lose...\n";
        cout << "Dealer wins with value of " << dSum <<".\n\n";
    }
    //Player bust
    else if(sumPlyr[k] > 21 && dSum <= 21){
        cout << "Your hand holds the total value: " << sumPlyr[k] << ".\n";
        cout << "You lose with a busted hand. Dealer wins.\n\n";
    }
    //Dealer bust
    else if(dSum > 21 && sumPlyr[k] < 21){
        cout << "Dealer has a hand with total value: " << dSum << ".\n";
        cout << "You win! the dealer busts.\n";
        bets[k] *= 2.0;
        cout << "Your winnings are: $" << bets[k] << endl << endl;
    }
    //Player and dealer have same hand
    else if(sumPlyr[k] == dSum && sumPlyr[k] <= 21){
        cout << "Dealer has a hand with total value: "<< dSum << ".\n"
             << "You and the dealer have the same hand.\n"
             << "You get your money back with no damage done!\n\n";
    }
    //Player wins
    else if(sumPlyr[k] > dSum && sumPlyr[k] < 21){
        cout << "You win!\n"
             << "Dealer has a hand with total value: "<< dSum << ".\n"
             << "Your winnings are: $" << (bets[k]*2) << endl << endl;
    }
    //Player got blackjack
    else if(sumPlyr[k] == 21 && sumPlyr[k] > dSum){
        cout << "The total value of your hand is " << sumPlyr[k] << ".\n"
             << "You got BLACKJACK!\n"
             << "Dealer has a hand with total value: " << dSum << ".\n"
             << "Because you got BLACKJACK your winnings are "
             << "increased by 1.25x.\n";
        bets[k] = bets[k] + (bets[k]*BLACKJACK);
        cout << "Your winnings are: $" << bets[k] << endl << endl;
    }
    //Player got blackjack and dealer busts
    else if(sumPlyr[k] == 21 && dSum > 21){
        cout << "The total value of your hand is " << sumPlyr[k] << ".\n"
             << "You got BLACKJACK!\n"
             << "Dealer has a hand with total value: " << dSum << ".\n"
             << "Because you got BLACKJACK your winnings are "
             << "increased by 1.25x.\n";
        bets[k] = bets[k] + (bets[k]*BLACKJACK);
        cout << "Your winnings are: $" << bets[k] << endl << endl;
    }
    //Dealer and Player got blackjack
    else if(sumPlyr[k] == 21 && dSum == 21){                                 
        cout << "The total value of your hand is " << sumPlyr[k] << ".\n";
        cout << "You and the dealer both got Blackjack!\n"
             << "You get your money back with no damage done.\n\n";
    }
    //Dealer wins by blackjack
    else if(dSum == 21 && sumPlyr[k] < dSum){
        cout << "The dealer's hand is valued " << dSum << ".\n"
             << "The dealer got BLACKJACK\n"
             << "Sorry, you lose, better luck next time.\n\n";
    }
    //Dealer and player both bust
    else if(dSum > 21 && sumPlyr[k] > 21){
        cout << "No harm done. You get your money back.\n"
             << "You hand the dealer both went bust!\n\n";
    }
}