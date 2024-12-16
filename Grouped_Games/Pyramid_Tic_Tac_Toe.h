#ifndef Pyranid_Tic_Tac_Toe_H
#define Pyranid_Tic_Tac_Toe_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

template <typename T>
class Pyramid_Board : public Board<T> {
protected:
    vector<vector<T>> board;

public:
    Pyramid_Board() {
        board = {
                {' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' '}
        };
    }

    void display_board() override {
        cout << "\nCurrent Board:\n";

        cout << "                      " << (board[0][2] == ' ' ? ".(0,2)" : string(1, board[0][2]) + "(0,2)") << endl;

        cout << "             ";
        for (int j = 1; j <= 3; ++j) {
            cout << (board[1][j] == ' ' ? ".(" + to_string(1) + "," + to_string(j) + ")" : string(1, board[1][j]) + "(" + to_string(1) + "," + to_string(j) + ")") << "   ";
        }
        cout << endl;

        cout << "    ";
        for (int j = 0; j < 5; ++j) {
            cout << (board[2][j] == ' ' ? ".(" + to_string(2) + "," + to_string(j) + ")" : string(1, board[2][j]) + "(" + to_string(2) + "," + to_string(j) + ")") << "   ";
        }
        cout << endl;
    }

    bool update_board(int x, int y, T symbol) override {
        if (x < 0 || x >= 3 || y < 0 || y >= 5 || board[x][y] != ' ') {
            return false;
        }
        board[x][y] = symbol;
        return true;
    }

    bool is_win() override {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j <= 2 + i; ++j) {
                if (j + 2 < board[i].size() &&
                    board[i][j] != ' ' &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i][j + 2]) {
                    return true;
                }
            }
        }

        for (int j = 0; j < 5; ++j) {
            if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
                return true;
            }
        }

        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return true;
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][3] && board[0][2] == board[2][4]) {
            return true;
        }

        return false;
    }

    bool is_draw() override {
        for (const auto& row : board) {
            for (T cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return !is_win();
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }
};


template <typename T>
class Pyramid_Player : public Player<T> {
public:
    Pyramid_Player(const string& player_name, T player_symbol) : Player<T>(player_name, player_symbol) {}

    void getmove(int& x, int& y) override {

        while (true) {
            cout << this->name << ", enter your move (row and column): ";
            cin >> x >> y;

            // Check if input is valid
            if (cin.fail() || x < 0 || x > 3 || y < 0 || y > 5) {
                cin.clear();                     // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "\nInvalid input. Please enter valid coordinates.\n";
                continue;
            }

            if ((x == 0 && y == 2) ||
                (x == 1 && y >= 1 && y <= 3) ||
                (x == 2 && y >= 0 && y <= 4)) {
                break; // Valid move
            }
            else {
                cout << "\nInvalid input. Please enter valid coordinates.\n";
            }
        }

    }
};

template <typename T>
class Pyramid_Random_Player : public RandomPlayer<T> {
public:
    Pyramid_Random_Player(T player_symbol) : RandomPlayer<T>(player_symbol) {
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int> ( time(0) ));  // Seed the random number generator
    }

    void getmove(int& x, int& y) override {
        // Ensure random coordinates are within valid bounds for each row
        x = rand() % 3;  // Row index (0, 1, or 2)

        // Based on the row (x), restrict the valid column (y)
        if (x == 0) {
            y = rand() % 1;  // Only 1 column in the top row
        } else if (x == 1) {
            y = rand() % 3;  // 3 columns in the middle row
        } else {
            y = rand() % 5;  // 5 columns in the bottom row
        }

        cout << this->name << " chooses move: (" << x << ", " << y << ")" << endl;
    }
};

#endif


