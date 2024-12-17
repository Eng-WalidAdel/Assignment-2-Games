#ifndef ASSIGNMENT_DEMO_CONNECT_FOUR_H
#define ASSIGNMENT_DEMO_CONNECT_FOUR_H


#include "BoardGame_Classes.h"

template <typename T>
class Four_in_a_row_Board : public Board<T> {  ///////////
public:

    Four_in_a_row_Board();

    ~Four_in_a_row_Board();

    void display_board();

    bool update_board(int x, int y, T symbol);

    bool is_win();

    bool is_draw();

    bool game_is_over();


};


template <typename T>
class Four_in_a_row_player : public Player <T> {
public:

    Four_in_a_row_player (string name, T symbol);

    void getmove(int& x , int& y);

};

template <typename T>

class Four_in_a_row_random_player : public RandomPlayer <T> {
protected:
    int dimension_x{} , dimension_y{};
public:

    Four_in_a_row_random_player (string name,T symbol);

    void getmove(int& x, int& y);
};

//================================ *** Implementation ***  =====================================================
#include <bits/stdc++.h>
using namespace std;


template <typename T>
Four_in_a_row_Board <T> :: Four_in_a_row_Board() {
    this->rows = 6;
    this->columns = 7;
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
Four_in_a_row_Board<T>::~Four_in_a_row_Board() {
    for (int i = 0; i < this->rows; ++i) {
        delete[] this->board[i]; // Deallocate each row
    }
    delete[] this->board; // Deallocate row pointers
    this->board = nullptr; // Avoid dangling pointer
}



template <typename T>
void Four_in_a_row_Board<T>::display_board() {
    cout << "\n ";
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
}


template <typename T>
bool Four_in_a_row_Board<T> :: update_board(int x, int y, T mark) {
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

bool Four_in_a_row_Board<T>::is_win() {

    // Check horizontally
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j <= this->columns - 4; ++j) { // Ensure room for 4 in a row
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2] &&
                this->board[i][j] == this->board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check vertically
    for (int j = 0; j < this->columns; ++j) {
        for (int i = 0; i <= this->rows - 4; ++i) { // Ensure room for 4 in a column
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j] &&
                this->board[i][j] == this->board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check diagonally (left-to-right)
    for (int i = 0; i <= this->rows - 4; ++i) {
        for (int j = 0; j <= this->columns - 4; ++j) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] &&
                this->board[i][j] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check diagonally (right-to-left)
    for (int i = 0; i <= this->rows - 4; ++i) {
        for (int j = 3; j < this->columns; ++j) { // Start from column index 3
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j - 1] &&
                this->board[i][j] == this->board[i + 2][j - 2] &&
                this->board[i][j] == this->board[i + 3][j - 3]) {
                return true;
            }
        }
    }

    // No win condition found
    return false;
}


template <typename T>
bool Four_in_a_row_Board<T>::is_draw() {
    return (this->n_moves == 42 && !is_win());
}

template <typename T>
bool Four_in_a_row_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//========================================================================

template <typename T>
Four_in_a_row_player <T> :: Four_in_a_row_player (string name, T symbol) : Player<T> (name, symbol) {}


template <typename T>
void Four_in_a_row_player <T> ::  getmove (int& x , int& y)
{
    bool not_valid = true;
    while (not_valid)
    {
        while (true) {
            cout << "\nPlease, enter the column number (from 0 to 6) you want to play in:";          // Defensive here
            cin >> y;

            // Check if input is valid
            if (cin.fail() ||  y < 0 || y > 6) {
                cin.clear();                     // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "\nInvalid input. Please enter valid column number.\n";
            } else {
                break; // Exit loop if input is valid
            }
        }

        x = -1;
        while (this->boardPtr->update_board(x + 1 , y , this->symbol)){
            this->boardPtr->update_board(x + 1 , y , 0);
            x++;
        }
        if(x != -1)
        {
            not_valid = false;
        }
        cout << "\nInvalid input. The column is full.\n";
    }

}
//===================================================================

// Constructor for X_O_Random_Player
template <typename T>
Four_in_a_row_random_player<T> :: Four_in_a_row_random_player (string name,T symbol) : RandomPlayer<T>(name,symbol)  {
    this->dimension_x = 6;
    this->dimension_y = 7;
    this->name = "\nRandom Computer Player";
    srand( static_cast <unsigned int> (time(0)) );  // Seed the random number generator
}


template <typename T>
void Four_in_a_row_random_player<T>::getmove(int& x, int& y) {

    cout << this->name << "'s turn!" << endl;
    bool not_valid = true;
    while (not_valid)
    {
        y = rand() % this->dimension_y;
        x = -1;
        while (this->boardPtr->update_board(x + 1 , y , 'O')){
            this->boardPtr->update_board(x + 1 , y , 0);
            x++;
        }
        if(x != -1)
        {
            not_valid = false;
        }
    }
}


#endif //ASSIGNMENT_DEMO_CONNECT_FOUR_H