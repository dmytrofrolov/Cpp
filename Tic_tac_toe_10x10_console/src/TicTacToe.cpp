#include "TicTacToe.h"

TicTacToe::TicTacToe(unsigned int sizeOfBoard, unsigned int toWin)
:boardSize(sizeOfBoard),inRowToWin(toWin)
{
    board = new unsigned int* [boardSize];
    for(unsigned int i = 0; i < boardSize; i++){
        board[i] = new unsigned int[boardSize];
        for(unsigned int j = 0; j<boardSize; j++)board[i][j]=0;
    }

}

TicTacToe::~TicTacToe()
{
    for(unsigned int i = 0; i < boardSize; i++){
        delete [] board[i];
    }
    delete [] board;
}


bool TicTacToe::isEmpty(unsigned int row,unsigned int col){
    if(row<=boardSize && col<=boardSize && board[row][col])return false;
    return true;
}


bool TicTacToe::makeMove(unsigned int row, unsigned int col, unsigned int player){
    if(row<=boardSize && col<=boardSize && isEmpty(row,col)){
        board[row][col]=player;
        return true;
    }
    return false;
}

bool TicTacToe::isWon(unsigned int player){

    unsigned int wonInLine = 0;
    for(unsigned int row = 0; row < boardSize; row++)
        for(unsigned int i = 0; i <= boardSize-inRowToWin; i++)
            for(unsigned int j = i; j < i+inRowToWin; j++){
                if(board[row][j]==player)wonInLine++;
                else wonInLine=0;
                if(wonInLine>=inRowToWin)return true;
            }
    wonInLine = 0;
    for(unsigned int col = 0; col < boardSize; col++)
        for(unsigned int i = 0; i <= boardSize-inRowToWin; i++)
            for(unsigned int j = i; j < i+inRowToWin; j++){
                if(board[j][col]==player)wonInLine++;
                else wonInLine=0;
                if(wonInLine>=inRowToWin)return true;
            }

    //add code to test diagonals

    return false;
}
