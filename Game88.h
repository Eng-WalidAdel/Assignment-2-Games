
#ifndef _GAME88_H
#define _GAME88_H

#include <iomanip>

#include "BoardGame_Classes.h"

template <typename T>
class X5_O5_Board:public Board<T> {
public:
    X5_O5_Board ();
    bool update_board (int x , int y , T mark) override;
    void display_board () override;
    bool is_win() override ;
    bool is_draw() override;
    bool game_is_over() override;
    int x_score();
    int y_score();
    int countX=0;
    int countY=0;


};

// player
template <typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T>{
public:
    X_O_Random_Player (string name ,T symbol);
    void getmove(int &x, int &y) ;
};


//========================== IMPLEMENTATION ===========================================
template <typename T>
X5_O5_Board<T>::X5_O5_Board() {
    this->rows = this->columns = 5;
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
bool X5_O5_Board<T>::update_board(int x, int y, T mark)  {
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
void X5_O5_Board<T>::display_board()  {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template <typename T>

bool X5_O5_Board<T>::is_win()  {

    static bool p2_win = false;
    if (p2_win) {
        return true;
    }
    if (this->n_moves < 23) {
        return false;
    }

    if (x_score() > y_score()) {
        return true;
    }
    if (y_score() > x_score()) {
        p2_win = true;
        return false;
    }
    return false;

}

bool isValid_board(int x, int y) {

}


template <typename T>
bool X5_O5_Board<T>::is_draw() {
    if (this->n_moves == 25) {return true;}
    return (this->n_moves >= 24 && !is_win());
}
template<typename T>
bool X5_O5_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template<typename T>
int X5_O5_Board<T>::x_score() {
    countX=0;
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns - 2; ++j) {
            if (this->board[i][j] != 0 &&this->board[i][j]=='X'&&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                countX++;
                }
        }
    }

    for (int i = 0; i < this->rows - 2; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            if (this->board[i][j] != 0 &&this->board[i][j]=='X'&&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {
                countX++;
                }
        }
    }
    // check diagonals
    for (int i = 0; i < this->rows - 2; ++i) {
        for (int j = 0; j < this->columns - 2; ++j) {
            if (this->board[i][j] != 0 &&this->board[i][j]=='X'&&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2]) {
                countX++;
                }
        }
    }

    for (int i = 0; i < this->rows - 2; ++i) {
        for (int j = 2; j < this->columns; ++j) {
            if (this->board[i][j] != 0 &&this->board[i][j]=='X'&&
                this->board[i][j] == this->board[i + 1][j - 1] &&
                this->board[i][j] == this->board[i + 2][j - 2]) {
                countX++;
                }
        }
    }
    return countX;
}

template<typename T>
int X5_O5_Board<T>::y_score() {
    countY=0;
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns - 2; ++j) {
            if (this->board[i][j] != 0 &&this->board[i][j]=='O'&&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                countY++;
                }
        }
    }

    for (int i = 0; i < this->rows - 2; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            if (this->board[i][j] != 0 &&this->board[i][j]=='O'&&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {
                countY++;
                }
        }
    }
    // check diagonals
    for (int i = 0; i < this->rows - 2; ++i) {
        for (int j = 0; j < this->columns - 2; ++j) {
            if (this->board[i][j] != 0 &&this->board[i][j]=='O'&&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2]) {
                countY++;
                }
        }
    }

    for (int i = 0; i < this->rows - 2; ++i) {
        for (int j = 2; j < this->columns; ++j) {
            if (this->board[i][j] != 0 &&this->board[i][j]=='O'&&
                this->board[i][j] == this->board[i + 1][j - 1] &&
                this->board[i][j] == this->board[i + 2][j - 2]) {
                countY++;
                }
        }
    }
    return countY;
}

// player section
template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(string name,T symbol) : RandomPlayer<T>(name,symbol) {
    this->dimension = 5;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}


#endif