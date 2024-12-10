////#include <iostream>
//#include "BoardGame_Classes.h"
//#include "3x3X_O.h"
////#include "MinMaxPlayer.h"
//#include "Connect_Four.h"
//#include "Numerical_Tic-Tac-Toe.h"
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//
//    Player<char>* players[2];
//    auto * B = new Four_in_a_row_Board <char>();
//
//    int choice;
//    string player1Name, player2Name;
//
//    cout << "Welcome to FCAI X-O Game. :)\n";
//
//    // Set up player 1
//    cout << "Enter Player X name: ";
//    cin >> player1Name;
//    cout << "Choose Player X type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cout << "3. Smart Computer (AI)\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[0] = new Four_in_a_row_player <char> (player1Name, 'X');
//            break;
//        case 2:
//            players[0] = new Four_in_a_row_random_player <char> ('X');
//            break;
////        case 3:
////            players[0] = new X_O_MinMax_Player<char>('X');
////            players[0]->setBoard(B);
////            break;
//        default:
//            cout << "Invalid choice for Player 1. Exiting the game.\n";
//            return 1;
//    }
//
//    // Set up player 2
//    cout << "Enter Player 2 name: ";
//    cin >> player2Name;
//    cout << "Choose Player 2 type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cout << "3. Smart Computer (AI)\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[1] = new Four_in_a_row_player <char>(player2Name, 'O');
//            break;
//        case 2:
//            players[1] = new Four_in_a_row_random_player<char>('O');
//            break;
////        case 3:
////            players[1] = new X_O_MinMax_Player<char>('O');
////            players[1]->setBoard(B);
////            break;
//        default:
//            cout << "Invalid choice for Player 2. Exiting the game.\n";
//            return 1;
//    }
//
//    // Create the game manager and run the game
//    GameManager<char> x_o_game (B, players);
//    x_o_game.run();
//
//    // Clean up
//    delete B;
//    for (int i = 0; i < 2; ++i) {
//        delete players[i];
//    }
//
//    return 0;
//}

#include "BoardGame_Classes.h"
#include "Connect_Four.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    Player<char>* players[2];
    auto* board = new Four_in_a_row_Board<char>();

    string player1Name, player2Name;
    int choice;

    cout << "Welcome to FCAI Connect Four Game! :)\n";

    // Player 1 setup
    cout << "Enter Player X name: ";
    cin >> player1Name;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    if (choice == 1) {

        players[0] = new Four_in_a_row_player<char>(player1Name, 'X');

    } else if (choice == 2) {
        players[0] = new Four_in_a_row_random_player<char>('X');
    } else {
        cout << "Invalid choice for Player X. Exiting.\n";
        delete board;
        return 1;
    }

    // Player 2 setup
    cout << "Enter Player O name: ";
    cin >> player2Name;
    cout << "Choose Player O type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    if (choice == 1) {
        players[1] = new Four_in_a_row_player<char>(player2Name, 'O');
    } else if (choice == 2) {
        players[1] = new Four_in_a_row_random_player<char>('O');
    } else {
        cout << "Invalid choice for Player O. Exiting.\n";
        delete players[0];
        delete board;
        return 1;
    }

    // Game Manager and Execution
    GameManager<char> game(board, players);
    game.run();

    // Clean up
    delete board;
    delete players[0];
    delete players[1];

    return 0;
}



//int main() {
//    int choice;
//    Player<char>* players[2];
//    X_O_Board<char>* B = new X_O_Board<char>();
//    string playerXName, player2Name;
//
//    cout << "Welcome to FCAI X-O Game. :)\n";
//
//    // Set up player 1
//    cout << "Enter Player X name: ";
//    cin >> playerXName;
//    cout << "Choose Player X type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cout << "3. Smart Computer (AI)\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[0] = new X_O_Player<char>(playerXName, 'X');
//            break;
//        case 2:
//            players[0] = new X_O_Random_Player<char>('X');
//            break;
////        case 3:
////            players[0] = new X_O_MinMax_Player<char>('X');
////            players[0]->setBoard(B);
////            break;
//        default:
//            cout << "Invalid choice for Player 1. Exiting the game.\n";
//            return 1;
//    }
//
//    // Set up player 2
//    cout << "Enter Player 2 name: ";
//    cin >> player2Name;
//    cout << "Choose Player 2 type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cout << "3. Smart Computer (AI)\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[1] = new X_O_Player<char>(player2Name, 'O');
//            break;
//        case 2:
//            players[1] = new X_O_Random_Player<char>('O');
//            break;
////        case 3:
////            players[1] = new X_O_MinMax_Player<char>('O');
////            players[1]->setBoard(B);
////            break;
//        default:
//            cout << "Invalid choice for Player 2. Exiting the game.\n";
//            return 1;
//    }
//
//    // Create the game manager and run the game
//    GameManager<char> x_o_game(B, players);
//    x_o_game.run();
//
//    // Clean up
//    delete B;
//    for (int i = 0; i < 2; ++i) {
//        delete players[i];
//    }
//
//    return 0;
//}
//
