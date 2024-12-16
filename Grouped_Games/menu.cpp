
#include <bits/stdc++.h>
#include "Word_Tic_Tc_Toe.h"
#include "Pyramid_Tic_Tac_Toe.h"
#include "Connect_Four.h"
#include "Numerical_Tic-Tac-Toe.h"
#include "4 x 4 Tic-Tac-Toe.h"
#include"5x5X_O.h"
#include"Game6.h"
#include"Ultimate_Board.h"
using namespace std;

int game1();
int game2();
int game3();
int game4();
int game5();
int game6();
int game7();
int game8();
int valid_choice(string);

void displayMenu() {

    cout << "\n========== Game Menu ==========" << endl;
    cout << "1. Game 1" << endl;
    cout << "2. Game 2" << endl;
    cout << "3. Game 3" << endl;
    cout << "4. Game 4" << endl;
    cout << "5. Game 5" << endl;
    cout << "6. Game 6" << endl;
    cout << "7. Game 7" << endl;
    cout << "8. Game 8" << endl;
    cout << "0. Exit" << endl;
    cout << "================================" << endl;
    cout << "Enter your choice:";
}

int main() {
    int choice;

    do {
//#ifdef _WIN32
//        system("cls");
//#else
//        system("clear");
//#endif

        while (true) {
            displayMenu();
            cin >> choice;

            // Check if input is valid
            if (cin.fail()) {
                cin.clear();                     // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "\nInvalid input. Please enter valid choice.\n";
            } else {
                break; // Exit loop if input is valid
            }
        }

        switch (choice) {
            case 1: game1(); break;
            case 2: game2(); break;
            case 3: game3(); break;
            case 4: game4(); break;
            case 5: game5(); break;
            case 6: game6(); break;
            case 7: game7(); break;
            case 8: game8(); break;
            case 0: cout << "Exiting the program. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }

        if (choice != 0) {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore(); // Clear the newline left by cin
            cin.get();
        }

    } while (choice != 0);

    return 0;
}


int game1(){
    cout << "\nYou chose Game 1!" << endl;
    Player<char>* players[2];
    Board <char> * B = new Pyramid_Board <char>();

    string player1Name, player2Name;

    cout << "Welcome to Pyramid Tic-Tac-Toe Game. :)\n";

    // Set up player 1
    switch(valid_choice("1")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new Pyramid_Player <char> (player1Name, 'X');
            break;
        case 2:
            players[0] = new Pyramid_Random_Player <char> ('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    players[0]->setBoard(B);

    // Set up player 2
    switch(valid_choice("2")) {
        case 1:
            cout << "Enter Player 2 name:";
            cin >> player2Name;
            players[1] = new Pyramid_Player <char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new Pyramid_Random_Player<char>('O');
            break;
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

int game2() {
    cout << "\nYou chose Game 2!" << endl;
    Player<char>* players[2];
    Board <char> * B = new Four_in_a_row_Board <char>();


    string player1Name, player2Name;

    cout << "Welcome to Connect Four X-O Game. :)\n";

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new Four_in_a_row_player <char> (player1Name, 'X');
            break;
        case 2:
            players[0] = new Four_in_a_row_random_player <char> ('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    players[0]->setBoard(B);

    // Set up player 2

    switch(valid_choice("2")) {
        case 1:
            cout << "Enter Player 2 name:";
            cin >> player2Name;
            players[1] = new Four_in_a_row_player <char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new Four_in_a_row_random_player<char>('O');
            break;
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

int game3() {
    Player<char>* players[2];
    auto* B = new X5_O5_Board<char>();


    string playerXName, player2Name;

    cout << "Welcome to 5 x 5 Tic Tac Toe Game. :)\n";

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            players[0] = new X5_O5_Player<char>(playerXName, 'X');
        break;
        case 2:
//            players[0] = new X5_O5_Random_Player<char>(playerXName,'X');              ///////////////////
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }

    // Set up player 2

    switch(valid_choice("2")) {
        case 1:
            players[1] = new X5_O5_Player<char>(player2Name, 'O');
        break;
        case 2:
//            players[1] = new X5_O5_Random_Player<char>(player2Name,'O');
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return 1;
    }

    // Create the game manager and run the game

    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}


int game4() {
    cout << "\nYou chose Game 4!" << endl;
//    string dict_file = "dic.txt";
//    cout << "Welcome to Word Tic-Tac-Toe!" << endl;
//
//
//    Player<char>* players[2];
//    Board <char> * B = new WordTicTacToe <char> board(3, 3, dict_file);
//
//
//    string player1Name, player2Name;
//
//    cout << "Welcome to Pyramic Tic-Tac-Toe Game. :)\n";
//
//    // Set up player 1
//    switch(valid_choice("1")) {
//        case 1:
//            cout << "Enter Player 1 name:";
//            cin >> player1Name;
//            players[0] = new Pyramid_Player <char> (player1Name, 'X');
//            break;
//        case 2:
//            players[0] = new Pyramid_Random_Player <char> ('X');
//            break;
//        default:
//            cout << "Invalid choice for Player 1. Exiting the game.\n";
//            return 1;
//    }
//
//    players[0]->setBoard(B);
//
//    // Set up player 2
//    switch(valid_choice("2")) {
//        case 1:
//            cout << "Enter Player 2 name:";
//            cin >> player2Name;
//            players[1] = new Pyramid_Player <char>(player2Name, 'O');
//            break;
//        case 2:
//            players[1] = new Pyramid_Random_Player<char>('O');
//            break;
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
//
//
//
//
//
//    player1.setBoard(&board);
//    player2.setBoard(&board);
//
//    int x, y;
//    int turn = 0;
//
//    board.display_board();
//    while (!board.game_is_over()) {
//        Player<char>* currentPlayer = players[turn];
//
//        currentPlayer->getmove(x, y);
//
//        while (!board.update_board(x, y, currentPlayer->getsymbol())) {
//            cout << "Invalid move! The position is either out of bounds or already occupied." << endl;
//            currentPlayer->getmove(x, y);
//        }
//
//        board.display_board();
//
//        if (board.is_win()) {
//            cout << currentPlayer->getname() << " wins by forming a valid word!" << endl;
//            return 0;
//        }
//
//        // Check for a draw
//        if (board.is_draw()) {
//            cout << "The game ends in a draw!" << endl;
//            return 0;
//        }
//
//        turn = 1 - turn;
//    }
    cout << "Welcome to Word Tic-Tac-Toe Game! :)\n";

    // Game parameters
    int rows = 3, cols = 3; // Fixed board dimensions
    string dictionary_file = "dict.txt"; // File containing valid 3-letter words

    // Initialize board
    Board<char>* B = new WordTicTacToe<char>(rows, cols, dictionary_file);

    Player<char>* players[2];
    string player1Name, player2Name;

    // Set up Player 1
    switch (valid_choice("1")) {
        case 1: {
            cout << "Enter Player 1 name: ";
            cin >> player1Name;
            players[0] = new HumanPlayer<char>(player1Name);
            break;
        }
        case 2: {
            players[0] = new ConcreteRandomPlayer<char>('X', rows);
            break;
        }
        default: {
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            delete B;
            return 1;
        }
    }
    players[0]->setBoard(B);

    // Set up Player 2
    switch (valid_choice("2")) {
        case 1: {
            cout << "Enter Player 2 name: ";
            cin >> player2Name;
            players[1] = new HumanPlayer<char>(player2Name);
            break;
        }
        case 2: {
            players[1] = new ConcreteRandomPlayer<char>('O', rows);
            break;
        }
        default: {
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            delete players[0];
            delete B;
            return 1;
        }
    }
    players[1]->setBoard(B);

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    cout << "Thank you for playing Word Tic-Tac-Toe!\n";
    return 0;
}

int game5() {
    cout << "\nYou chose Game 5!" << endl;
    Player<int>* players[2];
    Board <int> * B = new Numerical_Tic_Tac_Toe_Board <int>;

    string player1Name, player2Name;

    cout << "Welcome to Numerical_Tic_Tac_Toe Game. :)\n";

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new Numerical_Tic_Tac_Toe_player <int> (player1Name,0);
            break;
        case 2:
            players[0] = new Numerical_Tic_Tac_Toe_random_player <int> (0) ;
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    players[0]->setBoard(B);

    // Set up player 2


    switch(valid_choice("2")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player2Name;
            players[1] = new Numerical_Tic_Tac_Toe_player <int>(player2Name, 0);
            break;
        case 2:
            players[1] = new Numerical_Tic_Tac_Toe_random_player<int>(0);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }
    players[1]->setBoard(B);

    // Create the game manager and run the game
    GameManager<int> x_o_game (B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}

int game6() {
    cout << "\nYou chose Game 6!" << endl;
    Player<char>* players[2];
    auto* B = new X6_O6_Board<char>();


    string playerXName, player2Name;

    cout << "Welcome to Misere Tic Tac Toe Game. :)\n";

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            players[0] = new X6_O6_Player<char>(playerXName, 'X');
        break;
        case 2:
//            players[0] = new X6_O6_Random_Player<char>(playerXName,'X');          ////////////////////
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }

    // Set up player 2


    switch(valid_choice("2")) {
        case 1:
            players[1] = new X_O_Player<char>(player2Name, 'O');
        break;
        case 2:
//            players[1] = new X_O_Random_Player<char>(player2Name,'O');
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return 1;
    }

    // Create the game manager and run the game

    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}

int game7() {
    cout << "\nYou chose Game 7!" << endl;
    Player<char>* players[2];
    Board <char> * B = new _4x4_Tic_Tac_Toe_Board <char>();

    string player1Name, player2Name;

    cout << "Welcome to 4 x 4 Tic-Tac-Toe Game. :)\n";

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new _4x4_Tic_Tac_Toe_Player <char> (player1Name, 'X');
            break;
        case 2:
            players[0] = new _4x4_Tic_Tac_Toe_Random_Player <char> ('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    players[0]->setBoard(B);

    // Set up player 2

    switch(valid_choice("2")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player2Name;
            players[1] = new _4x4_Tic_Tac_Toe_Player <char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new _4x4_Tic_Tac_Toe_Random_Player<char>('O');
            break;
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

int game8() {
    cout << "\nYou chose Game 8!" << endl;
    Player<char>* players[2];
    auto* B = new Ultimate_Board<char>();


    string playerXName, player2Name;

    cout << "Welcome to Ultimate tic tac toe Game. :)\n";

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            players[0] = new X_O_Player<char>(playerXName, 'X');
        break;
        case 2:
//            players[0] = new X_O_Random_Player<char>(playerXName,'X');
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }

    // Set up player 2


    switch(valid_choice("2")) {
        case 1:
            players[1] = new X_O_Player<char>(player2Name, 'O');
        break;
        case 2:
//            players[1] = new X_O_Random_Player<char>(player2Name,'O');
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return 1;
    }

    // Create the game manager and run the game

    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}

int valid_choice(string player_num = ""){
    int choice;
    while (true) {
        cout << "Choose Player " << player_num << " type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;

        // Check if input is valid
        if (cin.fail()) {
            cin.clear();                     // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input. Please enter valid choice.\n";
        } else {
            break; // Exit loop if input is valid
        }
    }
    return choice;
}