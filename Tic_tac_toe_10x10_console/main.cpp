/// Tic Tac Toe game v 0.1
// Create date : Mar 09, 2015
// Author : Dmytro Frolov

#include <iostream>
#include <TicTacToe.h>
using namespace std;

int main()
{
    int gameSize = 3;
    TicTacToe game(gameSize, 3);
    int current = 2;
    bool currentWon = false;
    int x = 0, y = 0;
    while(!currentWon){
        current = current==1?2:1;
        cout << "For player : " << current << " input : x (0-" <<  gameSize-1 << ") : ";
        cin >> x;
        cout << " input : y (0-" <<  gameSize-1 << ") : ";
        cin >> y;
        game.makeMove(x, y, current);
        currentWon = game.isWon(current);
    }
    cout << "First : " << (current==1&&currentWon?1:0) << " Second : " << (current==2&&currentWon?1:0) << endl;
    return 0;
}
