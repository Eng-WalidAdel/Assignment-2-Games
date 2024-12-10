//
// Created by MOSTAFA on 12/10/2024.
//

#ifndef ASSIGNMENT_DEMO_CONNECT_FOUR_H
#define ASSIGNMENT_DEMO_CONNECT_FOUR_H


#include "BoardGame_Classes.h"

template <typename T>
class Numerical_Tic_Tac_Toe_Board : public Board<T> {  ///////////
public:

    Numerical_Tic_Tac_Toe_Board();

    ~Numerical_Tic_Tac_Toe_Board();

    void display_board();

    bool update_board(int x, int y, T symbol);

    bool is_win();

    bool is_draw();

    bool game_is_over();


};


template <typename T>
class Numerical_Tic_Tac_Toe_player : public Player <T> {
public:

    Numerical_Tic_Tac_Toe_player (string name, T symbol);

    void getmove(int& x , int& y);

};

template <typename T>

class Numerical_Tic_Tac_Toe_random_player : public RandomPlayer <T> {
public:

    Numerical_Tic_Tac_Toe_random_player (T symbol);

    void getmove(int& x, int& y);
};

//================================ *** Implementation ***  =====================================================
#include <bits/stdc++.h>
using namespace std;


template <typename T>
Numerical_Tic_Tac_Toe_Board <T> :: Numerical_Tic_Tac_Toe_Board() {
    this->rows = 3;
    this->columns = 3;
    this->board = new char*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}


template <typename T>
Numerical_Tic_Tac_Toe_Board<T>::~Numerical_Tic_Tac_Toe_Board() {
    for (int i = 0; i < this->rows; ++i) {
        delete[] this->board[i]; // Deallocate each row
    }
    delete[] this->board; // Deallocate row pointers
    this->board = nullptr; // Avoid dangling pointer
}


template <typename T>
void Numerical_Tic_Tac_Toe_Board<T>::display_board() {
    cout << "  ";
    for (int j = 0; j < this->columns; ++j) {
        cout << " " << j << "  ";
    }
    cout << endl;

    for (int i = 0; i < this->rows; ++i) {
        cout << "| ";
        for (int j = 0; j < this->columns; ++j) {
            char cell = this->board[i][j];
            cout << (cell == 0 ? ' ' : cell) << " | ";
        }
        cout << "\n" << string(4 * this->columns + 1, '-') << endl;
    }
    cout << endl;
}


template <typename T>
bool Numerical_Tic_Tac_Toe_Board<T>:: update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

template <typename T>

bool Numerical_Tic_Tac_Toe_Board<T>::is_win() {

    // Check horizontally
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] + this->board[i][1] + this->board[i][2] == 15 && this->board[i][0] != 0) ||
            (this->board[0][i] + this->board[1][i] + this->board[2][i] == 15 && this->board[0][i] != 0)) {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] + this->board[1][1] + this->board[2][2] == 15 && this->board[0][0] != 0) ||
        (this->board[0][2] + this->board[1][1] + this->board[2][0] == 15 && this->board[0][2] != 0)) {
        return true;
    }

    return false;
}


template <typename T>
bool Numerical_Tic_Tac_Toe_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Numerical_Tic_Tac_Toe_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//========================================================================

template <typename T>

Numerical_Tic_Tac_Toe_player <T> :: Numerical_Tic_Tac_Toe_player (string name, T symbol) : Player<T> (name, symbol) {}


template <typename T>
void Numerical_Tic_Tac_Toe_player <T> ::  getmove (int& x , int& y)
{
    cout << "Please, enter the column number (from 0 to 6) you want to play in: ";          // Defensive here
    cin >> y;

    while (this -> board[0][y] != 0){
        cout << "The column number you entered is full!!" << endl;
        cout << "Please, enter again: ";                                                   // Defensive here
        cin >> y;
    }

    for (int i = 1; i <= this -> row; ++i) {

        if (this -> board[i][y] != 0 || i == (this -> row) ){
            x = i - 1;
        }
    }

}


//===================================================================

// Constructor for X_O_Random_Player
template <typename T>
Numerical_Tic_Tac_Toe_random_player<T> :: Numerical_Tic_Tac_Toe_random_player (T symbol) : RandomPlayer<T>(symbol)  {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}


template <typename T>
void Numerical_Tic_Tac_Toe_random_player<T>::getmove(int& x, int& y) {
    do {
        y = rand() % this->dimension_y; // Random column
        if (this->boardPtr->board[0][y] == 0) {
            break; // Column is valid
        }
    } while (true);

    // Find the lowest available row
    for (int i = this->boardPtr->rows - 1; i >= 0; --i) {
        if (this->boardPtr->board[i][y] == 0) {
            x = i;
            break;
        }
    }
}


#endif //ASSIGNMENT_DEMO_NUMERICAL_TIC_TAC_TOE_H
