#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
    public:
        TicTacToe(unsigned int sizeOfBoard = 3, unsigned int toWin = 3);

        bool isEmpty(unsigned int row, unsigned int col)const;

        bool makeMove(unsigned int row, unsigned int col, unsigned int player);

        int isWon(unsigned int player)const; //0 if games going 1 - if 1st won, 2 - if 2nd won and -1 if noone won

        unsigned int getItem(unsigned int row, unsigned int col)const;
        
        //virtual ~TicTacToe();
        
        void printMeToConsole()const;
    
    private:
        unsigned const int boardSize;
        unsigned const int inRowToWin;
        unsigned int **board; //1 - for X, 2 - for 0

};

#endif // TICTACTOE_H
