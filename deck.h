/*
Name: Jenna Itani
Class: CECS 325- 02
Prog Name: Fibo Solitaire (Prog 1)
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program
*/
#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck{
    private:
    Card gamedeck[52];
    int top = 0;
    public:
    Deck();
    void resetDeck();
    Card deal();
    void shuffle();
    bool isEmpty();
    void show();

};
#endif
