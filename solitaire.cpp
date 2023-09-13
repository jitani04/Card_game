/*
Name: Jenna Itani
Class: CECS 325- 02
Prog Name: Fibo Solitaire 
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program
*/
#include "deck.h"
#include <ctime>
#include "card.h"
#include <iostream>
using namespace std;

bool isFibo( int sum){
    int fibo_nums[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    bool fibo = false;
    for(int i = 0; i < 14; ++i){
        if(sum == fibo_nums[i]){
            fibo = true;
        }
    }
    return fibo;
}

int main(){
    srand(time(0));
    int games = 0;
    Deck mydeck;
    bool opt_in = true;
    int game_counter = 0;
    while(opt_in){
        cout << "\nWelcome to Fibo Solitaire!" << endl << "1) Create New Deck" << endl << "2) Shuffle Deck" << endl <<
        "3) Display Deck"<< endl << "4) Play Fibo Solitaire" << endl << "5) Win Fibo Solitaire" << endl << "6) Exit" << endl;
        int user_input;
        cin >> user_input;

        if(user_input == 1){ //create new deck
            mydeck.resetDeck();
        }
        else if(user_input == 2){ //shuffle deck
            mydeck.shuffle();
        }
        else if(user_input == 3){ //dispay deck
            mydeck.show();
        }   

        else if(user_input == 4){ //play fibo solitaire
            cout << "Playing Fibonacci Solitaire!!" << endl;
            ++games;
            mydeck.resetDeck();
            mydeck.shuffle();
            int pile = 1;
            int sum = 0;

            for(int i = 0; i < 52, mydeck.isEmpty() == false; ++i){
                Card dealt_card = mydeck.deal(); 
                int inc = dealt_card.getValue();
                sum += inc;
                dealt_card.show();
                cout << ", ";
                if(i == 51){
                    if(isFibo(sum)){
                        cout << "Fibo" << sum << endl << cout << "Winner in " << pile << " piles!";
                    }
                    else{
                        cout << "Last pile NOT fibo: " << sum << endl << "Loser in " << pile << " piles!";
                    }
                } 
                else if(i != 51 and isFibo(sum)){
                    cout << "Fibo: " << sum << endl;
                    sum = 0;
                    ++pile;
                }
            }
        }

        else if(user_input == 5){ //win fibo solitaire
            bool winner = false;
            cout << "Playing Fibonacci Solitaire!!" << endl;
            while(winner == false){
                mydeck.resetDeck();
                mydeck.shuffle();
                ++games;
                int sum = 0;
                int pile = 1;
                for(int i = 0; i < 52, mydeck.isEmpty() == false; ++i){
                    Card dealt_card = mydeck.deal(); 
                    int inc = dealt_card.getValue();
                    sum += inc;
                    dealt_card.show();
                    cout << ", ";
                    
                    if(i == 51){
                        if(isFibo(sum)){
                            cout << "Fibo: " << sum << endl << "Winner in " << pile << " piles!" << endl;
                            cout << endl << endl<< "Winner in " << games << " games." << endl;
                            winner = true;
                        }
                        else{
                            cout << "Last pile NOT fibo: " << sum << endl << "Loser in " << pile << " piles!\n" <<endl;
                        }
                    }
                    else if(i != 51 and isFibo(sum)){
                        cout << "Fibo: " << sum << endl;
                        sum = 0; 
                        ++pile;
                    }
                }  
            }
        }

        else if(user_input == 6){ //exit
            cout << "You have left Fibo Solitaire\n";
            opt_in = false;
        }
        else{ //invalid input
            cout << "Please Enter a number 1-6";
        }
     cout << "\ntotal games played: " << games << endl;
    }
}