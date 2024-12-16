//
// Created by MOSTAFA on 12/13/2024.
//
#include <bits/stdc++.h>
#ifndef ASSIGNMENT_DEMO_4_X_4_TIC_TAC_TOE_H
#define ASSIGNMENT_DEMO_4_X_4_TIC_TAC_TOE_H


#include "BoardGame_Classes.h"
static bool X_player = true;
template <typename T>

class _4x4_Tic_Tac_Toe_Board :public Board<T> {

public:
    _4x4_Tic_Tac_Toe_Board();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>

class _4x4_Tic_Tac_Toe_Player : public Player<T> {
protected:
    vector < pair<int,int> > current_coordinates ;
public:
    _4x4_Tic_Tac_Toe_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>

class _4x4_Tic_Tac_Toe_Random_Player : public RandomPlayer<T>{
protected:
    vector < pair<int,int> > current_coordinates ;
public:

    _4x4_Tic_Tac_Toe_Random_Player(string name, T symbol);

    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION



using namespace std;

// Constructor for X_O_Board
template <typename T>
_4x4_Tic_Tac_Toe_Board<T>::_4x4_Tic_Tac_Toe_Board() {

    this->rows = this->columns = 4;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;


    update_board(0,1,'X');
    update_board(0,3,'X');
    update_board(3,0,'X');
    update_board(3,2,'X');


    update_board(0,0,'O');
    update_board(0,2,'O');
    update_board(3,1,'O');
    update_board(3,3,'O');

}

template <typename T>
bool _4x4_Tic_Tac_Toe_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
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

// Display the board and the pieces on it
template <typename T>
void _4x4_Tic_Tac_Toe_Board<T>::display_board() {
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

// Returns true if there is any winner
template <typename T>
bool _4x4_Tic_Tac_Toe_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        // Row check
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3] && this->board[i][1] != 0) ||
            // Column check
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0) ||
            (this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i] && this->board[1][i] != 0))
        {
            return true;
        }
    }

    // Check diagonals
    // Top-left to bottom-right diagonal
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[1][1] == this->board[2][2] && this->board[2][2] == this->board[3][3] && this->board[1][1] != 0) ||

        (this->board[0][1] == this->board[0][2] && this->board[0][2] == this->board[0][3] && this->board[0][1] != 0) ||
        (this->board[1][0] == this->board[2][1] && this->board[2][1] == this->board[3][2] && this->board[1][0] != 0) ||
        // Bottom-left diagonal to top-right.
        (this->board[3][0] == this->board[2][1] && this->board[2][1] == this->board[1][2] && this->board[3][0] != 0) ||
        (this->board[2][1] == this->board[1][2] && this->board[1][2] == this->board[0][3] && this->board[2][1] != 0) ||

        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0) ||
        (this->board[3][1] == this->board[2][2] && this->board[2][2] == this->board[1][3] && this->board[3][1] != 0))
    {
        return true;
    }

    return false;
}


// Return true if 9 moves are done and no winner
template <typename T>
bool _4x4_Tic_Tac_Toe_Board<T>::is_draw() {
//    return (this->n_moves == 20 && !is_win());
    return false;
}

template <typename T>
bool _4x4_Tic_Tac_Toe_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for _4x4_Tic_Tac_Toe_Player
template <typename T>
_4x4_Tic_Tac_Toe_Player<T>::_4x4_Tic_Tac_Toe_Player(string name, T symbol) : Player<T>(name, symbol) {
    if (X_player)
    {
        this->current_coordinates = {{0, 1}, {0, 3}, {3, 0}, {3, 2}};
    }
    else
    {
        this->current_coordinates = {{0, 0}, {0, 2}, {3, 1}, {3, 3}};
    }
    X_player = !X_player;
}

