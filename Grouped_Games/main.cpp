#include "Word_Tic_Tc_Toe.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string dict_file = "\"D:\\oop\\Word_Tic_Tac_Toe\\dic.txt";
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

    return 0;
}
