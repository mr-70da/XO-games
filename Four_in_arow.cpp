#include "Four_in_arow.h"

using namespace std;
Four_in_arow::Four_in_arow() {
    n_rows =  6,n_cols=7;
    board = new char*[n_rows] ;
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols] ;
        for (int j = 0; j < n_cols; j++){
            board[i][j] = 0;
            possible[i][j]=0;
        }
    }
    for(int i=0;i<n_cols;i++) possible[6][i]=1;
}

bool Four_in_arow::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)&&(possible[x+1][y])) {
        board[x][y] = (char)toupper(mark);
        possible[x][y]=1;
        n_moves++;
        return true;
    }
    else{

        return false;}
}

void Four_in_arow::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "|  (" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n------------------------------------------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Four_in_arow::is_winner() {
    // Check Rows
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols - 3; j++) {
            if (board[i][j]==board[i][j+1]
                &&board[i][j]==board[i][j+2]
                &&board[i][j]==board[i][j+3]
                &&(board[i][j]=='X'||board[i][j]=='O')) {
                return true;
            }
        }
    }

    // Check columns
    for (int i = 0; i < n_rows - 3; i++) {
        for (int j = 0; j < n_cols; j++) {
            if ( board[i][j] == board[i + 1][j]
                 && board[i][j] == board[i + 2][j]
                 && board[i][j] == board[i + 3][j]
                 && (board[i][j]=='X'||board[i][j]=='O') ) {
                return true;
            }
        }
    }

    // Check diagonals (left to right)
    for (int i = 0; i < n_rows - 3; i++) {
        for (int j = 0; j < n_cols - 3; j++) {
            if (board[i][j] == board[i + 1][j + 1]
                &&board[i][j] == board[i + 2][j + 2]
                && board[i][j] == board[i + 3][j + 3]
                && (board[i][j]=='X'||board[i][j]=='O') ) {
                return true;
            }
        }
    }

    // Check diagonals (right to left)
    for (int i = 0; i < n_rows - 3; i++) {
        for (int j = 3; j < n_cols; j++) {
            if (board[i][j] == board[i + 1][j - 1]
                && board[i][j] == board[i + 2][j - 2]
                && board[i][j] == board[i + 3][j - 3]
                && (board[i][j]=='X'||board[i][j]=='O')  ) {
                return true;
            }
        }
    }

    return false;
}

// Return true if 9 moves are done and no winner
bool Four_in_arow::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Four_in_arow::game_is_over () {
    return n_moves >= 42;
}

Four_in_arow::~Four_in_arow() {
    delete[] board;
}


RandomPlayer2::RandomPlayer2(char symbol, int dimension, int dimension2) : RandomPlayer(symbol , dimension) {
    this -> dimension2= dimension2 ;
}

void RandomPlayer2::get_move(int &x, int &y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension2);
}
