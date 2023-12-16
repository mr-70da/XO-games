#include "X_O_Pyramid_Board.h"
X_O_Pyramid_Board::X_O_Pyramid_Board() {
    n_rows = 3;
    board = new char* [n_rows];
    board[0] = new char [1]{0};
    board[1] = new char [3]{0};
    board[2] = new char [5]{0};
}

bool X_O_Pyramid_Board::update_board(int x, int y, char mark) {
    if(x==0&&y==0&&board[x][y]==0||x==1&&(y==0||y==1||y==2)&&board[x][y]==0
       ||x==2&&(y==0||y==1||y==2||y==3||y==4)&&board[x][y]==0){
        board[x][y] = (char)toupper(mark);
        n_moves++;
        return true;
    }
    return false;
}

bool X_O_Pyramid_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_Pyramid_Board::is_winner() {
    char row_win[3], col_win[1], diag_win[2];
    int j = 0,row = 2;
    for (int i:{1,2,3,4}) {
        if(i==1) {
            row_win[i] = (char) (board[i][j] & board[i][j+1] & board[i][j+2]); }
        else{
            row_win[row] = (char)(board[row][j] & board[row][j+1] & board[row][j+2]);
            ++j;
            if(row_win[row]=='X'||row_win[row]=='O'){
                break;
            }
        }
    }

    diag_win[0] = char(board[0][0] & board[1][0] & board[2][0]);
    diag_win[1] = char(board[0][0] & board[1][2] & board[2][4]);
    col_win[0] = char(board[0][0] & board[1][1] & board[2][2]);

    for(int i:{1,2,3,4}){
        if(i==1&&(row_win[i] && (row_win[i] == board[i][1]))||row_win[row]&&(row_win[row]==board[row][i])){
            return true;
        }
    }

    if((diag_win[0]==board[0][0])&&diag_win[0]|| (diag_win[1]==board[0][0])&&diag_win[1]){
        return true;
    }

    if((col_win[0] ==board[0][0])&&col_win[0]){
        return true;
    }

    return false;
}

bool X_O_Pyramid_Board::game_is_over() {
    return n_moves >= 9;
}

void X_O_Pyramid_Board::display_board() {
    for (int i = 0; i < 3; ++i) {
        cout<<'\n';
        cout<<setw(20)<<"|  ";
        for (int j:{0}) {
            cout << "(" << i << "," << j << ")";
            cout <<" "<< board [i][j] << " |";
        }++i;
        cout<<'\n';
        cout <<"\t"<< "--------------------------------";
        cout<<'\n';
        cout<<setw(14)<<"| ";
        for (int j :{0,1,2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(1) << board [i][j] << " |";
        }++i;
        cout << "\n     --------------------------------------";
        cout<<"\n| ";
        for (int j :{0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(3) << board [i][j] << " |";
        }
    }
    cout << endl;
}

X_O_Pyramid_Board::~X_O_Pyramid_Board() {
    delete[] board;
}
