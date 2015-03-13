#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
    public:
        TicTacToe(unsigned int sizeOfBoard = 3, unsigned int toWin = 3);
        bool isEmpty(unsigned int, unsigned int);
        bool makeMove(unsigned int, unsigned int, unsigned int);
        bool isWon(unsigned int player);
        virtual ~TicTacToe();
    private:
        unsigned const int boardSize;
        unsigned const int inRowToWin;
        unsigned int **board; //1 - for X, 2 - for 0

};

#endif // TICTACTOE_H
