//
//#include <bits/stdc++.h>
//#include "BoardGame_Classes.h"
//#include "Connect_Four.h"
//using namespace std;
//
//template <typename T>
//Four_in_a_row_Board<T>::Four_in_a_row_Board ()
//{
//    this->rows = 6;
//    this->columns = 7;
//    this->n_moves = 0;
//
//    this->board = make_unique <unique_ptr <T[]> [] > (this->rows);
//    for (int i = 0; i < this->rows; ++i) {
//        this->board[i] = make_unique <T[]> (this->columns);
//    }
//}
//
//
////    Four_in_a_row()
////    {
////        this->rows = 6;
////        this->columns = 7;
////
////        this->board = new T*[this->rows];
////        for (int i = 0; i < this->rows; ++i) {
////            this->board[i] = new T[this->columns]{};
////        }
////    }
////    ~Four_in_a_row() {
////        for (int i = 0; i < this->rows; ++i) {
////            delete[] this->board[i];
////        }
////        delete[] this->board;
////    }
//
//template <typename T>
//
//void Four_in_a_row_Board<T>::display_board() {
//    for (int i = 0; i < this->rows; i++) {
//        cout << "\n| ";
//        for (int j = 0; j < this->columns; j++) {
//            cout << "(" << i << "," << j << ")";
//            cout << setw(2) << this->board[i][j] << " |";
//        }
//        cout << "\n-----------------------------";
//    }
//    cout << endl;
//}
//
//
//template <typename T>
//bool Four_in_a_row_Board<T>:: update_board(int x, int y, T mark) {
//    // Only update if move is valid
//    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
//        if (mark == 0){
//            this->n_moves--;
//            this->board[x][y] = 0;
//        }
//        else {
//            this->n_moves++;
//            this->board[x][y] = toupper(mark);
//        }
//
//        return true;
//    }
//    return false;
//}
//
//template <typename T>
//
//bool Four_in_a_row_Board<T>::is_win() {
//
//    // Check horizontally
//    for (int i = 0; i < this->rows; ++i) {
//        for (int j = 0; j <= this->columns - 4; ++j) { // Ensure room for 4 in a row
//            if (this->board[i][j] != 0 &&
//                this->board[i][j] == this->board[i][j + 1] &&
//                this->board[i][j] == this->board[i][j + 2] &&
//                this->board[i][j] == this->board[i][j + 3]) {
//                return true;
//            }
//        }
//    }
//
//    // Check vertically
//    for (int j = 0; j < this->columns; ++j) {
//        for (int i = 0; i <= this->rows - 4; ++i) { // Ensure room for 4 in a column
//            if (this->board[i][j] != 0 &&
//                this->board[i][j] == this->board[i + 1][j] &&
//                this->board[i][j] == this->board[i + 2][j] &&
//                this->board[i][j] == this->board[i + 3][j]) {
//                return true;
//            }
//        }
//    }
//
//    // Check diagonally (left-to-right)
//    for (int i = 0; i <= this->rows - 4; ++i) {
//        for (int j = 0; j <= this->columns - 4; ++j) {
//            if (this->board[i][j] != 0 &&
//                this->board[i][j] == this->board[i + 1][j + 1] &&
//                this->board[i][j] == this->board[i + 2][j + 2] &&
//                this->board[i][j] == this->board[i + 3][j + 3]) {
//                return true;
//            }
//        }
//    }
//
//    // Check diagonally (right-to-left)
//    for (int i = 0; i <= this->rows - 4; ++i) {
//        for (int j = 3; j < this->columns; ++j) { // Start from column index 3
//            if (this->board[i][j] != 0 &&
//                this->board[i][j] == this->board[i + 1][j - 1] &&
//                this->board[i][j] == this->board[i + 2][j - 2] &&
//                this->board[i][j] == this->board[i + 3][j - 3]) {
//                return true;
//            }
//        }
//    }
//
//    // No win condition found
//    return false;
//}
//
//
//template <typename T>
//bool Four_in_a_row_Board<T>::is_draw() {
//    return (this->n_moves == 42 && !is_win());
//}
//
//template <typename T>
//bool Four_in_a_row_Board<T>::game_is_over() {
//    return is_win() || is_draw();
//}
//
////========================================================================
////template <typename T>
////
////Four_in_a_row_player <T> :: Four_in_a_row_player (string n, T symbol)
////{
////    this->name = n;
////    this->symbol = symbol;
////
////}
//
////template <typename T>
////Four_in_a_row_player <T> :: Four_in_a_row_player (T symbol)
////{
////    this->name = "Computer";
////    this->symbol = symbol;
////}
//
////    string setname(){
////        string player_name;
////        cout << "Please, enter the name you want to play with: ";
////        cin >> player_name;
////        return player_name;
////    }
////
////    T setsymbol(){
////        T player_symbol;
////        cout << "Please, enter the symbol you want to play with: ";
////        cin << player_symbol;
////        return player_symbol;
////    }
//
////template <typename T>
////string Four_in_a_row_player <T> :: getname()
////{
////    return this->name;
////}
////
////template <typename T>
////T Four_in_a_row_player <T> :: getsymbol()
////{
////    return this->symbol;
////}
//
////template <typename T>
////void Four_in_a_row_player<T>::setBoard(Board<T>* b) {
////    this->boardPtr = b;
////}
//
//template <typename T>
//void Four_in_a_row_player <T> ::  getmove (int& x , int& y)
//{
//    cout << "Please, enter the column number (from 0 to 6) you want to play in: ";          // Defensive here
//    cin >> y;
//
//    while (this -> board[0][y] != T()){
//        cout << "The column number you entered is full!!" << endl;
//        cout << "Please, enter again: ";                                                   // Defensive here
//        cin >> y;
//    }
//
//    for (int i = 1; i <= this -> row; ++i) {
//
//        if (this -> board[i][y] != T() || i == (this -> row) ){
//            x = i - 1;
//        }
//    }
//
//
//
//}
//
//
//
////===================================================================
//
//// Constructor for X_O_Random_Player
//template <typename T>
//Four_in_a_row_random_player<T> :: Four_in_a_row_random_player (T symbol)  {
//    this->dimension_x = 6;
//    this->dimension_y = 7;
//    this->name = "Random Computer Player";
//    srand( static_cast <unsigned int> (time(0)) );  // Seed the random number generator
//}
//
//template <typename T>
//void Four_in_a_row_random_player<T>::getmove(int& x, int& y) {
//    x = rand() % this->dimension_x;  // Random number between 0 and 5
//    y = rand() % this->dimension_y;  // Random number between 0 and 6
//}