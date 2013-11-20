//Blackjack
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;


        

int main(){
    int firstcard;
    int secondcard;
    int dfirstcard;
    int dsecondcard;
    int card; //for any drawn cards such as hits
    int total;
    int dtotal;
    int hit;
    char choice;
    int money = 100;
    int bet;
    int acechoice;
    char repeat;
    char split;
    bool drawcard = false;
    bool moneyok = true;
    bool betcorrect = true;
    bool push = false;
    bool hit2 = false;
    bool bust = false;
    bool ddraw = false;
    bool choicecorrect = true;
    bool facecard;
    bool cardexists = true;
    bool reshuffle = false;
    bool acecorrect = true;
    int count;
    int cardcount1 = 4, //For keeping track of each card in the deck
        cardcount2 = 4,
        cardcount3 = 4,
        cardcount4 = 4,
        cardcount5 = 4,
        cardcount6 = 4,
        cardcount7 = 4,
        cardcount8 = 4,
        cardcount9 = 4,
        cardcount10 = 4,
        cardcount11 = 4,
        cardcount12 = 4,
        cardcount13 = 4,
        totalcount;
        
    srand(time(0));    
    cout << "Welcome to blackjack! You will start off with $100 with which to gamble.\n";
    do{
    
    if(push == false){
    cout << "How much would you like to bet? You currently have $" << money << " to gamble with.\nYou can bet a minimum of $5 and a maximum of $50.\n";
    cout << "$";
    cin >> bet;
    }
    
    do{
    betcorrect = true;
    if(bet <5 || bet > 50 || bet > money){
        cout << endl << endl << "You cannot bet that amount. Please enter a new amount : $";
        cin >> bet;
        betcorrect = false;
    }
    
    }while(betcorrect == false);
        
        do{
        cardexists = true;
        totalcount = cardcount1 + cardcount2 + cardcount3 + cardcount4 + cardcount5 + cardcount6 + cardcount7 + cardcount8 + cardcount9 + cardcount10 + cardcount11 + cardcount12 + cardcount13;
        if(totalcount < 1){
            cout << endl << "We will reshuffle the deck" << endl << endl;
            cardcount1 = 4; 
            cardcount2 = 4;
            cardcount3 = 4;
            cardcount4 = 4;
            cardcount5 = 4;
            cardcount6 = 4;
            cardcount7 = 4;
            cardcount8 = 4;
            cardcount9 = 4;
            cardcount10 = 4;
            cardcount11 = 4;
            cardcount12 = 4;
            cardcount13 = 4;
            }
        firstcard = (rand() % 13 + 1);
        if(firstcard == 1){
            if(cardcount1 == 0){
                cardexists = false;
                }
            if(cardcount1 > 0){
            cardcount1 -= 1;
            }
            if(cardcount1 < 0)
                cardexists = false;
            }
        if(firstcard == 2){
            if(cardcount2 == 0){
                cardexists = false;
                }
            if(cardcount2 > 0){
            cardcount2 -= 1;
            }
            if(cardcount2 < 0)
                cardexists = false;
            }
        if(firstcard == 3){
            if(cardcount3 == 0){
                cardexists = false;
                }
            if(cardcount3 > 0){
            cardcount3 -= 1;
            }
            if(cardcount3 < 0)
                cardexists = false;
            }
        if(firstcard == 4){
            if(cardcount4 == 0){
                cardexists = false;
                }
            if(cardcount4 > 0){
            cardcount4 -= 1;
            }
            if(cardcount4 < 0)
                cardexists = false;
            }
        if(firstcard == 5){
            if(cardcount5 == 0){
                cardexists = false;
                }
            if(cardcount5 > 0){
            cardcount5 -= 1;
            }
            if(cardcount5 < 0)
                cardexists = false;
            }
        if(firstcard == 6){
            if(cardcount6 == 0){
                cardexists = false;
                }
            if(cardcount6 > 0){
            cardcount6 -= 1;
            }
            if(cardcount6 < 0)
                cardexists = false;
            }
        if(firstcard == 7){
            if(cardcount7 == 0){
                cardexists = false;
                }
            if(cardcount7 > 0){
            cardcount7 -= 1;
            }
            if(cardcount7 < 0)
                cardexists = false;
            }
        if(firstcard == 8){
            if(cardcount8 == 0){
                cardexists = false;
                }
            if(cardcount8 > 0){
            cardcount8 -= 1;
            }
            if(cardcount8 < 0)
                cardexists = false;
            }
        if(firstcard == 9){
            if(cardcount9 == 0){
                cardexists = false;
                }
            if(cardcount9 > 0){
            cardcount9 -= 1;
            }
            if(cardcount9 < 0)
                cardexists = false;
            }
        if(firstcard == 10){
            if(cardcount10 == 0){
                cardexists = false;
                }
            if(cardcount10 > 0){
            cardcount10 -= 1;
            }
            if(cardcount10 < 0)
                cardexists = false;
            }
        if(firstcard == 11){
             if(cardcount11 == 0){
                cardexists = false;
                }
            if(cardcount11 > 0){
            cardcount11 -= 1;
            }
            if(cardcount11 < 0)
                cardexists = false;
            }
        if(firstcard == 12){
             if(cardcount12 == 0){
                cardexists = false;
                }
            if(cardcount12 > 0){
            cardcount12 -= 1;
            }
            if(cardcount12 < 0)
                cardexists = false;
            }
        if(firstcard == 13){
             if(cardcount13 == 0){
                cardexists = false;
                }
            if(cardcount13 > 0){
            cardcount13 -= 1;
            }
            if(cardcount13 < 0)
                cardexists = false;
            }
        }
        while(cardexists == false);
        cardexists = true;
        
        
        do{
        cardexists = true;
        secondcard = (rand() % 13 + 1);
        if(secondcard == 1){
            if(cardcount1 == 0){
                cardexists = false;
                }
            if(cardcount1 > 0){
            cardcount1 -= 1;
            }
            if(cardcount1 < 0)
                cardexists = false;
            }
        if(secondcard == 2){
            if(cardcount2 == 0){
                cardexists = false;
                }
            if(cardcount2 > 0){
            cardcount2 -= 1;
            }
            if(cardcount2 < 0)
                cardexists = false;
            }
        if(secondcard == 3){
            if(cardcount3 == 0){
                cardexists = false;
                }
            if(cardcount3 > 0){
            cardcount3 -= 1;
            }
            if(cardcount3 < 0)
                cardexists = false;
            }
        if(secondcard == 4){
            if(cardcount4 == 0){
                cardexists = false;
                }
            if(cardcount4 > 0){
            cardcount4 -= 1;
            }
            if(cardcount4 < 0)
                cardexists = false;
            }
        if(secondcard == 5){
            if(cardcount5 == 0){
                cardexists = false;
                }
            if(cardcount5 > 0){
            cardcount5 -= 1;
            }
            if(cardcount5 < 0)
                cardexists = false;
            }
        if(secondcard == 6){
           if(cardcount6 == 0){
                cardexists = false;
                }
            if(cardcount6 > 0){
            cardcount6 -= 1;
            }
            if(cardcount6 < 0)
                cardexists = false;
            }
        if(secondcard == 7){
            if(cardcount7 == 0){
                cardexists = false;
                }
            if(cardcount7 > 0){
            cardcount7 -= 1;
            }
            if(cardcount7 < 0)
                cardexists = false;
            }
        if(secondcard == 8){
            if(cardcount8 == 0){
                cardexists = false;
                }
            if(cardcount8 > 0){
            cardcount8 -= 1;
            }
            if(cardcount8 < 0)
                cardexists = false;
            }
        if(secondcard == 9){
            if(cardcount9 == 0){
                cardexists = false;
                }
            if(cardcount9 > 0){
            cardcount9 -= 1;
            }
            if(cardcount9 < 0)
                cardexists = false;
            }
        if(secondcard == 10){
            if(cardcount10 == 0){
                cardexists = false;
                }
            if(cardcount10 > 0){
            cardcount10 -= 1;
            }
            if(cardcount10 < 0)
                cardexists = false;
            }
        if(secondcard == 11){
            cardcount11 -= 1;
             if(cardcount11 == 0){
                cardexists = false;
                }
            if(cardcount11 > 0){
            cardcount11 -= 1;
            }
            if(cardcount11 < 0)
                cardexists = false;
            }
        if(secondcard == 12){
             if(cardcount12 == 0){
                cardexists = false;
                }
            if(cardcount12 > 0){
            cardcount12 -= 1;
            }
            if(cardcount12 < 0)
                cardexists = false;
            }
        if(secondcard == 13){
             if(cardcount13 == 0){
                cardexists = false;
                }
            if(cardcount13 > 0){
            cardcount13 -= 1;
            }
            if(cardcount13 < 0)
                cardexists = false;
            }
        }
        while(cardexists == false);
        
        if(firstcard <= 10 && firstcard !=1 &&
           secondcard <= 10 && secondcard != 1){
           cout << "Your cards are " << firstcard << " and " << secondcard << " for a total of " << firstcard + secondcard;
        }      
        
        if((firstcard <=10 && firstcard != 1) && (secondcard >10 || secondcard == 1)){
            cout << "Your cards are " << firstcard << " and ";
            if(secondcard == 11){
                secondcard = 10;
                cout << "a Jack for a total of " << firstcard + secondcard;
            }
            else if(secondcard == 12){
                secondcard = 10;
                cout << "a Queen for a total of " << firstcard + secondcard;
            }
            else if(secondcard == 13){
                secondcard = 10;
                cout << "a King for a total of " << firstcard + secondcard;
            }
            else if(secondcard == 1){
                cout << "an Ace. \nWould you like your Ace to be a 1 or an 11?" << endl;
                do{
                    acecorrect = true;
                        cin >> acechoice;
                            if(acechoice != 1 && acechoice != 11){
                                cout << "That is not a possible choice. Please enter either 1 or 11" << endl;
                                acecorrect = false;
                                }
                            if(acechoice == 1 || acechoice == 11){
                                secondcard = acechoice;
                                total = firstcard + secondcard;
                                    cout << "Your cards are " << firstcard << " and an Ace worth " << secondcard << " for a total of " << total << endl;
                                }
                    }while(acecorrect == false);
                }
        }
        
        
        if(firstcard == 1){
            cout << "You drew an Ace and ";
                if(secondcard == 11){
                    bet *= 3;
                    cout << "a Jack.\n Congratulations! You just got BlackJack! You won 3 times your bet for a total of $" << bet << endl;
                    secondcard = 10;
                    }
                if(secondcard == 12){
                    bet *= 3;
                    cout << "a Queen.\n Congratulations! You just got BlackJack! You won 3 times your bet for a total of $" << bet << endl;
                    secondcard = 10;
                    }
                if(secondcard == 13){
                    bet *= 3;
                    cout << "a King.\n Congratulations! You just got BlackJack! You won 3 times your bet for a total of $" << bet << endl;
                    secondcard = 10;
                    }
                if(secondcard <=10 && secondcard != 1){
                    cout << secondcard;
                    
                cout << ".\nWould you like your Ace to be an 11 or a 1?" << endl;
                do{
                    acecorrect = true;
                        cin >> acechoice;
                            if(acechoice != 1 && acechoice != 11){
                                cout << "That is not a possible choice. Please enter either 1 or 11" << endl;
                                acecorrect = false;
                                }
                            if(acechoice == 1 || acechoice == 11){
                                firstcard = acechoice;
                                total = firstcard + secondcard;
                                    cout << "Your cards are worth " << acechoice << " and " << secondcard << " for a total of " << total << endl;
                                }
                    }while(acecorrect == false);
                }
            }
        else if(firstcard == 11){ //For if the first card is a jack
            firstcard = 10;
            cout << "Your cards are a Jack and ";
            if(secondcard <= 10 && secondcard != 1){
                firstcard = 10;
                cout << secondcard << " for a total of " << secondcard + firstcard;
                }
                else if(secondcard == 11){
                    secondcard = 10;
                    cout << "another Jack for a total of 20.";
                }
                else if(secondcard == 12){
                    secondcard = 10;
                    cout << "a Queen for a total of 20.";
                }
                else if(secondcard == 13){
                    secondcard = 10;
                    cout << "a King for a total of 20.";
                }
                else if(secondcard == 1){
                    bet *=3;
                    cout << "an Ace.\nCongratulations! You just got a BlackJack! You won 3 times your bet for a total of $" << bet << endl;
                    total = 21;
                }
            facecard = true;
            }
        else if(firstcard == 12){ //For if the first card is a queen
        firstcard = 10;
            cout << "Your cards are a Queen and ";
            if(secondcard <= 10 && secondcard != 1){
                cout << secondcard << " for a total of " << secondcard + 10;
                }
                else if(secondcard == 11){
                    secondcard = 10;
                    cout << "a Jack for a total of 20.";
                }
                else if(secondcard == 12){
                    secondcard = 10;
                    cout << "another Queen for a total of 20.";
                }
                else if(secondcard == 13){
                    secondcard = 10;
                    cout << "a King for a total of 20.";
                }
                 else if(secondcard == 1){
                    bet *=3;
                    cout << "an Ace.\nCongratulations! You just got a BlackJack! You won 3 times your bet for a total of $" << bet << endl;
                    total = 21;
                }
            facecard = true;
            }
        else if(firstcard == 13){ //For if the first card is a king
        firstcard = 10;
            cout << "Your cards are a King and ";
            if(secondcard <= 10 && secondcard != 1){
                cout << secondcard << " for a total of " << secondcard + 10;
                }
                else if(secondcard == 11){
                    secondcard = 10;
                    cout << "a Jack for a total of 20.";
                }
                else if(secondcard == 12){
                    secondcard = 10;
                    cout << "a Queen for a total of 20.";
                }
                else if(secondcard == 13){
                    secondcard = 10;
                    cout << "another King for a total of 20.";
                }
                else if(secondcard == 1){
                    bet *=3;
                    cout << "an Ace.\nCongratulations! You just got a BlackJack! You won 3 times your bet for a total of $" << bet << endl;
                    total = 21;
                }
            facecard = true;
            }
        
        
        
        do{
        cardexists = true;
        totalcount = cardcount1 + cardcount2 + cardcount3 + cardcount4 + cardcount5 + cardcount6 + cardcount7 + cardcount8 + cardcount9 + cardcount10 + cardcount11 + cardcount12 + cardcount13;
        if(totalcount < 1){
            cout << endl << "We will reshuffle the deck" << endl << endl;
            cardcount1 = 4;
            cardcount2 = 4;
            cardcount3 = 4;
            cardcount4 = 4;
            cardcount5 = 4;
            cardcount6 = 4;
            cardcount7 = 4;
            cardcount8 = 4;
            cardcount9 = 4;
            cardcount10 = 4;
            cardcount11 = 4;
            cardcount12 = 4;
            cardcount13 = 4;
            }
        dfirstcard = (rand() % 13 + 1);
        if(dfirstcard == 1){
            if(cardcount1 == 0){
                cardexists = false;
                }
            if(cardcount1 > 0){
            cardcount1 -= 1;
            }
            if(cardcount1 < 0)
                cardexists = false;
            }
        if(dfirstcard == 2){
            if(cardcount2 == 0){
                cardexists = false;
                }
            if(cardcount2 > 0){
            cardcount2 -= 1;
            }
            if(cardcount2 < 0)
                cardexists = false;
            }
        if(dfirstcard == 3){
            if(cardcount3 == 0){
                cardexists = false;
                }
            if(cardcount3 > 0){
            cardcount3 -= 1;
            }
            if(cardcount3 < 0)
                cardexists = false;
            }
        if(dfirstcard == 4){
            if(cardcount4 == 0){
                cardexists = false;
                }
            if(cardcount4 > 0){
            cardcount4 -= 1;
            }
            if(cardcount4 < 0)
                cardexists = false;
            }
        if(dfirstcard == 5){
            if(cardcount5 == 0){
                cardexists = false;
                }
            if(cardcount5 > 0){
            cardcount5 -= 1;
            }
            if(cardcount5 < 0)
                cardexists = false;
            }
        if(dfirstcard == 6){
            if(cardcount6 == 0){
                cardexists = false;
                }
            if(cardcount6 > 0){
            cardcount6 -= 1;
            }
            if(cardcount6 < 0)
                cardexists = false;
            }
        if(dfirstcard == 7){
            if(cardcount7 == 0){
                cardexists = false;
                }
            if(cardcount7 > 0){
            cardcount7 -= 1;
            }
            if(cardcount7 < 0)
                cardexists = false;
            }
        if(dfirstcard == 8){
            if(cardcount8 == 0){
                cardexists = false;
                }
            if(cardcount8 > 0){
            cardcount8 -= 1;
            }
            if(cardcount8 < 0)
                cardexists = false;
            }
        if(dfirstcard == 9){
            if(cardcount9 == 0){
                cardexists = false;
                }
            if(cardcount9 > 0){
            cardcount9 -= 1;
            }
            if(cardcount9 < 0)
                cardexists = false;
            }
        if(dfirstcard == 10){
            if(cardcount10 == 0){
                cardexists = false;
                }
            if(cardcount10 > 0){
            cardcount10 -= 1;
            }
            if(cardcount10 < 0)
                cardexists = false;
            }
        if(dfirstcard == 11){
             if(cardcount11 == 0){
                cardexists = false;
                }
            if(cardcount11 > 0){
            cardcount11 -= 1;
            }
            if(cardcount11 < 0)
                cardexists = false;
            }
        if(dfirstcard == 12){
             if(cardcount12 == 0){
                cardexists = false;
                }
            if(cardcount12 > 0){
            cardcount12 -= 1;
            }
            if(cardcount12 < 0)
                cardexists = false;
            }
        if(dfirstcard == 13){
             if(cardcount13 == 0){
                cardexists = false;
                }
            if(cardcount13 > 0){
            cardcount13 -= 1;
            }
            if(cardcount13 < 0)
                cardexists = false;
            }
        }
        while(cardexists == false);
        cardexists = true;
        
        
        do{
        cardexists = true;
        dsecondcard = (rand() % 13 + 1);
        if(dsecondcard == 1){
            if(cardcount1 == 0){
                cardexists = false;
                }
            if(cardcount1 > 0){
            cardcount1 -= 1;
            }
            if(cardcount1 < 0)
                cardexists = false;
            }
        if(dsecondcard == 2){
            if(cardcount2 == 0){
                cardexists = false;
                }
            if(cardcount2 > 0){
            cardcount2 -= 1;
            }
            if(cardcount2 < 0)
                cardexists = false;
            }
        if(dsecondcard == 3){
            if(cardcount3 == 0){
                cardexists = false;
                }
            if(cardcount3 > 0){
            cardcount3 -= 1;
            }
            if(cardcount3 < 0)
                cardexists = false;
            }
        if(dsecondcard == 4){
            if(cardcount4 == 0){
                cardexists = false;
                }
            if(cardcount4 > 0){
            cardcount4 -= 1;
            }
            if(cardcount4 < 0)
                cardexists = false;
            }
        if(dsecondcard == 5){
            if(cardcount5 == 0){
                cardexists = false;
                }
            if(cardcount5 > 0){
            cardcount5 -= 1;
            }
            if(cardcount5 < 0)
                cardexists = false;
            }
        if(dsecondcard == 6){
           if(cardcount6 == 0){
                cardexists = false;
                }
            if(cardcount6 > 0){
            cardcount6 -= 1;
            }
            if(cardcount6 < 0)
                cardexists = false;
            }
        if(dsecondcard == 7){
            if(cardcount7 == 0){
                cardexists = false;
                }
            if(cardcount7 > 0){
            cardcount7 -= 1;
            }
            if(cardcount7 < 0)
                cardexists = false;
            }
        if(dsecondcard == 8){
            if(cardcount8 == 0){
                cardexists = false;
                }
            if(cardcount8 > 0){
            cardcount8 -= 1;
            }
            if(cardcount8 < 0)
                cardexists = false;
            }
        if(dsecondcard == 9){
            if(cardcount9 == 0){
                cardexists = false;
                }
            if(cardcount9 > 0){
            cardcount9 -= 1;
            }
            if(cardcount9 < 0)
                cardexists = false;
            }
        if(dsecondcard == 10){
            if(cardcount10 == 0){
                cardexists = false;
                }
            if(cardcount10 > 0){
            cardcount10 -= 1;
            }
            if(cardcount10 < 0)
                cardexists = false;
            }
        if(dsecondcard == 11){
            cardcount11 -= 1;
             if(cardcount11 == 0){
                cardexists = false;
                }
            if(cardcount11 > 0){
            cardcount11 -= 1;
            }
            if(cardcount11 < 0)
                cardexists = false;
            }
        if(dsecondcard == 12){
             if(cardcount12 == 0){
                cardexists = false;
                }
            if(cardcount12 > 0){
            cardcount12 -= 1;
            }
            if(cardcount12 < 0)
                cardexists = false;
            }
        if(dsecondcard == 13){
             if(cardcount13 == 0){
                cardexists = false;
                }
            if(cardcount13 > 0){
            cardcount13 -= 1;
            }
            if(cardcount13 < 0)
                cardexists = false;
            }
        }
        while(cardexists == false);
        if(dfirstcard > 1 && dfirstcard <=10){
            cout << endl << endl << "The dealer has drawn " << dfirstcard << " and another card." << endl;
            }
        else if(dfirstcard == 11){
            dfirstcard = 10;
            cout << endl << endl << "The dealer drew a Jack and another card." << endl;
            }
        else if(dfirstcard == 12){
            dfirstcard = 10;
            cout << endl << endl << "The dealer drew a Queen and another card." << endl;
            }
        else if(dfirstcard == 13){
            dfirstcard = 10;
            cout << endl << endl << "The dealer drew a King and another card." << endl;
            }
        else if(dfirstcard == 1){
            cout << endl << endl << "The dealer drew an Ace and another card." << endl;
            }
        
        
        
        total = firstcard + secondcard;
        
        
        //Blackjack goes here
        
        
        if(total < 21){
            cout << "\nWould you like to hit, stay or double down?\n(H to hit, S to stay and D to double down)" << endl;
            do{
                if(hit2 == true){
                    choice = 'h';
                }
                if(hit2 == false){
                    cin >> choice;
                }
                hit2= false;
            do{
            choicecorrect = true;
                if(choice == 'H' || choice == 'h'){
                    drawcard = true;
                }
                if(choice == 'D' || choice == 'd'){
                    drawcard = true;
                    bet *= 2;
                    cout << "Your bet is now worth $" << bet << " and you will hit once." << endl;
                }
                    if(drawcard == true){
                        drawcard = false;
                            do{
                                cardexists = true;
                                totalcount = cardcount1 + cardcount2 + cardcount3 + cardcount4 + cardcount5 + cardcount6 + cardcount7 + cardcount8 + cardcount9 + cardcount10 + cardcount11 + cardcount12 + cardcount13;
                                    if(totalcount < 1){
                                        cout << endl << "We will reshuffle the deck" << endl << endl;
                                            cardcount1 = 4; 
                                            cardcount2 = 4;
                                            cardcount3 = 4;
                                            cardcount4 = 4;
                                            cardcount5 = 4;
                                            cardcount6 = 4;
                                            cardcount7 = 4;
                                            cardcount8 = 4;
                                            cardcount9 = 4;
                                            cardcount10 = 4;
                                            cardcount11 = 4;
                                            cardcount12 = 4;
                                            cardcount13 = 4;
                                            }
                                    card= (rand() % 13 + 1);
                                    if(card == 1){
                                        if(cardcount1 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount1 > 0){
                                        cardcount1 -= 1;
                                        }
                                        if(cardcount1 < 0)
                                            cardexists = false;
                                        }
                                        if(card== 2){
                                            if(cardcount2 == 0){
                                                cardexists = false;
                                        }
                                        if(cardcount2 > 0){
                                        cardcount2 -= 1;
                                        }
                                        if(cardcount2 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 3){
                                        if(cardcount3 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount3 > 0){
                                        cardcount3 -= 1;
                                        }
                                        if(cardcount3 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 4){
                                        if(cardcount4 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount4 > 0){
                                        cardcount4 -= 1;
                                        }
                                        if(cardcount4 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 5){
                                        if(cardcount5 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount5 > 0){
                                        cardcount5 -= 1;
                                        }
                                        if(cardcount5 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 6){
                                        if(cardcount6 == 0){
                                            cardexists = false;
                                        }
                                        if(cardcount6 > 0){
                                        cardcount6 -= 1;
                                        }
                                        if(cardcount6 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 7){
                                        if(cardcount7 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount7 > 0){
                                        cardcount7 -= 1;
                                        }
                                        if(cardcount7 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 8){
                                        if(cardcount8 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount8 > 0){
                                        cardcount8 -= 1;
                                        }
                                        if(cardcount8 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 9){
                                        if(cardcount9 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount9 > 0){
                                        cardcount9 -= 1;
                                        }
                                        if(cardcount9 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 10){
                                        if(cardcount10 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount10 > 0){
                                        cardcount10 -= 1;
                                        }
                                        if(cardcount10 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 11){
                                         if(cardcount11 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount11 > 0){
                                        cardcount11 -= 1;
                                        }
                                        if(cardcount11 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 12){
                                         if(cardcount12 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount12 > 0){
                                        cardcount12 -= 1;
                                        }
                                        if(cardcount12 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 13){
                                         if(cardcount13 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount13 > 0){
                                        cardcount13 -= 1;
                                        }
                                        if(cardcount13 < 0)
                                            cardexists = false;
                                        }
                                    }while(cardexists == false);
                                if(card != 1 && card <= 10){
                                    total += card;
                                    cout << "You drew " << card << " for a total of " << total << endl;
                                }
                                if(card == 1){
                                    cout << "You drew an Ace. Do you want the Ace to be an 11 or a 1?" << endl;
                                    do{
                                        acecorrect = true;
                                            cin >> acechoice;
                                                if(acechoice != 1 && acechoice != 11){
                                                 cout << "That is not a possible choice. Please enter either 1 or 11" << endl;
                                                  acecorrect = false;
                                                   }
                                               if(acechoice == 1 || acechoice == 11){
                                                   total += acechoice;
                                                   cout << "Your total is now " << total << endl;
                                                   }
                                      }while(acecorrect == false);
                                    }
                                
                                if(card == 11){
                                    card = 10;
                                    total += card;
                                    cout << "You drew a Jack for a new total of " << total << endl;
                                }
                                if(card == 12){
                                    card = 10;
                                    total += card;
                                    cout << "You drew a Queen for a new total of " << total << endl;
                                }
                                if(card == 13){
                                    card = 10;
                                    total += card;
                                    cout << "You drew a King for a new total of " << total << endl;
                                }
                                
                                if(total < 21 && (choice == 'H' || choice == 'h')){
                                    cout << "Would you like to hit again? (H to hit, S to stay)" << endl;
                                    cin >> choice;
                                    if(choice == 'H' || choice == 'h'){
                                        hit2 = true;
                                        }
                                    }
                                }
                if(choice == 'S' || choice == 's'){ //STAY
                    cout << "You chose to stay with a total of " << total <<"." << endl;
                    }

                                
                if(choice != 'H' && choice != 'h'
                   && choice != 'S' && choice != 's' 
                   && choice != 'D' && choice != 'd'){
                        cout << "\nThat is not a valid choice, please choose H to hit, S to stay or D to double down." << endl;
                        choicecorrect = false;
                        }
                }while(choicecorrect == false);
            }while (hit2 == true);
        }

        if(total > 21){
            cout << "You bust! Sorry." << endl;
            bust = true;
            }                     
        if(total == 21){
            cout << "You got 21! The dealer will now flip over his other card." << endl;
            cout << "The dealer flips his face down card and reveals ";
            if(dsecondcard > 1 && dsecondcard <=10){
            cout << dsecondcard << endl;
            }
        else if(dsecondcard == 11){
            dsecondcard = 10;
            cout << "a Jack." << endl;
            }
        else if(dsecondcard == 12){
            dsecondcard = 10;
            cout << "a Queen." << endl;
            }
        else if(dsecondcard == 13){
            dsecondcard = 10;
            cout << "a King." << endl;
            }
        else if(dsecondcard == 1){
            cout << "an Ace that will be worth ";
                if(dfirstcard <= 6){
                    dsecondcard = 1;
                    cout << "1." << endl;
                }
                if(dfirstcard > 6){
                    dsecondcard = 11;
                    cout << "11." << endl;
                }
            }
            if(dfirstcard + dsecondcard != 21){
                cout << "You win!" << endl;
                money += bet;
            }
            if(dfirstcard + dsecondcard == 21){
                cout << "It's a tie!" << endl;
                push = true;
            }
        }
        if(total < 21){
            cout << "Your cards total " << total << "." << endl;
            //Dealer comparison here
            cout << endl << "The dealer will now play his hand until he reaches a minimum of 17." << endl;
            cout << "The dealer flips his face down card and reveals ";
            if(dsecondcard > 1 && dsecondcard <=10){
            cout << dsecondcard << endl;
            }
        else if(dsecondcard == 11){
            dsecondcard = 10;
            cout << "a Jack." << endl;
            }
        else if(dsecondcard == 12){
            dsecondcard = 10;
            cout << "a Queen." << endl;
            }
        else if(dsecondcard == 13){
            dsecondcard = 10;
            cout << "a King." << endl;
            }
        else if(dsecondcard == 1){
            cout << "an Ace that will be worth ";
                if(dfirstcard <= 6){
                    dsecondcard = 1;
                    cout << "1." << endl;
                }
                if(dfirstcard > 6){
                    dsecondcard = 11;
                    cout << "11." << endl;
                }
            }
        if(dfirstcard == 1){
            if(dsecondcard <= 6 || dsecondcard == 11){
                dfirstcard = 1;
            }
            if(dsecondcard > 6 && dsecondcard != 11){
                dfirstcard = 11;
            }
        }
        dtotal = dfirstcard + dsecondcard;
        cout << endl << "The dealers current total is " << dtotal << "." << endl;
        if(dtotal == 21){
            cout << "The dealer got a blackjack!";
            }
        }   
        if(dtotal < 17){
            do{
                ddraw = false;
                            do{
                                cardexists = true;
                                totalcount = cardcount1 + cardcount2 + cardcount3 + cardcount4 + cardcount5 + cardcount6 + cardcount7 + cardcount8 + cardcount9 + cardcount10 + cardcount11 + cardcount12 + cardcount13;
                                    if(totalcount < 1){
                                        cout << endl << "We will reshuffle the deck" << endl << endl;
                                            cardcount1 = 4; 
                                            cardcount2 = 4;
                                            cardcount3 = 4;
                                            cardcount4 = 4;
                                            cardcount5 = 4;
                                            cardcount6 = 4;
                                            cardcount7 = 4;
                                            cardcount8 = 4;
                                            cardcount9 = 4;
                                            cardcount10 = 4;
                                            cardcount11 = 4;
                                            cardcount12 = 4;
                                            cardcount13 = 4;
                                            }
                                    card= (rand() % 13 + 1);
                                    if(card == 1){
                                        if(cardcount1 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount1 > 0){
                                        cardcount1 -= 1;
                                        }
                                        if(cardcount1 < 0)
                                            cardexists = false;
                                        }
                                        if(card== 2){
                                            if(cardcount2 == 0){
                                                cardexists = false;
                                        }
                                        if(cardcount2 > 0){
                                        cardcount2 -= 1;
                                        }
                                        if(cardcount2 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 3){
                                        if(cardcount3 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount3 > 0){
                                        cardcount3 -= 1;
                                        }
                                        if(cardcount3 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 4){
                                        if(cardcount4 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount4 > 0){
                                        cardcount4 -= 1;
                                        }
                                        if(cardcount4 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 5){
                                        if(cardcount5 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount5 > 0){
                                        cardcount5 -= 1;
                                        }
                                        if(cardcount5 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 6){
                                        if(cardcount6 == 0){
                                            cardexists = false;
                                        }
                                        if(cardcount6 > 0){
                                        cardcount6 -= 1;
                                        }
                                        if(cardcount6 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 7){
                                        if(cardcount7 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount7 > 0){
                                        cardcount7 -= 1;
                                        }
                                        if(cardcount7 < 0)
                                            cardexists = false;
                                        }
                                    if(card== 8){
                                        if(cardcount8 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount8 > 0){
                                        cardcount8 -= 1;
                                        }
                                        if(cardcount8 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 9){
                                        if(cardcount9 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount9 > 0){
                                        cardcount9 -= 1;
                                        }
                                        if(cardcount9 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 10){
                                        if(cardcount10 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount10 > 0){
                                        cardcount10 -= 1;
                                        }
                                        if(cardcount10 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 11){
                                         if(cardcount11 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount11 > 0){
                                        cardcount11 -= 1;
                                        }
                                        if(cardcount11 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 12){
                                         if(cardcount12 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount12 > 0){
                                        cardcount12 -= 1;
                                        }
                                        if(cardcount12 < 0)
                                            cardexists = false;
                                        }
                                    if(card == 13){
                                         if(cardcount13 == 0){
                                            cardexists = false;
                                            }
                                        if(cardcount13 > 0){
                                        cardcount13 -= 1;
                                        }
                                        if(cardcount13 < 0)
                                            cardexists = false;
                                        }
                                    }while(cardexists == false);
                                if(card != 1 && card <= 10){
                                    dtotal += card;
                                    cout << "The dealer drew " << card << " for a total of " << dtotal << endl;
                                }
                                if(card == 1){
                                    cout << "The dealer drew an Ace that will be worth ";
                                    if(dtotal <= 6 || dtotal > 10){
                                        card = 1;
                                        cout << "1." << endl;
                                    }
                                    else{
                                        card = 11;
                                        cout << "11." << endl;
                                    }
                                }
                                if(card == 11){
                                    card = 10;
                                    dtotal += card;
                                    cout << "The dealer drew a Jack for a new total of " << dtotal << endl;
                                }
                                if(card == 12){
                                    card = 10;
                                    dtotal += card;
                                    cout << "The dealer drew a Queen for a new total of " << dtotal << endl;
                                }
                                if(card == 13){
                                    card = 10;
                                    dtotal += card;
                                    cout << "The dealer drew a King for a new total of " << dtotal << endl;
                                }
                            if(dtotal < 17){
                                ddraw = true;
                            }
                }while(ddraw == true);
            }
            if(bust == false){
                if(dtotal > 21){
                    cout << "The dealer bust! You win!" << endl << endl;
                    money += bet;
                }
                if(dtotal < total && total <= 21){
                    cout << "You win!" << endl << endl;
                    money += bet;
                }
                if(dtotal > total && dtotal <= 21){
                    cout << "Sorry, you lose!" << endl << endl;
                    money -= bet;
                }
                if(dtotal == total){
                    cout << "It's a tie!" << endl << endl;
                    push = true;
                }
            }
            if(bust == true){
                money -= bet;
                bust = false;
            }
                         
                    
        //if(firstcard == secondcard){
        //    cout << "Would you like to split? (Y/N)\n";
        //    cin >> split;
        //    if(split == 'Y' || split == 'y'){
        //        splitcard1 = firstcard;
        //        splitcard2 = secondcard;
        //        firstcard = splitcard1;
                
                    
    if(money <= 5){
        cout << "You do not have enough money to continue playing right now. To get more money to play, please make payments of $100 to Stephen Anderson." << endl << endl;
        moneyok = false;
    }
                  
    if(push == false && moneyok == true){        
    cout << endl << "Would you like to play another hand? (Y/N)" << endl;
    cin >> repeat;
    }
    if(push == true){
        repeat = 'y';
    }
    
    if(moneyok == false){
        repeat = 'n';
    }
    }while(repeat == 'Y' || repeat == 'y');
system("PAUSE");
return 0;
}

