/*
 Trang Hoang
 9/13/20
 Assignment 2.1

 This program allows a user to play a simple game of blackjack. The goal is to get as close
 to 21 as possible without going over.

 a2_1amend.cpp

 Created by nyccowgirl on 9/13/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
    
    srand(static_cast<unsigned>(time(nullptr)));
    
    const int blackjack = 21;       // Define blackjack amount
    
    int card1, card2, newCard;      // To hold randomly generated cards
    int total;                      // To hold the sum of all the cards
    char anotherCard = '\0';               // To hold Y/N or y/n input for another card
    char again;                     // To hold Y/N or y/n input to play again
    
    do {
        card1 = rand() % 10 + 1;
        card2 = rand() % 10 + 1;
            
        cout << "First cards: " << card1 << ", " << card2 << endl;
        total = card1 + card2;
        cout << "Total: " << total << endl;

            while ((total < blackjack) && (anotherCard != 'n' && anotherCard != 'N')) {
                cout << "Do you want another card? (y/n): ";
                cin >> anotherCard;
                
                while (anotherCard != 'y' && anotherCard != 'Y' && anotherCard != 'n' && anotherCard != 'N') {
                    cout << "ERROR: Enter y or n whether you want another card: ";
                    cin >> anotherCard;
                }
            
                if (anotherCard == 'y' || anotherCard == 'Y') {
                    newCard = rand() % 10 + 1;
                    cout << "Card: " << newCard << endl;
                    total += newCard;
                    cout << "Total: " << total << endl;
                }
            }
                
            if (total == blackjack) {
                cout << "Congratulations!" << endl;
            } else if (total > blackjack) {
                cout << "Bust." << endl;
            }
        
        cout << "Would you like to play again? (y/n): ";
        cin >> again;
        anotherCard = '\0';
        cout << endl;
    
        while (again != 'y' && again != 'Y' && again != 'n' && again != 'N') {
            cout << "ERROR: Enter y or n whether you want to play again: ";
            cin >> again;
        }
        
    } while (again == 'y' || again == 'Y');
    return 0;
}


/*
 
 First cards: 4, 6
 Total: 10
 Do you want another card? (y/n): Y
 Card: 2
 Total: 12
 Do you want another card? (y/n): y
 Card: 5
 Total: 17
 Do you want another card? (y/n): c
 ERROR: Enter y or n whether you want another card: y
 Card: 6
 Total: 23
 Bust.
 Would you like to play again? (y/n): y
 
 First cards: 3, 4
 Total: 7
 Do you want another card? (y/n): y
 Card: 8
 Total: 15
 Do you want another card? (y/n): n
 Would you like to play again? (y/n): y

 First cards: 4, 2
 Total: 6
 Do you want another card? (y/n): y
 Card: 3
 Total: 9
 Do you want another card? (y/n): y
 Card: 2
 Total: 11
 Do you want another card? (y/n): y
 Card: 10
 Total: 21
 Congratulations!
 Would you like to play again? (y/n): n

 Program ended with exit code: 0

*/
