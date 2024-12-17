
#ifndef _ULTIMATE_BOARD_H
#define _ULTIMATE_BOARD_H

#include <iomanip>

#include "BoardGame_Classes.h"

template <typename T>
class Ultimate_Board:public Board<T> {
public:
    Ultimate_Board ();
    bool update_board (int x , int y , T mark) override;
    void display_board () override;
    bool is_win() override ;
    bool is_draw() override;
    bool game_is_over() override;
    bool isValid_board00(int x, int y);
    bool isValid_board01(int x, int y);
    bool isValid_board02(int x, int y);
    bool isValid_board10(int x, int y);
    bool isValid_board11(int x, int y);
    bool isValid_board12(int x, int y);
    bool isValid_board20(int x, int y);
    bool isValid_board21(int x, int y);
    bool isValid_board22(int x, int y);

    void isemptyboard(int x, int y);

    int countPl=0;
    int co=0;

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
Ultimate_Board<T>::Ultimate_Board() {
    this->rows = this->columns = 9;
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
bool Ultimate_Board<T>::update_board(int x, int y, T mark)  {
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
void Ultimate_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            // Print the cell content
            cout << " " << this->board[i][j] << " ";
            // Add a vertical boundary for sub-grids
            if ((j + 1) % 3 == 0 && j != this->columns - 1) {
                cout << "||";
            } else {
                cout << "|";
            }
        }
        cout << endl;

        // Add horizontal boundary after each row
        if ((i + 1) % 3 == 0 && i != this->rows - 1) {
            cout << string(39, '=') << endl; // Thicker line for sub-grid boundaries
        } else {
            cout << string(39, '-') << endl; // Regular line between rows
        }
    }
    cout << endl;
}



template <typename T>

bool Ultimate_Board<T>::is_win()  {
    co=isValid_board00(0,0)+isValid_board00(0,3)+isValid_board00(0,6)+isValid_board00(3,0)+isValid_board00(3,3)+isValid_board00(3,6)+isValid_board00(6,0)+isValid_board00(6,3)+isValid_board00(6,6);
    static bool p2_win=false;
    if(p2_win){
      return true;}
    if(co==9){
        if(this->n_moves%2!=0 ){
          if(countX>countY){
            return true;}
          else if(countX<countY){
            p2_win=true;
          }
        }
    }
    return false;
}

template <typename T>
void Ultimate_Board<T>::isemptyboard(int x, int y) {
  countPl=0;
  for(int i=x;i<x+3;i++){
    for(int j=y;j<y+3;j++){
      if(this->board[i][j] != 0){
          countPl++;
      }
    }
}
}

template <typename T>
bool Ultimate_Board<T>:: isValid_board00(int x, int y) {
    if(!(x/3==0 && y/3==0)){
        return false;
    }
    static int flag=0;
    if(flag==1){return true;}


    for (int i = 0; i < 3; ++i) {
        if (this->board[i][0] ==this-> board[i][1] &&this-> board[i][1]==this->board[i][2])
        {
            if(this->board[0][i] =='X')countX++;
            else if(this->board[0][i]=='O')countY++;
            flag++;
            return true;
        } // Row
        if (this->board[0][i]==this->board[1][i] &&this-> board[1][i]== this->board[2][i])
        {
            if(this->board[0][i] =='X')countX++;
            else if(this->board[0][i]=='O')countY++;
            flag++;
            return true;
        } // Column
    }
    if (this->board[0][0] ==this->board[1][1] &&this-> board[1][1]== this->board[2][2] )
    {
        if(this->board[0][0] =='X')countX++;
        else if(this->board[0][0]=='O')countY++;
        flag++;
        return true;
    } // Diagonal
    if (this->board[0][2] == this->board[1][1] &&this-> board[1][1]== this->board[2][0])
    {
        if(this->board[0][2] =='X')countX++;
        else if(this->board[0][2]=='O')countY++;
        flag++;
        return true;
    } // Diagonal

    isemptyboard(0,0);
    if(countPl==9)return true;

    return false;
}


