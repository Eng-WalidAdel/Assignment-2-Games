
#include <bits/stdc++.h>
#include "Word_Tic_Tc_Toe.h"
#include "Pyramid_Tic_Tac_Toe.h"
#include "Connect_Four.h"
#include "Numerical_Tic-Tac-Toe.h"
#include "4 x 4 Tic-Tac-Toe.h"
using namespace std;

void game1();
int game2();
int game3();
int game4();
int game5();
int game6();
int game7();
int game8();

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

        displayMenu();
        cin >> choice;

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

void game1() {
    cout << "\nYou chose Game 1!" << endl;
    Pyramid_Board<char> board;

    string player1_name, player2_name;
    cout << "Enter Player 1 name: ";
    cin >> player1_name;
    Pyramid_Player<char> player1(player1_name, 'X');

    cout << "Enter Player 2 name (or type 'AI' for a random player): ";
    cin >> player2_name;

    Player<char>* player2;
    if (player2_name == "AI") {
        player2 = new Pyramid_Random_Player<char>('O');
    } else {
        player2 = new Pyramid_Player<char>(player2_name, 'O');
    }

    cout << "\nGame Instructions:\n";
    cout << "1. The board positions are shown as (row,col).\n";
    cout << "2. To make a move, input the row and column numbers (e.g., 2 3).\n";
    cout << "3. The game ends when a player wins or the board is full.\n";
    cout << "Let's start!\n";

    bool game_over = false;
    Player<char>* current_player = &player1;
    int x, y;

    while (!game_over) {
        board.display_board();
        cout << current_player->getname() << "'s turn (symbol: " << current_player->getsymbol() << ")\n";
        current_player->getmove(x, y);

        if (!board.update_board(x, y, current_player->getsymbol())) {
            cout << "Invalid move! Position already taken or out of bounds. Try again.\n";
            continue;
        }

        if (board.is_win()) {
            board.display_board();
            cout << current_player->getname() << " wins!\n";
            game_over = true;
        } else if (board.is_draw()) {
            board.display_board();
            cout << "It's a draw!\n";
            game_over = true;
        } else {
            current_player = (current_player == &player1) ? player2 : &player1;
        }
    }

    if (player2_name == "AI") {
        delete player2;
    }

}

int game2() {
    cout << "\nYou chose Game 2!" << endl;
    Player<char>* players[2];
    Board <char> * B = new Four_in_a_row_Board <char>();

    int choice;
    string player1Name, player2Name;

    cout << "Welcome to Connect Four X-O Game. :)\n";

    // Set up player 1
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
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
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter Player 1 name:";
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
    cout << "\nYou chose Game 3!" << endl;
    // Add game logic here
}

int game4() {
    cout << "\nYou chose Game 4!" << endl;
    string dict_file = "dic.txt";
    cout << "Welcome to Word Tic-Tac-Toe!" << endl;

    WordTicTacToe<char> board(3, 3, dict_file);

    HumanPlayer<char> player1("Player 1");
    HumanPlayer<char> player2("Player 2");
    Player<char>* players[2] = { &player1, &player2 };

    player1.setBoard(&board);
    player2.setBoard(&board);

    int x, y;
    int turn = 0;

    board.display_board();
    while (!board.game_is_over()) {
        Player<char>* currentPlayer = players[turn];

        currentPlayer->getmove(x, y);

        while (!board.update_board(x, y, currentPlayer->getsymbol())) {
            cout << "Invalid move! The position is either out of bounds or already occupied." << endl;
            currentPlayer->getmove(x, y);
        }

        board.display_board();

        if (board.is_win()) {
            cout << currentPlayer->getname() << " wins by forming a valid word!" << endl;
            return 0;
        }

        // Check for a draw
        if (board.is_draw()) {
            cout << "The game ends in a draw!" << endl;
            return 0;
        }

        turn = 1 - turn;
    }
}

int game5() {
    cout << "\nYou chose Game 5!" << endl;
    Player<int>* players[2];
    Board <int> * B = new Numerical_Tic_Tac_Toe_Board <int>;

    int choice;
    string player1Name, player2Name;

    cout << "Welcome to Numerical_Tic_Tac_Toe Game. :)\n";

    // Set up player 1
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
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
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
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
    // Add game logic here
}

int game7() {
    cout << "\nYou chose Game 7!" << endl;
    Player<char>* players[2];
    Board <char> * B = new _4x4_Tic_Tac_Toe_Board <char>();

    int choice;
    string player1Name, player2Name;

    cout << "Welcome to 4 x 4 Tic-Tac-Toe Game. :)\n";

    // Set up player 1
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
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
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    players[0]->setBoard(B);

    // Set up player 2
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
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
    // Add game logic here
}
