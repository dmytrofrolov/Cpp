#include "TicTacToe.h"

TicTacToe::TicTacToe(unsigned int sizeOfBoard, unsigned int toWin)
:bordSize(sizeOfBoard),inRowToWin(toWin)
{
    board = new unsigned int* [bordSize];
    for(unsigned int i = 0; i < bordSize; i++){
        board[i] = new unsigned int[bordSize];
        for(unsigned int j = 0; j<bordSize; j++)board[i][j]=0;
    }

}

TicTacToe::~TicTacToe()
{
    for(unsigned int i = 0; i < bordSize; i++){
        delete [] board[i];
    }
    delete [] board;
}


bool TicTacToe::isEmpty(int x, int y){
    if(board[x][y])return false;
    return true;
}
