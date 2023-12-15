#include "X_O_5x5board.h"
#include "X_O_Pyramid_Board.h"
#include "Four_in_arow.h"
void menu(char& game){
    cout<<"Choose a game to play:\n"
          "1- 3x3 XO \n"
          "2- Pyramid XO\n"
          "3- Connect 4 \n"
          "4- 5x5 XO\n";
    cin>>game;
    switch (game) {
        case '1':
        case '2':
        case '3':
        case '4':
            break;
        default:
            cout<<"Invalid\n";
            cout<<"Choose a game to play:\n"
                  "1- 3x3 XO \n"
                  "2- Pyramid XO\n"
                  "3- Connect 4 \n"
                  "4- 5x5 XO\n";
            menu(game);
    }
}
int main() {
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    char game;
    menu(game);
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        //Player pointer points to child
        switch (game) {
        case '1':
        case '2':
        case '4':
            players[1] = new RandomPlayer('o', 5);
            break;
        case '3':
            players[1] = new RandomPlayer2('o', 6, 7);
            break;
        default:
            break;
    }
    if(game=='1'){
        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
    }
    else if(game =='2'){
        GameManager x_o_game (new X_O_Pyramid_Board(), players);
        x_o_game.run();
    }
    else if(game == '3'){
        GameManager x_o_game(new Four_in_arow(), players);
        x_o_game.run();
    }
    else{
        GameManager2 x_o_game(new X_O_5x5board(), players);
        x_o_game.run();
    }
    delete players[0];
    delete players[1];
    system("pause");
}