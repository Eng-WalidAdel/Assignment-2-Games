#ifndef _GAME8_H
#define _GAME8_H

#include <iomanip>
#include <iostream>
#include "BoardGame_Classes.h"  // Assuming this defines Player, RandomPlayer, and the Board class

using namespace std;

template <typename T>
class X_O_Board : public Board<T> {
public:
    X_O_Board boards[3][3];  // 3x3 grid of smaller X_O_Boards
    T winnerSymbol;  // This will track the symbol of the winner
    X_O_Board();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

// Player and RandomPlayer for handling user and random input
template <typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player(string name, T symbol);
    void getmove(int& x, int& y) override;
};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T> {
public:
    X_O_Random_Player(string name, T symbol);
    void getmove(int& x, int& y) override;
};

// X_O_Board Constructor (no dynamic allocation)
template <typename T>
X_O_Board<T>::X_O_Board() {
    this->rows = this->columns = 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            winnerSymbol = ' ';  // Reset each small board
            // boards[i][j] will automatically initialize
        }
    }
}

// Function to update a board (handles 3x3 sections)
template <typename T>
bool X_O_Board<T>::update_board(int x, int y, T symbol) {
    // Determine which smaller board we are targeting
    int smallX = x / 3, smallY = y / 3;
    int posX = x % 3, posY = y % 3;

    if (boards[smallX][smallY].game_is_over()) {
        cout << "This board is already won! Try another.\n";
        return false;
    }

    bool updated = boards[smallX][smallY].update_board(posX, posY, symbol);  // Update the corresponding small board
    if (updated) this->n_moves++;

    return updated;
}

// Display the entire Ultimate Tic-Tac-Toe board
template <typename T>
void X_O_Board<T>::display_board() {
    cout << "\nUltimate Tic Tac Toe Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int r = 0; r < 3; ++r) { // Rows inside small boards
            for (int j = 0; j < 3; ++j) {
                boards[i][j].display_row(r);  // Display each row in small boards
                cout << " | ";
            }
            cout << endl;
        }
        cout << "-------------------------\n";
    }
}

// Check for win condition in a line (row/column/diagonal) for a board
template <typename T>
bool check_line(X_O_Board<T>* b1, X_O_Board<T>* b2, X_O_Board<T>* b3) {
    return (b1->is_win() && b2->is_win() && b3->is_win());
}

// Function to check for a win condition
template <typename T>
bool X_O_Board<T>::is_win() {
    // Check rows, columns, and diagonals for small board victories
    for (int i = 0; i < 3; i++) {
        if (check_line(&boards[i][0], &boards[i][1], &boards[i][2])) return true;
        if (check_line(&boards[0][i], &boards[1][i], &boards[2][i])) return true;
    }

    if (check_line(&boards[0][0], &boards[1][1], &boards[2][2])) return true;
    if (check_line(&boards[0][2], &boards[1][1], &boards[2][0])) return true;

    return false;
}

// Check for a draw condition
template <typename T>
bool X_O_Board<T>::is_draw() {
    return this->n_moves >= 81;  // 81 moves max in Ultimate Tic-Tac-Toe
}

// Function to check if the game is over
template <typename T>
bool X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

// X_O_Player for user input handling
template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move (x and y) separated by spaces (0 to 8): ";
    cin >> x >> y;
}

// X_O_Random_Player for random moves
template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(string name, T symbol) : RandomPlayer<T>(name, symbol) {
    this->dimension = 3;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}

#endif  // _GAME8_H
