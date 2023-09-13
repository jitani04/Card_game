/*
Name: Jenna Itani
Class: CECS 325- 02
Prog Name: Fibo Solitaire (Prog 1)
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program
*/
#include "deck.h"
#include "card.h"
#include <ctime>
#include <iostream>
using namespace std;

    Deck::Deck(){ // constructor which creates a deck of 52 cards. Ace of Spades on top, followed by the
    //rest of the spades in order, followed by Hearts, Diamonds and Clubs.
        char rank[] = {'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q','K'};
        char suit[] = {'S', 'H', 'D', 'C'};
        int c = 0;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 13; ++j){
                gamedeck[c] = Card(rank[j], suit[i]);
                ++c;
            }
        }
    }

    void Deck::resetDeck(){ // reset the deck so it looks like a new deck
        top = 0;
        char rank[] = {'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q','K'};
        char suit[] = {'S', 'H', 'D', 'C'};
        int c = 0;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 13; ++j){
                gamedeck[c] = Card(rank[j], suit[i]);
                ++c;
            }
        }
    }

    Card Deck::deal(){ // deal a card from the top of the deck.
        Card dealt = gamedeck[top];
        ++top;
        return dealt;

    }

    void Deck::shuffle(){ //shuffle the cards in the deck.
    
        for(int i = 0; i < 52; ++i){

            int rand1 = rand() % 52;
            int rand2 = rand() % 52;

            Card saver = gamedeck[rand1];
            gamedeck[rand1] = gamedeck[rand2];
            gamedeck[rand2] = saver;
        }
    }

    bool Deck::isEmpty(){ //true if deck is empty, false if the deck is not empty
        if(top == 52){
            return true;
        }
        else{
            return false;
        }
    }
    void Deck::show(){ // show all the cards in the deck: 13 columns and 4 rows
        int column = 0;
        for(int i = 0; i < 52; ++i, ++column){
            if(column == 13){
                cout << endl;
                column = 0;
            }
            gamedeck[i].show();
            if(i != 51){
                cout << ", ";
            }
        }
        cout << endl;
    }

