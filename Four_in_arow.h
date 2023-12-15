#ifndef XO_OOP_WRANDOM_FOUR_IN_AROW_H
#define XO_OOP_WRANDOM_FOUR_IN_AROW_H


#include <bits/stdc++.h>
#include"../include/BoardGame_Classes.hpp"

using namespace std;


class Four_in_arow : public Board {
protected:
    int possible[7][7]{};
public:
    Four_in_arow();

    bool update_board(int x, int y, char mark) override;

    void display_board() override;

    bool is_winner() override;

    bool is_draw() override;

    bool game_is_over() override;

    ~Four_in_arow();
};


class RandomPlayer2 : public RandomPlayer {
protected:
    int dimension2;
public:
    RandomPlayer2(char symbol, int dimension, int dimension2);

    void get_move(int &x, int &y) override;

};

#endif //XO_OOP_WRANDOM_FOUR_IN_AROW_H