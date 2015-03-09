#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
    public:
        TicTacToe(unsigned int sizeOfBoard = 3, unsigned int toWin = 3);
        virtual ~TicTacToe();
    private:
        unsigned const int bordSize;
        unsigned const int inRowToWin;
        unsigned short int **board;
};

#endif // TICTACTOE_H
