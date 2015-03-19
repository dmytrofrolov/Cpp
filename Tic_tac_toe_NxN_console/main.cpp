/// Tic Tac Toe game v 0.1
// Create date : Mar 09, 2015
// Author : Dmytro Frolov

#include <iostream>
#include <TicTacToe.h>
using namespace std;

int main()
{
    int gameSize = 4;
    int movesToWin = 2;
    TicTacToe game(gameSize, movesToWin);

    //current player
    int current = 2;

    //user won (0 - game goes, 1 - 1st won, 2-2nd won, -1 - noone wons)
    int currentWon = 0;

    //for input choice
    int x = 0, y = 0;
    game.printMeToConsole();
    while(!currentWon && currentWon!=-1){
        current = current==1?2:1;
        bool isRightMove = true;
        do{
        cout << "For player : " << current << " input (row col) : (1-" <<  gameSize << ") : " << endl;
        cin >> x >> y;
        x--;y--;
        isRightMove = game.makeMove(x, y, current);
        }while(!isRightMove);
        currentWon = game.isWon(current);
        game.printMeToConsole();
    }
    cout << "First : " << (current==1&&currentWon?1:0) << " Second : " << (current==2&&currentWon?1:0) << endl;
    return 0;
}

//0 2 0 0 1 1 0 1 2 0
//0 0 0 1 1 1 0 2 2 2
//0 1 1 1 1 0 0 0 2 0
