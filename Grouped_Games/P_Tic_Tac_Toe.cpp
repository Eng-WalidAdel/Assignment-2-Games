#include "Pyramid_Tic_Tac_Toe.h"
#include <iostream>
using namespace std;
//sara
int main() {
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

    return 0;
}
