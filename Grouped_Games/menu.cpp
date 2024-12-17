
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
            cout << endl;

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
    Player<char>* players[2];
    Board <char> * B = new Pyramid_Board <char>();

    string player1Name, player2Name;

    cout << "Welcome to Pyramid Tic-Tac-Toe Game. :)\n";
    cout << endl;
    cout << "Winning: The first player to get three(X,O)-in-a-row vertically, horizontally, or diagonally wins."<<endl;
    cout << endl;

    // Set up player 1
    switch(valid_choice("1")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new Pyramid_Player <char> (player1Name, 'X');
            break;
        case 2:
            players[0] = new Pyramid_Random_Player <char> (player1Name,'X');
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
            players[1] = new Pyramid_Random_Player<char>(player2Name,'O');
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

    Player<char>* players[2];
    Board <char> * B = new Four_in_a_row_Board <char>();


    string player1Name, player2Name;

    cout << "Welcome to Connect Four X-O Game. :)\n";
    cout << endl;
    cout <<"Rules: The first player places an X in the bottom square of any column. Taking turns, players make\ntheir mark in any column, as long as it is in the lowest square possible. See image below for an\n"
           "example of possible first six moves."<<endl;
    cout << endl;
    cout << "Winning: The first player to get four-in-a-row horizontally, or diagonally wins." <<endl;
    cout << endl;

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new Four_in_a_row_player <char> (player1Name, 'X');
            break;
        case 2:
            players[0] = new Four_in_a_row_random_player <char> (player1Name, 'X');
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
            players[1] = new Four_in_a_row_random_player<char>(player2Name, 'O');
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
    cout << endl;
    cout << "Rules: Players take turns placing an X or an O in\n"
            "one of the squares until all the squares except one\n"
            "are filled. (Each player has 12 turns for a total of\n"
            "24 squares.)"<<endl;
    cout << endl;
    cout << "Winning: Count the number of three-in-a-rows\n"
            "each player has. Sequences can be vertically, horizontally, or diagonally. Whoever has the most, wins.\nCan one mark be counted in more than one"
            "three-in-a-row sequence?\nDecide ahead of time, yes or no. It is easier in implementation to allow\n"
            "counting more than once."<<endl;
    cout << endl;

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
            players[1] = new X5_O5_Random_Player<char>(player2Name,'O');
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
    cout << "Welcome to Word Tic-Tac-Toe Game!:)\n";
    cout << endl;
    cout << "Rules: Each player takes turns placing one letter on the\n"
            "board. A player must try to form a valid word with each\n"
            "move. Players can build upon existing letters to form words, provided that the resulting sequence is\n"
            "a valid word."<<endl;
    cout << endl;
    cout << "Winning: The game is won by forming a valid word horizontally, vertically, or diagonally."<<endl;
    // Game parameters
    ifstream file1;
    int rows = 3, cols = 3; // Fixed board dimensions
    string dictionary_file = "dic.txt"; // File containing valid 3-letter words
    file1.open(dictionary_file, ios::in);
    while (!file1){

        if (!file1){

            cout << "The first file name isn't detected!" << endl;
            cout << "Please, enter the first file's name again:" ;
            cin >> dictionary_file ;
            cout << endl;
            file1.open(dictionary_file, ios::in);
        }


    }

    // Initialize board
    Board<char>* B = new WordTicTacToe<char>(rows, cols, dictionary_file);

    Player<char>* players[2];
    string player1Name, player2Name;

    // Set up Player 1
    switch (valid_choice("1")) {
        case 1: {
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new HumanPlayer<char>(player1Name);
            break;
        }
        case 2: {
            players[0] = new ConcreteRandomPlayer<char>(player1Name,'X', rows);
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
            cout << "Enter Player 2 name:";
            cin >> player2Name;
            players[1] = new HumanPlayer<char>(player2Name);
            break;
        }
        case 2: {
            players[1] = new ConcreteRandomPlayer<char>(player2Name,'O', rows);
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
    Player<int>* players[2];
    Board <int> * B = new Numerical_Tic_Tac_Toe_Board <int>;

    string player1Name, player2Name;

    cout << "Welcome to Numerical_Tic_Tac_Toe Game. :)\n";
    cout << endl;
    cout << "Rules: Player 1 typically starts and uses odd numbers\n"
            "(1, 3, 5, 7, 9), while Player 2 uses even numbers (2, 4, 6, 8). Players alternate turns, placing one number in an\n"
            "empty cell on the board. Each number can only be used\n"
            "once." << endl;
    cout << endl;
    cout << "Winning: A player by placing three numbers in a row, column, or diagonal that add up to 15.\n"
            "If cells are filled without achieving the sum of 15 in any line,\nthe game ends in a draw."<<endl;
    cout << endl;

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new Numerical_Tic_Tac_Toe_player <int> (player1Name,0);
            break;
        case 2:
            players[0] = new Numerical_Tic_Tac_Toe_random_player <int> (player1Name, 0) ;
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
            players[1] = new Numerical_Tic_Tac_Toe_random_player<int>(player2Name, 0);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }
    players[1]->setBoard(B);

    // Create the game manager and run the game..
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
    Player<char>* players[2];
    auto* B = new X6_O6_Board<char>();


    string playerXName, player2Name;

    cout << "Welcome to Misere Tic Tac Toe Game. :)\n";
    cout << endl;
    cout << "Rules: The game is played on a standard 3x3 Tic-Tac-Toe\n"
            "grid. The goal is to avoid placing three of your marks in a\n"
            "row, column, or diagonal. The player who ends up with\n"
            "three marks in a row loses the game. If all cells are filled\n"
            "without either player aligning three marks in a row,\nthe"
            "game ends in a draw."<<endl;
    cout << endl;

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
            players[1] = new X6_O6_Player<char>(player2Name, 'O');
        break;
        case 2:
            players[1] = new X6_O6_Random_Player<char>(player2Name,'O');
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
    Player<char>* players[2];
    Board <char> * B = new _4x4_Tic_Tac_Toe_Board <char>();

    string player1Name, player2Name;

    cout << "Welcome to 4 x 4 Tic-Tac-Toe Game. :)\n";
    cout << endl;
    cout << "Rules: Players alternate turns, moving one of their tokens to\n"
            "an immediately adjacent open square. Tokens can be moved\n"
            "horizontally or vertically but not diagonally. Tokens may not jump over other tokens. The goal is to\n"
            "align three of your tokens in a row. This can be achieved\n"
            "horizontally, vertically, or diagonally."<<endl;
    cout << endl;
    cout << "Winning: The first player to get three tokens in a row wins"
            "the game.\nThe alignment can be in any direction: horizontal, vertical, or diagonal."<<endl;
    cout << endl;

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            cout << "Enter Player 1 name:";
            cin >> player1Name;
            players[0] = new _4x4_Tic_Tac_Toe_Player <char> (player1Name, 'X');
            break;
        case 2:
            players[0] = new _4x4_Tic_Tac_Toe_Random_Player <char> (player1Name,'X');
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
            players[1] = new _4x4_Tic_Tac_Toe_Random_Player<char>(player2Name,'O');
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
    Player<char>* players[2];
    auto* B = new Ultimate_Board<char>();


    string playerXName, player2Name;

    cout << "Welcome to Ultimate tic tac toe Game. :)\n";
    cout << endl;
    cout << "Player 1 starts by choosing any of the\n"
            "nine smaller Tic Tac Toe boards to play on. Players alternate turns, playing Tic Tac Toe on"
            "the smaller boards\n.The winner of each smaller"
            "board claims that space on the main board.\nThe"
            "winner of the smaller board replaces that board\n"
            "with their symbol (X or O) on the main board.\n\nWinning: The first player to win three smaller boards in a row on the main 3x3 grid wins the\n"
            "Ultimate Tic Tac Toe game. The winning row on the main board can be horizontal, vertical, or\n"
            "diagonal."<<endl;
    cout << endl;

    // Set up player 1


    switch(valid_choice("1")) {
        case 1:
            players[0] = new X_O_Player<char>(playerXName, 'X');
        break;
        case 2:
            players[0] = new X_O_Random_Player<char>(playerXName,'X');
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
            players[1] = new X_O_Random_Player<char>(player2Name,'O');
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