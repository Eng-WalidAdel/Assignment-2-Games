#ifndef ASSIGNMENT_DEMO_NUMERICAL_TIC_TAC_TOE_H
#define ASSIGNMENT_DEMO_NUMERICAL_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
static bool odd_player = true;
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
protected:
    vector <int> available_numbers;

public:
    Numerical_Tic_Tac_Toe_player (string name, T symbol);
//    Numerical_Tic_Tac_Toe_player (string name);

    void getmove(int& x , int& y);

};

template <typename T>
class Numerical_Tic_Tac_Toe_random_player : public RandomPlayer <T> {
protected:
    vector <int> available_numbers;
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
    this->board = new int*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new int[this->columns];
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
    cout << "\n   ";
    for (int j = 0; j < this->columns; ++j) {
        cout << "   " << j << "   "; // Column headers
    }
    cout << endl;

    for (int i = 0; i < this->rows; ++i) {
        cout << "  ";
        cout << string(7 * this->columns + 1, '-') << endl; // Row separator

        cout << i << " | "; // Row header
        for (int j = 0; j < this->columns; ++j) {
            // Check the cell content
            T cell = this->board[i][j];
            if (cell == 0) {
                cout << "     | "; // Empty cell
            } else {
                cout << "  " << cell << "  | "; // Display the number
            }
        }
        cout << endl;
    }

    cout << "  " << string(7 * this->columns + 1, '-') << endl; // Final row separator
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
        if ((this->board[i][0] + this->board[i][1] + this->board[i][2] == 15 && this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0) ||
            (this->board[0][i] + this->board[1][i] + this->board[2][i] == 15 && this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0)) {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] + this->board[1][1] + this->board[2][2] == 15 && this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0) ||
        (this->board[0][2] + this->board[1][1] + this->board[2][0] == 15 && this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0)) {
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
Numerical_Tic_Tac_Toe_player <T> :: Numerical_Tic_Tac_Toe_player (string name, T symbol) : Player<T> (name, symbol) {

    if (odd_player)
    {
        this->available_numbers = {1, 3, 5, 7, 9};
    }
    else
    {
        this->available_numbers = {2, 4, 6, 8};
    }
    odd_player = !odd_player;
}

//template <typename T>
//Numerical_Tic_Tac_Toe_player <T> :: Numerical_Tic_Tac_Toe_player (string name) : Player<T> (name) {
//
//    if (odd_player)
//    {
//        this->available_numbers = {1, 3, 5, 7, 9};
//    }
//    else
//    {
//        this->available_numbers = {2, 4, 6, 8};
//    }
//    odd_player = !odd_player;
//}


#include <iostream>
#include <vector>
#include <algorithm> // for std::find and std::remove
using namespace std;

template <typename T>
void Numerical_Tic_Tac_Toe_player<T>::getmove(int& x, int& y) {

    cout << "The number(s) remaining is(are): { " << this->available_numbers[0];
    for (int i = 1; i < this->available_numbers.size(); ++i) {
        cout << ", " << this->available_numbers[i];
    }
    cout << " }" << endl;

    // Loop to get valid x and y coordinates
    while (true) {
        cout << "\nPlease enter your move x and y (0 to 2) separated by spaces:";
        cin >> x >> y;

        // Check if input is valid
        if (cin.fail() || x < 0 || x > 2 || y < 0 || y > 2) {
            cin.clear();                     // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input. Please enter valid coordinates (0, 1, or 2).\n";
        } else {
            break; // Exit loop if input is valid
        }
    }

    // Loop to get a valid number from available_numbers
    while (true) {


        cout << "\nPlease enter the number you want to play with:";
        cin >> this->symbol;

        // Check if the number is in the available_numbers
        if (cin.fail() || find(this->available_numbers.begin(), this->available_numbers.end(), this->symbol) == this->available_numbers.end()) {
            cin.clear();                     // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid number. Please choose a number from the list.\n";
        } else {
            break; // Exit loop if input is valid
        }

        cout << "\nThe number(s) remaining is(are): { " << this->available_numbers[0];
        for (int i = 1; i < this->available_numbers.size(); ++i) {
            cout << ", " << this->available_numbers[i];
        }
        cout << " }" << endl;
    }

    // Remove the selected number from available_numbers
    this->available_numbers.erase(
            remove(this->available_numbers.begin(), this->available_numbers.end(), this->symbol),
            this->available_numbers.end()
    );
}



//===================================================================

// Constructor for X_O_Random_Player
template <typename T>
Numerical_Tic_Tac_Toe_random_player<T> :: Numerical_Tic_Tac_Toe_random_player (T symbol) : RandomPlayer<T>(symbol)  {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int> ( time(0) ));  // Seed the random number generator
    if (odd_player)
    {
        this->available_numbers = {1, 3, 5, 7, 9};
    }
    else
    {
        this->available_numbers = {2, 4, 6, 8};
    }
    odd_player = !odd_player;
}


template <typename T>
void Numerical_Tic_Tac_Toe_random_player<T>::getmove(int& x, int& y) {
    cout << this -> name << "'s turn!" << endl;

    y = rand() % this->dimension;
    x = rand() % this->dimension;


    // Set up a random number generator
    random_device rd;  // Seed for the random number engine
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<> dis(0, this->available_numbers.size() - 1); // Distribution for indices

    // Randomly select an element
    int randomIndex = dis(gen); // Generate a random index

    this->symbol = this->available_numbers[randomIndex]; // Get the element at that index

//    this->available_numbers.erase(this->symbol);
    this->available_numbers.erase(
            remove(this->available_numbers.begin(), this->available_numbers.end(), this->symbol),
            this->available_numbers.end());


}


#endif //ASSIGNMENT_DEMO_NUMERICAL_TIC_TAC_TOE_H