/*Stephen Anderson
  Purpose: To play blackjack without losing real money (well, you shouldn't lose any real money...)
*/

//Declare Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

//No Global Constants

//Function Prototypes
int drawcard(int [], int);
int moneyandbet(int);
void reshuffle(int[], int);
void printcard(int);
bool drawlegal(int, int[], int);
int acechoice(int);
int correctfacecard(int);
char askplayerchoice(int, int, int, int [], int[], int);
int hit(int, int [], int);
int dealerai (int [], int[], int, int [], int);


//Begin execution
int main(){
    //Begin Random Number Generator
    srand(time(0));
    //Declare Variables
    int playerhand [2]; //Array that holds the cards in the players starting hand
    int splithand[2]; //Array that holds a players hand in the event of a split
    int dealerhand [2]; //Array that holds the cards in the dealers starting hand
    int cardcount [13] = {4,4,4,4,4,4,4,4,4,4,4,4,4}; //Array that holds all the cards in the deck and manages how many cards exist
    int decks; //Controls how many decks are being played
	int money = 100; //How much money the player has, starts at 100 and changes in run-time
    int bet; //The bet the player makes through the moneyandbet function
    int total; //The total of the player's hand
    int dtotal; //The total of the dealer's hand
    char playerchoice; //The players choice to hit, stay or double down as returned from the askplayerchoice function
    bool replay = false; //Used to rerun program from beginning if player wants to play another hand
    bool loop = false; //Used to determine if hitting can be done more than once after the askplayerchoice function
	bool correct; //Used to make sure bool choice is a valid option and loops if it isn't
	char choice; //Used by the user to answer yes or no
	bool split = false; //Used to determine if a split is possible or not
	string line; //For reading from saved scores
    
    //Begin game, ask for bet
    cout << "         _     _  _______  ___      ______  _______  __   __  _______  " << endl  
    	 << "        | | _ | ||       ||   |    |      ||       ||  |_|  ||       |" << endl   
    	 << "        | || || ||    ___||   |    |      ||   _   ||       ||    ___| " << endl      
    	 << "        |       ||   |___ |   |    |      ||  | |  ||       ||   |" << endl
		 << "        |       ||    ___||   |___ |     _||  |_|  ||       ||    ___| " << endl
		 << "        |   _   ||   |___ |       ||    |_ |       || ||_|| ||   | " << endl
		 << "        |__| |__||_______||_______||______||_______||_|   |_||_______| " << endl << endl
		 << "                              _______  _______ " << endl
		 << "                             |       ||       | " << endl
		 << "                             |_     _||   _   | " << endl
		 << "                               |   |  |  | |  | " << endl
		 << "                               |   |  |  |_|  | " << endl
		 << "                               |   |  |       | " << endl
		 << "                               |___|  |_______| " << endl << endl
		 << " _______  ___      _______  ______  ___   _      ___  _______  ______  ___   _  " 
		 << "|  _    ||   |    |   _   ||      ||   | | |    |   ||   _   ||      ||   | | | " 
		 << "| |_|   ||   |    |  |_|  ||      ||   |_| |    |   ||  |_|  ||      ||   |_| | "
		 << "|       ||   |    |       ||      ||      _|    |   ||       ||      ||      _| " 
		 << "|  _   | |   |___ |       ||     _||     |_  ___|   ||       ||     _||     |_  " 
		 << "| |_|   ||       ||   _   ||    |_ |    _  ||       ||   _   ||    |_ |    _  | " 
		 << "|_______||_______||__| |__||______||___| |_||_______||__| |__||______||___| |_| " << endl;
	cout << endl << "Would you like to view your saved scores? (Y/N)" << endl;
	do{
		cin >> choice;
		correct = true;
		if(choice == 'Y' || choice == 'y'){
			ifstream myfile ("savedscores.txt");
  			if (myfile.is_open()){
   				while (getline (myfile,line)){
      			cout << "$" << line << endl;
    			}
    			cout << endl;
    			myfile.close();
  			}
			else{
                cout << "Unable to open file" << endl << endl;
            }
		}
		else if(choice == 'N' || choice == 'n'){
			cout << endl;
		}
		else{
			cout << endl << "Please enter either Y or N to make a choice." << endl;
			correct = false;
		}
	}while (correct == false);
	
	cout << "We will start by giving you some money to gamble with!" << endl;
		 

	cout << endl << "How many decks would you like to play with? (1-5)" << endl;
	do{
		correct = true;
		cin >> decks;
		if(decks <1 || decks > 5){
			cout << endl << "Please enter a number between 1 and 5." << endl;
			correct = false;
		}
		else{
			for(int i = 0; i < 13; ++i)cardcount[i] = 4 * decks;
		}
				 
	}while (correct == false);
	
	do{
		bet = moneyandbet(money);
		split = false;
		
	    playerhand [0] = drawcard(cardcount, decks);
	    playerhand [1] = drawcard(cardcount, decks);
	    cout << endl << "You drew"; 
	    printcard(playerhand [0]); 
	    cout << "and";
	    printcard(playerhand [1]);
	    cout << endl;
	    
	    if(playerhand[0] == playerhand[1] && bet * 2 <= money){
	    	cout << endl << "Would you like to split? (Y/N)" << endl;
	    	do{
	    		correct = true;
	    		split = false;
	    		cin >> choice;
	    		if(choice == 'Y' || choice == 'y') split = true;
				else if(choice == 'N' || choice == 'n') split = false;
				else{
					cout << endl << "Please enter either Y or N to make a choice." << endl;
					correct = false;
				}
	    	}while (correct == false);
		    if(split == true){
				splithand[0] = playerhand [1];
		    	playerhand [1] = drawcard(cardcount, decks);
		    	splithand [1] = drawcard(cardcount, decks);
		    	
		    	cout << endl << "Your first hand is";
		    	printcard(playerhand[0]);
		    	cout << "and";
		    	printcard(playerhand[1]);
		    	if(playerhand [0] >= 11) playerhand [0] = correctfacecard(playerhand [0]);
		    	if(playerhand [1] >= 11) playerhand [1] = correctfacecard(playerhand [1]);
		    	if(playerhand [0] == 1) playerhand [0] = acechoice(playerhand [0]);
		    	if(playerhand [1] == 1) playerhand [1] = acechoice(playerhand [1]);
		    	total = playerhand [0] + playerhand [1];
		    	cout << endl << "Your total is " << total << "." << endl;
		    	cout << endl << "We'll play your first hand first." << endl;
		    	//Asks player to decide what to do from appropriate options and loops when needed.
		  	    if(total < 21){
			  	  do{
			    		loop = false;
				    	playerchoice = askplayerchoice(total, bet, money, playerhand, cardcount, decks);
				  	  if     (playerchoice == 'H' || playerchoice == 'h'){
				   	 	total = hit(total, cardcount, decks);
				    	if(total < 21)loop = true;
					    }
			
					    else if(playerchoice == 'S' || playerchoice == 's'){
					        loop = false;
					    }
				    
					    else if(playerchoice == 'D' || playerchoice == 'd'){
					    	bet *= 2;
					    	total = hit(total, cardcount, decks);
					    	loop = false;
					    }
					if(total > 21)cout << endl << "You bust!" << endl;
					}while (loop == true);
				}
		    	
				cout << endl << endl << "Your second hand is";
		    	printcard(splithand[0]);
		    	cout << "and";
		    	printcard(splithand[1]);
		    	if(splithand [0] >= 11) splithand [0] = correctfacecard(splithand [0]);
		    	if(splithand [1] >= 11) splithand [1] = correctfacecard(splithand [1]);
		    	if(splithand [0] == 1) splithand [0] = acechoice(splithand [0]);
		    	if(splithand [1] == 1) splithand [1] = acechoice(splithand [1]);
		    	total = splithand [0] + splithand [1];
		    	cout << endl << "Your total is " << total << "." << endl;
		    	cout << "Now we will play your second hand." << endl;
		    	
		    	//Asks player to decide what to do from appropriate options and loops when needed.
		  	    if(total < 21){
			  	  do{
			    		loop = false;
				    	playerchoice = askplayerchoice(total, bet, money, splithand, cardcount, decks);
				  	  if     (playerchoice == 'H' || playerchoice == 'h'){
				   	 	total = hit(total, cardcount, decks);
				    	if(total < 21)loop = true;
					    }
			
					    else if(playerchoice == 'S' || playerchoice == 's'){
					        loop = false;
					    }
				    
					    else if(playerchoice == 'D' || playerchoice == 'd'){
					    	bet *= 2;
					    	total = hit(total, cardcount, decks);
					    	loop = false;
					    }
					if(total > 21)cout << endl << "You bust!" << endl;
					}while (loop == true);
				}
		    }
		}
	    
	    
	if(split == false){
		//Begin ace choice and face card fixing
	    if(playerhand [0] >= 11) playerhand [0] = correctfacecard(playerhand [0]);
	    if(playerhand [1] >= 11) playerhand [1] = correctfacecard(playerhand [1]);
	    if(playerhand [0] == 1) playerhand [0] = acechoice(playerhand [0]);
	    if(playerhand [1] == 1) playerhand [1] = acechoice(playerhand [1]);
	    total = playerhand [0] + playerhand [1];
	    cout << "Your total is " << total << "." << endl;
	    
		//Dealer starts here
	    dealerhand [0] = drawcard(cardcount, decks);
	    dealerhand [1] = drawcard(cardcount, decks);
	    cout << endl << "The dealer drew";
	    printcard(dealerhand [0]);
	    cout << "and another card." << endl;   
		    
	    //Asks player to decide what to do from appropriate options and loops when needed.
	    if(total < 21){
		    do{
		    	loop = false;
			    playerchoice = askplayerchoice(total, bet, money, playerhand, cardcount, decks);
			    if     (playerchoice == 'H' || playerchoice == 'h'){
			    	total = hit(total, cardcount, decks);
			    	if(total < 21)loop = true;
			    }
		
			    else if(playerchoice == 'S' || playerchoice == 's'){
			        loop = false;
			    }
			    
			    else if(playerchoice == 'D' || playerchoice == 'd'){
			    	bet *= 2;
			    	total = hit(total, cardcount, decks);
			    	loop = false;
			    }
			if(total > 21)cout << endl << "You bust!" << endl;
			}while (loop == true);
		}
    }
		//Dealer continues with AI
		cout << endl << "The dealer reveals that he has";
		printcard(dealerhand [0]);
		cout << "and";
		printcard(dealerhand [1]);
		dtotal = dealerai(dealerhand, cardcount, decks, playerhand, total);
		
		if(total == playerhand[0] + playerhand [1] && total == 21 && dtotal != 21){
			bet *= 2;
			cout << endl << endl << "Congratulations! You got a Blackjack! You won twice your bet, so you recieve $" << bet << " for winning!" << endl;
			money += bet;
		}
		
		else if((total > dtotal && total < 22) || (dtotal > 21 && total <= 21)){
			if(dtotal > 21)cout << "The dealer busts!" << endl;
			cout << endl << endl << "Congratulations! You won! You recieve $" << bet << "." << endl;
			money += bet;
		}
		else if((dtotal > total && dtotal < 22) || (total > 21 && dtotal < 22)){
			cout << endl << endl << "Sorry, you lost. You lose $" << bet << "." << endl;
			money -= bet;
		}
		else if (total == dtotal){
			cout << endl << endl << "It's a push. You are returned your bet of $" << bet << "." << endl;
			bet = 0;	
		}
		if(split == true){
			if(total == splithand[0] + splithand [1] && total == 21 && dtotal != 21){
				bet *= 2;
				cout << endl << endl << "Congratulations! You got a Blackjack! You won twice your bet, so you recieve $" << bet << " for winning!" << endl;
				money += bet;
			}
			
			else if((total > dtotal && total < 22) || (dtotal > 21 && total <= 21)){
				if(dtotal > 21)cout << "The dealer busts!" << endl;
				cout << endl << endl << "Congratulations! You won! You recieve $" << bet << "." << endl;
				money += bet;
			}
			else if((dtotal > total && dtotal < 22) || (total > 21 && dtotal < 22)){
				cout << endl << endl << "Sorry, you lost. You lose $" << bet << "." << endl;
				money -= bet;
			}
			else if (total == dtotal){
				cout << endl << endl << "It's a push. You are returned your bet of $" << bet << "." << endl;
				bet = 0;	
			}
				
			}
	if(money > 0){
		cout << endl << endl << "Would you like to play another hand? (Y/N)" << endl;
		do{
			cin >> choice;
			correct = true;
			if(choice == 'Y' || choice == 'y') replay = true;
			else if(choice == 'N' || choice == 'n'){
				replay = false;
				cout << endl << endl << "Would you like to save your score to a file? (Y/N)" << endl;
				do{
					cin >> choice;
					correct = true;
					if(choice == 'Y' || choice == 'y'){
						ofstream myfile ("savedscores.txt");
  							if (myfile.is_open()){
    							myfile << money << endl;
    							myfile.close();
    						}
  							else{
  								 cout << "Unable to open file"; 
  							}
					}
					else if(choice == 'N' || choice == 'n'){
						cout << endl << "Have a nice day!";
					}
					else{
						cout << endl << "Please enter either Y or N to make a choice." << endl;
						correct = false;
					}
				}while (correct == false);
			}
			else{
				cout << endl << "Please enter either Y or N to make a choice." << endl;
				correct = false;
			}
		}while (correct == false);
	}
	else{
		cout << endl << endl << "Uh oh! You're all out of money!" << endl << "If you'd like more, simply make payments of $100 to Stephen Anderson." << endl;
		replay = false;
	}
}while (replay == true);
    
system("PAUSE");
return 0;
}

