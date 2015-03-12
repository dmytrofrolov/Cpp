#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
    public:
        TicTacToe(unsigned int sizeOfBoard = 3, unsigned int toWin = 3);
        bool isEmpty(int, int);
        virtual ~TicTacToe();
    private:
        unsigned const int bordSize;
        unsigned const int inRowToWin;
        unsigned int **board;
};

#endif // TICTACTOE_H