//&& !(isValid_board00( x,  y))&& !(isValid_board01( x,  y))&& !(isValid_board02( x,  y))&& !(isValid_board10( x,  y))&& !(isValid_board11( x,  y))&& !(isValid_board12( x,  y))&& !(isValid_board20( x,  y))&& !(isValid_board21( x,  y)) && !(isValid_board22( x,  y))
template <typename T>
bool Ultimate_Board<T>:: isValid_board01(int x, int y) {
    if(!(x/3==0 && y/3==1)){
        return false;
    }
    static int flag=0;
  if(flag==1){return true;}

    for (int i = 0; i < 3; ++i) {
        if (this->board[i][3] ==this-> board[i][4]&&this-> board[i][4]==this->board[i][5]){
            if(this->board[i][3] =='X')countX++;
            else if(this->board[i][3]=='O')countY++;
            flag++;
            return true;

        }
        if (this->board[0][i+3]==this->board[1][i+3] &&this-> board[1][i+3]== this->board[2][i+3]){
            if(this->board[0][i+3] =='X')countX++;
            else if(this->board[0][i+3]=='O')countY++;
            flag++;
            return true;
        }
            // Column
    }
    if (this->board[0][3] ==this->board[1][4] &&this-> board[1][4]== this->board[2][5] ){
        if(this->board[0][3] =='X')countX++;
        else if(this->board[0][3]=='O')countY++;
        flag++;
        return true;
      }
        // Diagonal
    if (this->board[0][5] == this->board[1][4] &&this-> board[1][4]== this->board[2][3]){
        if(this->board[0][5] =='X')countX++;
        else if(this->board[0][5]=='O')countY++;
        flag++;
        return true; // Diagonal
}
    isemptyboard(0,3);
    if(countPl==9)return true;
    return false;
}
template <typename T>
bool Ultimate_Board<T>:: isValid_board02(int x, int y) {

    if(!(x/3==0 && y/3==2)){
        return false;
    }
    static int flag=0;
  if(flag==1){return true;}

    for (int i = 0; i < 3; ++i) {
        if (this->board[i][6] ==this-> board[i][7]&&this-> board[i][7]==this->board[i][8]){
            if(this->board[i][6] =='X')countX++;
            else if(this->board[i][6]=='O')countY++;
            flag++;
            return true; // Row
        }

        if (this->board[0][i+6]==this->board[1][i+6] &&this-> board[1][i+6]== this->board[2][i+6]){
            if(this->board[0][i+6] =='X')countX++;
            else if(this->board[0][i+6]=='O')countY++;
            flag++;
            return true; // Column
        }


    }
    if (this->board[0][6] ==this->board[1][7]&&this-> board[1][7] == this->board[2][8] ){
        if(this->board[0][6] =='X')countX++;
        else if(this->board[0][6]=='O')countY++;
        flag++;
        return true; // Diagonal
    }

    if (this->board[0][8] == this->board[1][7] &&this-> board[1][7]== this->board[2][6]){
        if(this->board[0][8] =='X')countX++;
        else if(this->board[0][8]=='O')countY++;
        flag++;
        return true; // Diagonal
    }

    isemptyboard(0,6);
    if(countPl==9)return true;
    return false;
}
template <typename T>
bool Ultimate_Board<T>:: isValid_board10(int x, int y) {
    if(!(x/3==1 && y/3==0)){
        return false;
    }

    static int flag=0;
  if(flag==1){return true;}

    for (int i = 3; i < 6; ++i) {
        if (this->board[i][0] ==this-> board[i][1]&&this-> board[i][1]==this->board[i][2])
        {
            if(this->board[i][0] =='X')countX++;
            else if(this->board[i][0]=='O')countY++;
            flag++;
            return true; // Row
        } // Row
        if (this->board[3][i-3]==this->board[4][i-3]&&this-> board[4][i-3] == this->board[5][i-3])
        {
            if(this->board[3][i-3] =='X')countX++;
            else if(this->board[3][i-3]=='O')countY++;
            flag++;
            return true; // Row
        } // Column
    }
    if (this->board[3][0] ==this->board[4][1] &&this-> board[4][1]== this->board[5][3] )
    {
        if(this->board[3][0] =='X')countX++;
        else if(this->board[3][0]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    if (this->board[3][2] == this->board[4][1]&&this-> board[4][1] == this->board[5][0])
    {
        if(this->board[3][2] =='X')countX++;
        else if(this->board[3][2]=='O')countY++;
        flag++;
        return true; // Row
    }// Diagonal
    isemptyboard(3,0);
    if(countPl==9)return true;
    return false;
}
template <typename T>
bool Ultimate_Board<T>:: isValid_board11(int x, int y) {
    if(!(x/3==1 && y/3==1)){
        return false;
    }
    static int flag=0;
  if(flag==1){return true;}

    for (int i = 3; i < 6; ++i) {
        if (this->board[i][3] ==this-> board[i][4]&&this-> board[i][4]==this->board[i][5])
        {
            if(this->board[i][3] =='X')countX++;
            else if(this->board[i][3]=='O')countY++;
            flag++;
            return true; // Row
        } // Row
        if (this->board[3][i]==this->board[3][i+1] &&this-> board[3][i+1]== this->board[5][i+2])
        {
            if(this->board[3][i] =='X')countX++;
            else if(this->board[3][i]=='O')countY++;
            flag++;
            return true; // Row
        } // Column
    }
    if (this->board[3][3] ==this->board[4][4] &&this-> board[4][4]== this->board[5][5] )
    {
        if(this->board[3][3] =='X')countX++;
        else if(this->board[3][3]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    if (this->board[5][3] == this->board[4][4] &&this-> board[4][4]== this->board[3][5])
    {
        if(this->board[5][3] =='X')countX++;
        else if(this->board[5][3]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    isemptyboard(3,3);
    if(countPl==9)return true;
    return false;
}

template <typename T>
bool Ultimate_Board<T>:: isValid_board12(int x, int y) {

    if(!(x/3==1 && y/3==2)){
        return false;
    }
    static int flag=0;
  if(flag==1){return true;}

    for (int i = 3; i < 6; ++i) {
        if (this->board[i][6] ==this-> board[i][7]&&this-> board[i][7]==this->board[i][8])
        {
            if(this->board[i][6] =='X')countX++;
            else if(this->board[i][6]=='O')countY++;
            flag++;
            return true; // Row
        } // Row
        if (this->board[3][i+3]==this->board[4][i+3] &&this-> board[4][i+3]== this->board[5][i+6])
        {
            if(this->board[3][i+3] =='X')countX++;
            else if(this->board[3][i+3]=='O')countY++;
            flag++;
            return true; // Row
        } // Column
    }
    if (this->board[3][6] ==this->board[4][7] &&this-> board[4][7]== this->board[5][8] )
    {
        if(this->board[3][6] =='X')countX++;
        else if(this->board[3][6]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    if (this->board[3][8] == this->board[4][7] &&this-> board[4][7]== this->board[5][6])
    {
        if(this->board[3][8] =='X')countX++;
        else if(this->board[3][8]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    isemptyboard(3,6);
    if(countPl==9)return true;
    return false;
}


template <typename T>
bool Ultimate_Board<T>:: isValid_board20(int x, int y) {

    if(!(x/3==2 && y/3==0)){
        return false;
    }
    static int flag=0;
  if(flag==1){return true;}

    for (int i = 6; i < 9; ++i) {
        if (this->board[i][0] ==this-> board[i][1]&&this-> board[i][1]==this->board[i][2])
        {
            if(this->board[i][0] =='X')countX++;
            else if(this->board[i][0]=='O')countY++;
            flag++;
            return true; // Row
        } // Row
        if (this->board[6][i-6]==this->board[7][i-6] &&this-> board[7][i-6]== this->board[8][i-6])
        {
            if(this->board[6][i-6] =='X')countX++;
            else if(this->board[6][i-6]=='O')countY++;
            flag++;
            return true; // Row
        }// Column
    }
    if (this->board[6][0] ==this->board[7][1] &&this-> board[7][1]== this->board[8][2] )
    {
        if(this->board[6][0] =='X')countX++;
        else if(this->board[6][0]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    if (this->board[6][2] == this->board[7][1]&&this-> board[7][1] == this->board[8][0])
    {
        if(this->board[6][2] =='X')countX++;
        else if(this->board[6][2]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    isemptyboard(6,0);
    if(countPl==9)return true;
    return false;
}
template <typename T>
bool Ultimate_Board<T>:: isValid_board21(int x , int y) {
    if(!(x/3==2 && y/3==1)){
        return false;
    }

    static int flag=0;
  if(flag==1){return true;}

    for (int i = 6; i < 9; ++i) {
        if (this->board[i][3] ==this-> board[i][4]&&this-> board[i][4]==this->board[i][5])
        {
            if(this->board[i][3] =='X')countX++;
            else if(this->board[i][3]=='O')countY++;
            flag++;
            return true; // Row
        }// Row
        if (this->board[6][i-3]==this->board[7][i-3]&&this-> board[7][i-3] == this->board[8][i-3])
        {
            if(this->board[6][i-3] =='X')countX++;
            else if(this->board[6][i-3]=='O')countY++;
            flag++;
            return true; // Row
        } // Column
    }
    if (this->board[6][3] ==this->board[7][4]&&this-> board[7][4] == this->board[8][5] )
    {
        if(this->board[6][3] =='X')countX++;
        else if(this->board[6][3]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    if (this->board[6][5] == this->board[7][4]&&this-> board[7][4] == this->board[8][8])
    {
        if(this->board[6][5] =='X')countX++;
        else if(this->board[6][5]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    isemptyboard(6,3);
    if(countPl==9)return true;
    return false;
}
template <typename T>
bool Ultimate_Board<T>:: isValid_board22(int x, int y) {
    if(!(x/3==2 && y/3==2)){
        return false;
    }

    static int flag=0;
  if(flag==1){return true;}

    for (int i = 6; i < 9; ++i) {
        if (this->board[i][6] ==this-> board[i][7]&&this-> board[i][7]==this->board[i][8])
        {
            if(this->board[i][6] =='X')countX++;
            else if(this->board[i][6]=='O')countY++;
            flag++;
            return true; // Row
        } // Row
        if (this->board[6][i]==this->board[7][i] &&this-> board[7][i]== this->board[8][i])
        {
            if(this->board[6][i] =='X')countX++;
            else if(this->board[6][i]=='O')countY++;
            flag++;
            return true; // Row
        } // Column
    }
    if (this->board[6][6] ==this->board[7][7]&&this-> board[7][7] == this->board[8][8] )
    {
        if(this->board[6][6] =='X')countX++;
        else if(this->board[6][6]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    if (this->board[6][8] == this->board[7][7]&&this-> board[7][7] == this->board[8][6])
    {
        if(this->board[6][8] =='X')countX++;
        else if(this->board[6][6]=='O')countY++;
        flag++;
        return true; // Row
    } // Diagonal
    isemptyboard(6,6);
    if(countPl==9)return true;
    return false;
}
template <typename T>
bool Ultimate_Board<T>::is_draw() {
    if (this->n_moves == 81) {return true;}
    return (this->co == 9 && !is_win());
}
template<typename T>
bool Ultimate_Board<T>::game_is_over() {
    return is_win() || is_draw();
}




// player section
template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 8) separated by spaces: ";
    cin >> x >> y;
}

template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(string name,T symbol) : RandomPlayer<T>(name,symbol) {
    this->dimension = 9;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}


#endif