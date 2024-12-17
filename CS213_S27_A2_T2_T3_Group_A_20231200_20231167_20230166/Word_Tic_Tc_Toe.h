#ifndef _WORD_TIC_TAC_TOE_H
#define _WORD_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class HumanPlayer : public Player<T> {
public:
    HumanPlayer(string n) : Player<T>(n, '-') {}

    void getmove(int& x, int& y) override {
        char letter;
        while (true) {
            cout << this->getname() << ", enter your move (row and column):";
            cin >> x >> y;

            // Check if input is valid
            if (cin.fail() ||  x < 0 || x > 2 || y < 0 || y > 2) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "\nInvalid input. Please enter a valid choice (1 or 2).\n";
            } else {
                break; // Exit loop if input is valid
            }
        }

        do {
            cout << "\nEnter the letter you want to place (A-Z or a-z):";
            cin >> letter;

            if (letter >= 'a' && letter <= 'z') {
                letter = letter - 'a' + 'A';
            }

            if (letter >= 'A' && letter <= 'Z') {
                this->symbol = letter;
                break;
            } else {
                cout << "Invalid letter! Please enter a valid alphabetic character (A-Z or a-z)." << endl;
            }
        } while (true);
    }
};

template <typename T>
class WordTicTacToe : public Board<T> {
private:
    unordered_set<string> valid_words;

    string generate_word(int start_x, int start_y, int dx, int dy) {
        string word = "";
        for (int i = 0; i < 3; ++i) {
            int x = start_x + i * dx;
            int y = start_y + i * dy;
            if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y]) {
                word += toupper(this->board[x][y]);
            } else {
                return "";
            }
        }
        return word;
    }


    bool check_for_word(int x, int y) {

        static const vector<pair<int, int>> directions = {
                {0, 1},
                {0, -1},
                {1, 0},
                {-1, 0},
                {1, 1},
                {1, -1},
                {-1, 1},
                {-1, -1}
        };

        for (const auto& [dx, dy] : directions) {
            string word = generate_word(x, y, dx, dy);
            if (word.length() == 3) {
                string reversed_word = word;
                reverse(reversed_word.begin(), reversed_word.end());
                if (valid_words.find(word) != valid_words.end() || valid_words.find(reversed_word) != valid_words.end()) {
                    return true;  // Valid word found
                }
            }
        }
        return false;
    }

public:
    // Constructor
    WordTicTacToe(int rows, int cols, const string& dict_file) {
        this->rows = rows;
        this->columns = cols;
        this->n_moves = 0;

        this->board = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            this->board[i] = new T[cols]{};
        }

        ifstream file(dict_file);
        string word;
        while (getline(file, word)) {
            if (word.length() == 3) {
                for (char& c : word) c = toupper(c);
                valid_words.insert(word);
            }
        }
        file.close();
    }

    ~WordTicTacToe() {
        for (int i = 0; i < this->rows; ++i) {
            delete[] this->board[i];
        }
        delete[] this->board;
    }

    bool update_board(int x, int y, T symbol) override {
        if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && !this->board[x][y]) {
            this->board[x][y] = symbol;
            this->n_moves++;
            return true;
        }
        return false;
    }

    void display_board() override {
        cout << "\nBoard State:\n";
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->columns; ++j) {
                cout << (this->board[i][j] ? this->board[i][j] : '-') << " ";
            }
            cout << endl;
        }
    }

    bool is_win() override {
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->columns; ++j) {
                if (this->board[i][j] && check_for_word(i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool is_draw() override {
        return this->n_moves == this->rows * this->columns && !is_win();
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }
};

// ConcreteRandomPlayer class implementing the pure virtual function 'getmove'
template <typename T>
class ConcreteRandomPlayer : public RandomPlayer<T> {
private:
    int dimension; // Board dimension
public:
    ConcreteRandomPlayer(string name,T symbol, int dim) : RandomPlayer<T>(name,symbol), dimension(dim) {
        srand(static_cast<unsigned int>(time(nullptr))); // Seed random number generator
    }

    void getmove(int& x, int& y) override {
        vector<char> letters;

        // Initialize vector with letters A to Z
        for (char c = 'A'; c <= 'Z'; ++c) {
            letters.push_back(c);
        }
        x = rand() % dimension;  // Generate random row
        y = rand() % dimension;  // Generate random column
        cout << this->getname() << " chooses position (" << x + 1 << ", " << y + 1 << ")" << endl;

        random_device rd;  // Seed for the random number engine
        mt19937 gen(rd()); // Mersenne Twister engine
        uniform_int_distribution<> dis(0, letters.size() - 1); // Distribution for indices

        // Randomly select an element
        int randomIndex = dis(gen); // Generate a random index

        this->symbol = letters[randomIndex]; // Get the element at that index
    }
};

#endif //_WORD_TIC_TAC_TOE_H