//Draws a card
int drawcard(int cardcount[], int decks){
    int card;
    bool cardexists = true;
    card = (rand() % 13 + 1);
    do{
        cardexists = true;
        cardexists = drawlegal(card, cardcount, decks);
        }while (cardexists = false);
    cardcount[card -1] -= 1;
    return card;
}


//Prompts the user to input a bet and check if it is a legal bet to make
int moneyandbet(int money){
    cout << "You currently have $" << money << " to spend.\nHow much would you like to bet? (Please enter a whole number)\n$";
    int bet = 0;
    bool betcorrect = true;
    cin >> bet;
    do{
        betcorrect = true;
        //If they make an illegal bet
        if(bet < 0){
        	betcorrect = false;
        	cout << endl << "You cannot bet a negative number. Please enter a positive amount." << endl;	
        	cin >> bet;
        }
        else if(bet == 0){
        	betcorrect = false;
        	cout << endl << "You must enter a bet. Please enter an amount." << endl;
        	cin >> bet;
        }
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
bool drawlegal(int card, int cardcount[], int decks){
    bool exists = true;
    int total = 0;
    for(int i = 0; i < 13; ++i)total += cardcount[i];
    if(cardcount[card - 1] <= 0){
        exists = false;
    }
    if(total <= 5)reshuffle(cardcount, decks);
    return exists;
}
    
//Reshuffles the deck by making all cardcount values 4
void reshuffle(int cardcount[],int decks){
    cout << endl << "We need to reshuffle the deck." << endl;
    for(int i = 0; i < 13; ++i){
        cardcount[i] = (4 * decks);
    }
}
    
//For choosing the value of an ace, if drawn.
int acechoice(int card){
    bool choice = true;
    int x;
        if(card == 1){
            cout << endl << "Would you like your Ace to be a 1 or an 11?" << endl;
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

//Prompts player to make a choice to either hit, stay or, if possible, double down
char askplayerchoice(int total, int bet, int money, int card[], int cardcount[],int decks){
    bool correct = true;
    char playerchoice;
    if(total == card [0] + card [1] && bet * 2 <= money){
        cout << endl << "Would you like to hit, stay or double down? \n(Type H to hit, S to stay and D to double down)" << endl;
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
        return playerchoice;
    }
    else{
	    cout << endl << "Would you like to hit or stay? \n(Type H to hit or S to stay)" << endl;
	    do{
	        correct = true;
	        cin >> playerchoice;
	        if(playerchoice != 'H' && playerchoice != 'h' &&
	            playerchoice != 'S' && playerchoice != 's'){
	                correct = false;
	                cout << endl << "Please enter either H or S" << endl;
	        }
	    }while (correct == false);
    	return playerchoice;
    }
}

//Used if player chooses to hit. Draws a card and adds it to the current hand total.
int hit(int total, int cardcount [],int decks){
	int drawncard = 0;
    drawncard = drawcard(cardcount, decks);
    cout << endl << "You drew";
    printcard(drawncard);
    if(drawncard >= 11) drawncard = correctfacecard(drawncard);
    if(drawncard == 1) drawncard = acechoice(drawncard);
    total += drawncard;
    cout << endl << "Your total is " << total << endl;
    return total;
}

//Controls the dealer's decisions in different situations
int dealerai(int hand[], int cardcount [], int decks, int playerhand [], int ptotal){
	//If either of the dealers cards is a face card
	if(hand [0] >= 11) hand [0] = correctfacecard(hand[0]);
	if(hand [1] >= 11) hand [1] = correctfacecard(hand[1]);
	//If either the dealer has any aces
	if(hand [0] == 1 && hand [1] == 1){
		hand [0] = 1;
		hand [1] = 11;
	}
	else if(hand [0] == 1){
		if(hand [1] >= 7)hand[0] = 11;
	}
	else if(hand [1] == 1){
		if(hand [0] >= 7)hand[1] = 11;
	}
	
	int card; //For storign drawn cards to add to total
	int total = hand[0] + hand[1];
	cout << "for a total of " << total << endl;
	if(ptotal == playerhand [0] + playerhand [1] && ptotal == 21 && total != 21)return total;
	else{
		if(ptotal <= 21){
			for(; total < 17;){
				card = 0;
				card = drawcard(cardcount, decks);
				cout << "The dealer drew";
				printcard(card);
				cout << "for a total of ";
				if(card >= 11) card = correctfacecard(card);
				
				else if(card == 1 && total <= 10 && total >= 7)card = 11;
				else if(card == 1 && total > 10 && total < 7)card = 1;
				total += card;
				cout << total << endl;
			}
		}
	}
return total;
}

