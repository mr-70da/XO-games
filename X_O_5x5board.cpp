// Author1 and ID and Group: Mahmoud Ayman Ramadan ID:20220313 Email:man3092003city@gmail.com Group:S6.
// Author2 and ID and Group: Hassan Sherif Elkersh ID:20220112 Email:1243hassan@gmail.com     Group:S6.
// FCAI – OOP Programming – 2023 - Assignment 3-XO 5x5 Game.
// Program Name:            xxxxxx.cpp
// Last Modification Date:    6/12/2023
// Teaching Assistant:        xxxxx xxxxx
// Purpose: mastering OOP concepts.
#include "X_O_5x5board.h"

void X_O_5x5board::display_board() {

    for (int i: {0, 1, 2, 3, 4}) {
        cout << "\n| ";
        for (int j: {0, 1, 2, 3, 4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n---------------------------------------------- -";
    }
    cout << endl;
}

X_O_5x5board::X_O_5x5board() {
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }

}

bool X_O_5x5board::update_board(int x, int y, char symbol) {
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && !(board[x][y])) {
        board[x][y] = (char) toupper(symbol);
        n_moves++;
        return true;
    }
    return false;
}

bool X_O_5x5board::is_winner() {
    XCnt = OCnt = 0;
    count_X_O();
    if (XCnt > OCnt) {
        return true;
    } else if (XCnt < OCnt) {
        return false;
    }
}

bool X_O_5x5board::is_draw() {
    XCnt = OCnt = 0;
    count_X_O();
    return XCnt == OCnt;
}

bool X_O_5x5board::game_is_over() {
    return (n_moves > 24);
}

X_O_5x5board::~X_O_5x5board() {
    delete[] board;
}

void X_O_5x5board::count_X_O() {
    // Check rows
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols - 2; j++) {
            if (board[i][j] == board[i][j + 1]
                && board[i][j] == board[i][j + 2]) {
                XCnt += (board[i][j] == 'X') ? 1 : 0;
                OCnt += (board[i][j] == 'O') ? 1 : 0;
            }
        }
    }/*
 * 0 2
 */
    // Check columns
    for (int i = 0; i < n_rows - 2; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (board[i][j] == board[i + 1][j]
                && board[i][j] == board[i + 2][j]) {
                XCnt += (board[i][j] == 'X') ? 1 : 0;
                OCnt += (board[i][j] == 'O') ? 1 : 0;
            }
        }
    }

    // Check diagonals (left to right)
    for (int i = 0; i < n_rows - 2; i++) {
        for (int j = 0; j < n_cols - 2; j++) {
            if (board[i][j] == board[i + 1][j + 1]
                && board[i][j] == board[i + 2][j + 2]) {
                XCnt += (board[i][j] == 'X') ? 1 : 0;
                OCnt += (board[i][j] == 'O') ? 1 : 0;
            }
        }
    }

    // Check diagonals (right to left)
    for (int i = 0; i < n_rows - 2; i++) {
        for (int j = 3; j < n_cols; j++) {
            if (board[i][j] == board[i + 1][j - 1]
                && board[i][j] == board[i + 2][j - 2]) {
                XCnt += (board[i][j] == 'X') ? 1 : 0;
                OCnt += (board[i][j] == 'O') ? 1 : 0;
            }
        }
    }
}

GameManager2::GameManager2(Board *bPtr, Player **playerPtr) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager2::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()){
        for (int i: {0, 1}) {
            if(boardPtr->n_moves>23){
                goto next;
            }
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                if(boardPtr->n_moves>23){
                    goto next;
                }
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();

        }
    }
    next:
    if (boardPtr->is_draw()) {
        cout << "Draw!\n";
    }
    else if (boardPtr->is_winner()) {
        cout << players[0]->to_string() << " wins\n";
    } else {
        cout << players[1]->to_string() << " wins\n";
    }
}
