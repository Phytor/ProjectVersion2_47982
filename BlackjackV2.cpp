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
void acechoice(int []);
void correctfacecard(int []);
void askplayerchoice(int, int, int, int []);
void choicesplit(char, int []);
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
    bool correct = true;
    
    //Begin game, ask for bet
    cout << "Welcome to Blackjack! To start, we will give you some money to gamble with.\n";
    bet = moneyandbet(money);
    do{
        correct = true;
        playerhand [0] = drawcard(cardcount);
        correct = drawlegal(playerhand [1],cardcount);
    }while (correct == false);
    do{
        correct = true;
        correct = playerhand [1] = drawcard(cardcount);
    }while (correct == false);
    cout << endl << "You drew"; 
    printcard(playerhand [0]); 
    cout << "and";
    printcard(playerhand [1]);
    cout << endl;
    if(playerhand [0] >= 11 || playerhand [1] >= 11) correctfacecard (playerhand);
    if(playerhand [0] == 1 || playerhand [1] == 1) acechoice (playerhand);
    total = playerhand[0] + playerhand [1];
    cout << "Your total is " << total << "." << endl;
    
    //Dealer starts here
    
    askplayerchoice(total, bet, money, playerhand);
    
system("PAUSE");
return 0;
}

//Draws a card
int drawcard(int cardcount[]){
    int card;
    int counttotal;
    bool cardexists = true;
    card = (rand() % 13 + 1);
    do{
        cardexists = true;
        cardexists = drawlegal(card, cardcount);
        if( counttotal < 5){
            reshuffle(cardcount);
            }
        } while (cardexists = false);
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

//Checks to see if the randomly generated card is in the deck, and if it isn't, returns a bool to draw another card from the drawcard function
bool drawlegal(int card, int cardcount[]){
    bool exists = true;
    if(cardcount[card] <= 0){
        exists = false;
    }
    return exists;
}
    
    
void reshuffle(int cardcount[]){
    for(int i = 0; i < 13; ++i){
        cardcount[i] = 4;
    }
}
    
//For choosing the value of an ace, if drawn.
void acechoice(int card []){
    bool choice = true;
    int x;
    for(int i = 0; i < 2; ++i){
        if(card [i] == 1){
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
            card[i] = x;
        }
    }
}
    
//Corrects the value of fnon-Ace facecards
void correctfacecard(int card []){
    for(int i = 0; i < 2; ++i){
        if(card [i] >= 11)card[i] = 10;
    }
}

void askplayerchoice(int total, int bet, int money, int card[]){
    bool correct = true;
    char playerchoice;
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
    choicesplit(playerchoice, card[]);
}

//YOU LEFT OFF HERE

//Takes the users choice and splits it up through the 3 different functions    
void choicesplit(char choice, int card[]){
    if(choice == 'H' || choice == 'h')
    if(choice == 'S' || choice == 's')
    if(choice == 'D' || choice == 'd')
}

void hit(int card[]){
    
    
    

















