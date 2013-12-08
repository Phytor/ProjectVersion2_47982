/*Stephen Anderson
  Purpose: To play blackjack without losing real money
*/

//Declare Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//No Global Constants

//Function Prototypes
int drawcard(int []);
int moneyandbet(int);
void reshuffle(int[]);
void printcard(int);
bool drawlegal(int, int[]);
int acechoice(int);
int correctfacecard(int);
void askplayerchoice(int, int, int, int [], int[]);
void hit(int []);
void doubledown(int, int, int[]);


//Begin execution
int main(){
    //Begin Random Number Generator
    srand(time(0));
    //Declare Variables
    int playerhand [2];
    int dealerhand [2];
    int cardcount [13] = {4,4,4,4,4,4,4,4,4,4,4,4,4};
    int money = 100;
    int bet;
    int total;
    char playerchoice;
    
    //Begin game, ask for bet
    cout << "Welcome to Blackjack! To start, we will give you some money to gamble with.\n";
    bet = moneyandbet(money);
    playerhand [0] = drawcard(cardcount);
    playerhand [1] = drawcard(cardcount);
    cout << endl << "You drew"; 
    printcard(playerhand [0]); 
    cout << "and";
    printcard(playerhand [1]);
    cout << endl;
    
    //Begin ace choice and face card fixing
    if(playerhand [0] >= 11) playerhand [0] = correctfacecard(playerhand [1]);
    if(playerhand [1] >= 11) playerhand [1] = correctfacecard(playerhand [1]);
    if(playerhand [0] == 1) playerhand [0] = acechoice(playerhand [0]);
    if(playerhand [1] == 1) playerhand [1] = acechoice(playerhand [1]);
    total = playerhand [0] + playerhand [1];
    cout << "Your total is " << total << "." << endl;
    
    //Dealer starts here
    dealerhand [0] = drawcard(cardcount);
    dealerhand [1] = drawcard(cardcount);
    cout << endl << "The dealer drew";
    printcard(dealerhand [0]);
    cout << "and another card." << endl;
    
    askplayerchoice(total, bet, money, playerhand, cardcount);
    

    
system("PAUSE");
return 0;
}

//Draws a card
int drawcard(int cardcount[]){
    int card;
    bool cardexists = true;
    card = (rand() % 13 + 1);
    do{
        cardexists = true;
        cardexists = drawlegal(card, cardcount);
        }while (cardexists = false);
    cardcount[card -1] -= 1;
    return card;
}


//Prompts the user to input a bet and check if it is a legal bet to make
int moneyandbet(int money){
    cout << "You currently have $" << money << " to spend.\nHow much would you like to bet?\n$";
    int bet;
    bool betcorrect = true;
    cin >> bet;
    do{
        betcorrect = true;
        //If they make an illegal bet
        if(bet > money){
            betcorrect = false;
            cout << endl << "You don't have that much money, please enter a new amount that is under $" << money + 1 << endl;
            cin >> bet; 
        }
    
    }while (betcorrect == false);
    return bet;
}

//States card drawn with correct grammar and names face cards correctly
void printcard(int card){
    if(card == 1) cout << " an Ace ";
    if(card == 2) cout << " a 2 ";
    if(card == 3) cout << " a 3 ";
    if(card == 4) cout << " a 4 ";
    if(card == 5) cout << " a 5 ";
    if(card == 6) cout << " a 6 ";
    if(card == 7) cout << " a 7 ";
    if(card == 8) cout << " an 8 ";
    if(card == 9) cout << " a 9 ";
    if(card == 10) cout << " a 10 ";
    if(card == 11) cout << " a Jack ";
    if(card == 12) cout << " a Queen ";
    if(card == 13) cout << " a King ";
}

//Checks to see if the randomly generated card is in the deck, and if it isn't, returns a bool to the drawcard function. Also checks to see if deck should be shuffled.
bool drawlegal(int card, int cardcount[]){
    bool exists = true;
    int total = 0;
    for(int i = 0; i < 13; ++i)total += cardcount[i];
    if(cardcount[card - 1] <= 0){
        exists = false;
    }
    if(total <= 5)reshuffle(cardcount);
    return exists;
}
    
//Reshuffles the deck by making all cardcount values 4
void reshuffle(int cardcount[]){
    cout << endl << "We need to reshuffle the deck." << endl;
    for(int i = 0; i < 13; ++i){
        cardcount[i] = 4;
    }
}
    
//For choosing the value of an ace, if drawn.
int acechoice(int card){
    bool choice = true;
    int x;
        if(card == 1){
            cout << "Would you like your Ace to be a 1 or an 11?" << endl;
            cin >> x;
            do{
                choice = true;
                if(x != 1 && x != 11){
                    choice = false;
                    cout << endl << "Please enter either a 1 or an 11" << endl;
                    cin >> x;
                }
            }while (choice == false);
            card = x;
        }
    return card;
}
    
//Corrects the value of non-Ace facecards
int correctfacecard(int card){
        if(card >= 11)card = 10;
    return card;
}

void askplayerchoice(int total, int bet, int money, int card[], int cardcount[]){
    bool correct = true;
    char playerchoice;
    int drawncard; //Used for temporarily storying drawn cards for use in other functions
    if(total == card [0] + card [1] && bet * 2 <= money){
        cout << "Would you like to hit, stay or double down? \n(Type H to hit, S to stay and D to double down)" << endl;
        do{
            correct = true;
            cin >> playerchoice;
            if(playerchoice != 'H' && playerchoice != 'h' &&
                playerchoice != 'S' && playerchoice != 's' &&
                playerchoice != 'D' && playerchoice != 'd'){
                    correct = false;
                    cout << endl << "Please enter either H, S, or D." << endl;
                }
            }while (correct == false);
        }
        else{
            cout << "Would you like to hit or stay? \n(Type H to hit or S to stay)" << endl;
            do{
                correct = true;
                cin >> playerchoice;
                if(playerchoice != 'H' && playerchoice != 'h' &&
                   playerchoice != 'S' && playerchoice != 's'){
                        correct = false;
                        cout << endl << "Please enter either H or S" << endl;
                    }
                }while (correct == false);
            }
    if     (playerchoice == 'H' || playerchoice == 'h'){
        drawncard = 0;
        drawncard = drawcard(cardcount);
        cout << endl << "You drew";
        printcard(drawncard);
        if(drawncard >= 11) drawncard = correctfacecard(drawncard);
        if(drawncard == 1) drawncard = acechoice(drawncard);
        total += drawncard;
        cout << endl << "Your total is " << total << endl;
        
    }
    else if(playerchoice == 'S' || playerchoice == 's'){
        
    }
    else if(playerchoice == 'D' || playerchoice == 'd');{
        
    }
}

//YOU LEFT OFF HERE

//void hit(int total, int card[]){
    
    
    
    

















