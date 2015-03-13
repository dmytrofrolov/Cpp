/// Tic Tac Toe game v 0.1
// Create date : Mar 09, 2015
// Author : Dmytro Frolov

#include <iostream>
#include <TicTacToe.h>
using namespace std;

int main()
{
    TicTacToe game(4, 3);
    game.makeMove(1,1,1);
    game.makeMove(2,1,1);
    game.makeMove(3,1,1);
    cout << game.isWon(1);
    return 0;
}
