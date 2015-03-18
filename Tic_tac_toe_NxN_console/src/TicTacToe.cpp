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


bool TicTacToe::isEmpty(unsigned int row,unsigned int col)const{
    if(row < boardSize && col < boardSize && board[row][col])return false;
    return true;
}


bool TicTacToe::makeMove(unsigned int row, unsigned int col, unsigned int player){
    if(row < boardSize && col < boardSize && isEmpty(row,col)){
        board[row][col]=player;
        return true;
    }
    return false;
}

int TicTacToe::isWon(unsigned int player)const{
    unsigned int wonInLine = 0;

    //checking rows
    //for each row
    for(unsigned int row = 0; row < boardSize; row++)
        //for each place that is less than should be to win
        for(unsigned int i = 0; i <= boardSize-inRowToWin; i++)
            //check if all what should marked to win is marked
            for(unsigned int j = i; j < i+inRowToWin; j++){
                if(board[row][j]==player)wonInLine++;
                else wonInLine=0;
                if(wonInLine>=inRowToWin)return player;
            }
    wonInLine = 0;

    //checking cols
    //for each col
    for(unsigned int col = 0; col < boardSize; col++)
        //for each place in col what is less than it necessary to win
        for(unsigned int i = 0; i <= boardSize-inRowToWin; i++)
            //check if all that it should be to win is checked
            for(unsigned int j = i; j < i+inRowToWin; j++){
                if(board[j][col]==player)wonInLine++;
                else wonInLine=0;
                if(wonInLine>=inRowToWin)return player;
            }
    wonInLine = 0;


    //checking diagonals from top-left to bottom-right
    //for each row
    for(unsigned int row = 0; row <= boardSize-inRowToWin; row++)
        //for each col in row what is less than it necessary to win
        for(unsigned int col = 0; col <= boardSize-inRowToWin; col++)
            //check if all that it should be to win is checked
            for(unsigned int j = col; j < col+inRowToWin; j++){
                if(board[j][j]==player)wonInLine++;
                else wonInLine=0;
                if(wonInLine>=inRowToWin)return player;
            }
    wonInLine = 0;

    //checking diagonals from bottom-left to top-right
    //for each row
    for(unsigned int row = inRowToWin-1; row < boardSize; row++)
        //for each col in row what is less than it necessary to win
        for(unsigned int col = 0; col <= boardSize-inRowToWin; col++)
            //check if all that it should be to win is checked
            for(unsigned int j = 0; j < inRowToWin; j++){
                if(board[row-j][col+j]==player)wonInLine++;
                else wonInLine=0;
                if(wonInLine>=inRowToWin)return player;
            }
    wonInLine = 0;

    //check if there are some free places
    int notMarked = boardSize * boardSize;
    for(unsigned int row = 0; row < boardSize; row++)
        for(unsigned int col = 0; col < boardSize; col++)
            if(board[row][col])notMarked--;
    //if there are nothing left return -1
    if(!notMarked)return -1;

    //game goes but noone still win
    return 0;
}

unsigned int TicTacToe::getItem(unsigned int row, unsigned int col)const{
    if(col<boardSize && row < boardSize)return board[row][col];
    return 0;
}
