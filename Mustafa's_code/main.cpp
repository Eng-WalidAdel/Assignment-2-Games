
#include "BoardGame_Classes.h"
#include "3x3X_O.h"
//#include "MinMaxPlayer.h"
#include "Connect_Four.h"
#include "Numerical_Tic-Tac-Toe.h"
#include "4 x 4 Tic-Tac-Toe .h"
#include <bits/stdc++.h>

using namespace std;

//int main() {
//
//    Player<char>* players[2];
//    Board <char> * B = new Four_in_a_row_Board <char>();
//
//    int choice;
//    string player1Name, player2Name;
//
//    cout << "Welcome to Connect Four X-O Game. :)\n";
//
//    // Set up player 1
//    cout << "Choose Player 1 type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cout << "3. Smart Computer (AI)\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            cout << "Enter Player 1 name:";
//            cin >> player1Name;
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
//    players[0]->setBoard(B);
//
//    // Set up player 2
//    cout << "Choose Player 2 type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cout << "3. Smart Computer (AI)\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            cout << "Enter Player 1 name:";
//            cin >> player2Name;
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
//    players[1]->setBoard(B);
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

//int main() {
//
//    Player<int>* players[2];
//    Board <int> * B = new Numerical_Tic_Tac_Toe_Board <int>;
//
//    int choice;
//    string player1Name, player2Name;
//
//    cout << "Welcome to Numerical_Tic_Tac_Toe Game. :)\n";
//
//    // Set up player 1
//    cout << "Choose Player 1 type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cout << "3. Smart Computer (AI)\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            cout << "Enter Player 1 name:";
//            cin >> player1Name;
//            players[0] = new Numerical_Tic_Tac_Toe_player <int> (player1Name,0);
//            break;
//        case 2:
//            players[0] = new Numerical_Tic_Tac_Toe_random_player <int> (0) ;
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
//    players[0]->setBoard(B);
//
//    // Set up player 2
//    cout << "Choose Player 2 type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cout << "3. Smart Computer (AI)\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            cout << "Enter Player 1 name:";
//            cin >> player2Name;
//            players[1] = new Numerical_Tic_Tac_Toe_player <int>(player2Name, 0);
//            break;
//        case 2:
//            players[1] = new Numerical_Tic_Tac_Toe_random_player<int>(0);
//            break;
////        case 3:
////            players[1] = new X_O_MinMax_Player<char>('O');
////            players[1]->setBoard(B);
////            break;
//        default:
//            cout << "Invalid choice for Player 2. Exiting the game.\n";
//            return 1;
//    }
//    players[1]->setBoard(B);
//
//    // Create the game manager and run the game
//    GameManager<int> x_o_game (B, players);
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

int main() {

    Player<char>* players[2];
    Board <char> * B = new _4x4_Tic_Tac_Toe_Board <char>();

    int choice;
    string player1Name, player2Name;

    cout << "Welcome to 4 x 4 Tic-Tac-Toe Game. :)\n";

    // Set up player 1
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new _4x4_Tic_Tac_Toe_Player <char> (player1Name, 'X');
            break;
        case 2:
            players[0] = new _4x4_Tic_Tac_Toe_Random_Player <char> ('X');
            break;
//        case 3:
//            players[0] = new X_O_MinMax_Player<char>('X');
//            players[0]->setBoard(B);
//            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    players[0]->setBoard(B);

    // Set up player 2
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player2Name;
            players[1] = new _4x4_Tic_Tac_Toe_Player <char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new _4x4_Tic_Tac_Toe_Random_Player<char>('O');
            break;
//        case 3:
//            players[1] = new X_O_MinMax_Player<char>('O');
//            players[1]->setBoard(B);
//            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }
    players[1]->setBoard(B);

    // Create the game manager and run the game
    GameManager<char> x_o_game (B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

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
