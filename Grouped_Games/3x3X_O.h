#ifndef _SUS_GAME_H
#define _SUS_GAME_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <vector>
using namespace std;

class SUSBoard : public Board<char> {
private:
    vector<vector<char>> board;
    int susCountPlayer1 = 0;
    int susCountPlayer2 = 0;

public:
    SUSBoard(int rows, int cols) {
        this->rows = rows;
        this->columns = cols;
        board = vector<vector<char>>(rows, vector<char>(cols, ' '));
    }

    bool update_board(int x, int y, char symbol) override {
        // Check if the move is within bounds and the cell is empty
        if (x < 0 || x >= rows || y < 0 || y >= columns || board[x][y] != ' ') {
            return false; // Invalid move
        }
        board[x][y] = symbol; // Place the player's symbol
        return true;
    }

    void display_board() override {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << "\n";
            for (int k = 0; k < columns; ++k) cout << "---";
            cout << "\n";
        }
    }

    bool is_win() override {
        return false; // Winning is based on points, not single win condition.
    }

    bool is_draw() override {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

    bool game_is_over() override {
        return is_draw();
    }

    int count_SUS_sequences() {
        int susCount = 0;

        // Check rows for "S-U-S"
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j <= columns - 3; ++j) {
                if (board[i][j] == 'S' && board[i][j + 1] == 'U' && board[i][j + 2] == 'S') {
                    ++susCount;
                }
            }
        }

        // Check columns for "S-U-S"
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == 'S' && board[i + 1][j] == 'U' && board[i + 2][j] == 'S') {
                    ++susCount;
                }
            }
        }

        // Check diagonals for "S-U-S"
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= columns - 3; ++j) {
                if (board[i][j] == 'S' && board[i + 1][j + 1] == 'U' && board[i + 2][j + 2] == 'S') {
                    ++susCount;
                }
            }
        }

        // Check anti-diagonals for "S-U-S"
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 2; j < columns; ++j) {
                if (board[i][j] == 'S' && board[i + 1][j - 1] == 'U' && board[i + 2][j - 2] == 'S') {
                    ++susCount;
                }
            }
        }

        return susCount;
    }


    void update_scores(int player, int x, int y) {
        // Save the current count of "S-U-S" sequences
        int previousCount = count_SUS_sequences();

        // Simulate the current move
        char previousSymbol = board[x][y]; // Save the previous symbol at this position
        board[x][y] = (player == 1) ? 'S' : 'U';

        // Recalculate the number of "S-U-S" sequences after the move
        int newCount = count_SUS_sequences();

        // Restore the original board state (undo simulation)
        board[x][y] = previousSymbol;

        // Increment only the current player's score if new sequences were added
        if (player == 1) {

            susCountPlayer1 += ( previousCount) - (newCount-1);
        } else if (player == 2) {
            susCountPlayer2 += (newCount - previousCount);
        }
    }


    int getScore(int player) {
        return player == 1 ? susCountPlayer1 : susCountPlayer2;
    }
};

class SUSPlayer : public Player<char> {
public:
    SUSPlayer(string name, char symbol) : Player(name, symbol) {}

    void getmove(int& x, int& y) override {
        cout << this->name << "'s turn. Enter row and column: ";
        cin >> x >> y;
    }
};

#endif //_SUS_GAME_H