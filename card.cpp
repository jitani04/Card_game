/*
Name: Jenna Itani
Class: CECS 325- 02
Prog Name: Fibo Solitaire 
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program
*/
#include "card.h"
#include <iostream>
using namespace std;

    Card::Card(){  // create a “default” card
        rank = '2';
        suit = 'S';
    }
    Card::Card(char r, char s){ // constructor to create a card, setting the rank and suit
        rank = r;
        suit = s;
    }
    void Card::setCard(char r, char s){ //set existing card to new values 
        rank = r;
        suit = s;
    }
    int Card::getValue(){ // return the point value of the card. Ace = 1, 2 thru 10, Jack = 10, Queen = 10,
//King = 10

        if(rank == 'A'){
            return 1;
        }
        else if(rank == 'J' or rank == 'Q' or rank =='K'){
            return 10;
        }
        else{
            int rankVal = int(rank) - 48;
            return rankVal;
        }
    return 0;
    }
    
    void Card::show(){ // show the card using 2 fields… Ace of Spade:AS, Ten of Diamond:10D, Queen
    //of Heart:QH, Three of Club:3C.
        cout << rank << suit;

    }

