// Author1 and ID and Group: Mahmoud Ayman Ramadan ID:20220313 Email:man3092003city@gmail.com Group:S6.
// Author2 and ID and Group: Hassan Sherif Elkersh ID:20220112 Email:1243hassan@gmail.com     Group:S6.
// FCAI – OOP Programming – 2023 - Assignment 3-XO 5x5 Game.
// Program Name:            xxxxxx.cpp
// Last Modification Date:    6/12/2023
// Teaching Assistant:        xxxxx xxxxx
// Purpose: mastering OOP concepts.

#ifndef XO_OOP_WRANDOM_X_O_5X5BOARD_H
#define XO_OOP_WRANDOM_X_O_5X5BOARD_H

#include"../include/BoardGame_Classes.hpp"
#include <bits/stdc++.h>

using namespace std;

class X_O_5x5board : public Board {
private:
    int XCnt = 0;
    int OCnt = 0;
public:
    X_O_5x5board();

    bool update_board(int x, int y, char symbol) override;

    bool is_winner() override;

    void count_X_O();

    // Return true if all moves are done and no winner
    bool is_draw() override;

    // Display the board and the pieces on it
    void display_board() override;

    // Return true if game is over
    bool game_is_over() override;

    ~X_O_5x5board();
};

class GameManager2 {
private:
    Board *boardPtr;
    Player *players[2]{};
public:
    GameManager2(Board *, Player *playerPtr[2]);

    void run();
};


#endif //XO_OOP_WRANDOM_X_O_5X5BOARD_H