template <typename T>
void _4x4_Tic_Tac_Toe_Player<T>::getmove(int& x, int& y) {

    bool not_valid = true;
    int current_X , current_Y;
    vector <pair<int , int>> possible_moves;


    while (not_valid) {

        bool no_moves = true;

        cout << "\nPlease enter your symbol's position you want to play with , x and y (0 to 3) separated by spaces:";
        cin >> current_X >> current_Y ;

        // Check if input is valid
        if (cin.fail() || current_X < 0 || current_X > 3 || current_Y < 0 || current_Y > 3) {
            cin.clear();                     // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input. Please enter valid coordinates (0, 1, 2 or 3).\n";
            continue;
        }

        if (this->boardPtr->update_board(current_X,current_Y + 1,this->symbol))
        {
            this->boardPtr->update_board(current_X,current_Y + 1,0);
            possible_moves.emplace_back(current_X,current_Y + 1);
            no_moves = false;
        }
        if (this->boardPtr->update_board(current_X,current_Y - 1,this->symbol))
        {
            this->boardPtr->update_board(current_X,current_Y - 1,0);
            possible_moves.emplace_back(current_X,current_Y - 1);
            no_moves = false;
        }
        if (this->boardPtr->update_board(current_X + 1,current_Y ,this->symbol))
        {
            this->boardPtr->update_board(current_X + 1,current_Y ,0);
            possible_moves.emplace_back(current_X + 1,current_Y);
            no_moves = false;
        }
        if (this->boardPtr->update_board(current_X - 1,current_Y ,this->symbol))
        {
            this->boardPtr->update_board(current_X - 1,current_Y ,0);
            possible_moves.emplace_back(current_X - 1,current_Y);
            no_moves = false;
        }
        if (no_moves) {
            cout << "\nThe selected symbol's coordinates can not be moved. Please enter a different coordinates or for other problems.";
//            possible_moves.clear();
            continue;
        }


        // The entered position symbol is in my current coordinates or not?
        for (int i = 0; i < this->current_coordinates.size(); ++i) {

            if ( this->current_coordinates[i] == make_pair(current_X,current_Y) )
            {
                this->current_coordinates.erase(this->current_coordinates.begin() + i);
                not_valid = false;
                break; // Exit loop if input is valid
            }
            else if (i == this->current_coordinates.size() - 1 )
            {
                cout << "\nThe entered coordinate is not one of your current symbol's positions.";
            }

        }

    }

    this->boardPtr->update_board(current_X ,current_Y ,0);

    not_valid = true;

    while (not_valid)
    {
        while (true) {
            cout << "\nPlease enter your coordinates you want to move to , x and y (0 to 3) separated by spaces:";
            cin >> x >> y;

            // Check if input is valid
            if (cin.fail() || x < 0 || x > 3 || y < 0 || y > 3) {
                cin.clear();                     // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "\nInvalid input. Please enter valid coordinates (0, 1, 2 or 3).\n";
            } else {
                break; // Exit loop if input is valid
            }
        }

        for (int i = 0; i < possible_moves.size(); ++i) {

            if (make_pair(x,y) == possible_moves[i]){

                if (this->boardPtr->update_board(x,y,this->symbol) )
                {
                    this->boardPtr->update_board(x,y,0);
                    this->current_coordinates.emplace_back(make_pair(x,y));
                    not_valid = false;
                }
                else {
                    cout << "\nPlease, enter a valid position to move to.";
                    break;
                }
            }

            else if (i == possible_moves.size() - 1)
            {
                cout << "\nPlease, enter a valid position to move to.";
            }

        }


    }
}

// Constructor for _4x4_Tic_Tac_Toe_Random_Player
template <typename T>
_4x4_Tic_Tac_Toe_Random_Player<T>::_4x4_Tic_Tac_Toe_Random_Player(string name,T symbol) : RandomPlayer<T>(name,symbol) {
    this->dimension = 4;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    if (X_player)
    {
        this->current_coordinates = {{0, 1}, {0, 3}, {3, 0}, {3, 2}};
    }
    else
    {
        this->current_coordinates = {{0, 0}, {0, 2}, {3, 1}, {3, 3}};
    }
    X_player = !X_player;
}

template <typename T>
void _4x4_Tic_Tac_Toe_Random_Player<T>::getmove(int& x, int& y) {

    int current_X , current_Y;
    vector <pair<int , int>> possible_moves;

    // Set up a random number generator
    random_device rd;  // Seed for the random number engine
    mt19937 gen(rd()); // Mersenne Twister engine

    while (true){

        bool no_moves = true;

        uniform_int_distribution<> dis1(0, this->current_coordinates.size() - 1); // Distribution for indices

        // Randomly select an element
        int randomIndex = dis1(gen); // Generate a random index

        tie(current_X,current_Y) = this->current_coordinates[randomIndex]; // Get the element at that index

        if (this->boardPtr->update_board(current_X,current_Y + 1,this->symbol))
        {
            this->boardPtr->update_board(current_X,current_Y + 1,0);
            possible_moves.emplace_back(current_X,current_Y + 1);
            no_moves = false;
        }
        if (this->boardPtr->update_board(current_X,current_Y - 1,this->symbol))
        {
            this->boardPtr->update_board(current_X,current_Y - 1,0);
            possible_moves.emplace_back(current_X,current_Y - 1);
            no_moves = false;
        }
        if (this->boardPtr->update_board(current_X + 1,current_Y ,this->symbol))
        {
            this->boardPtr->update_board(current_X + 1,current_Y ,0);
            possible_moves.emplace_back(current_X + 1,current_Y);
            no_moves = false;
        }
        if (this->boardPtr->update_board(current_X - 1,current_Y ,this->symbol))
        {
            this->boardPtr->update_board(current_X - 1,current_Y ,0);
            possible_moves.emplace_back(current_X - 1,current_Y);
            no_moves = false;
        }
        if (no_moves) {
//            cout << "\nThe selected symbol's coordinates can not be moved. Please enter a different coordinates or for other problems.";
//            possible_moves.clear();
            continue;
        }

        this->boardPtr->update_board(current_X,current_Y ,0);
//    this->available_numbers.erase(this->symbol);
        this->current_coordinates.erase(
                remove(this->current_coordinates.begin(), this->current_coordinates.end(), make_pair(current_X,current_Y)),
                this->current_coordinates.end());

        break;
    }

    uniform_int_distribution<> dis2(0, possible_moves.size() - 1); // Distribution for indices
    int randomIndex = dis2(gen); // Generate a random index

    tie(x,y) =  possible_moves[randomIndex];
//    this->boardPtr->update_board(x,y ,this->symbol);
    this->current_coordinates.emplace_back(make_pair(x,y));



}



#endif //ASSIGNMENT_DEMO_4_X_4_TIC_TAC_TOE_H