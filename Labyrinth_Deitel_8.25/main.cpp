//Labyrinth task
//Dmytro Frolov
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
void mazeTraverse(char **maze, int size, int startingPoint[2], int direction[2]);
int main() {
    fstream labyrinth;
    labyrinth.open("labyrinth_1.txt");
    if(!labyrinth.is_open()){
        cout << "ERROR! With file opening" << endl;
        return -1;
    }
    char row[100];
    char **maze;
    int startingPoint[2];
    int direction[2] = {0, -1};
    maze = new char *[20];
    for(int i = 0; i <20; i++)
        maze[i] = new char[20];
    int j = 0;
    while(!labyrinth.eof()){
        labyrinth >> row;
        for(int i = 0; i<12; i++){
            maze[j][i] = row[i];
            if(row[i]=='T'){
                startingPoint[0]=j;
                startingPoint[1]=i;
            }

        }
        j++;
    }

    mazeTraverse( maze, 12, startingPoint, direction);
    labyrinth.close();
    return 0;
}



void mazeTraverse(char **maze, int size, int startingPoint[2], int direction[2]) {
    const int dirA[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    const int rightA[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    const int leftA[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};

    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
    if((startingPoint[0]==11||startingPoint[0]==0||startingPoint[1]==0)){
        cout << "Found end! At : " << startingPoint[0] << " " << startingPoint[1] << endl;
        for(int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << maze[i][j] << " ";
            cout << endl;
        }
        return;
    }
    int tempRight[2] = {0,0};
    for(int i = 0; i<4; i++)
        if(direction[0]==dirA[i][0] && direction[1]==dirA[i][1]){
            tempRight[0] = rightA[i][0];
            tempRight[1] = rightA[i][1];
            cout << tempRight[0] << " " << tempRight[1] << endl;
        }
    if(maze[startingPoint[0]+tempRight[0]][startingPoint[1]+tempRight[1]]=='#'){
        while(maze[startingPoint[0]+direction[0]][startingPoint[1]+direction[1]]!='.') {
            //turn left
            int tempLeft[2] = {0,0};
            for(int i = 0; i<4; i++)
                if(direction[0]==dirA[i][0] && direction[1]==dirA[i][1]){
                    tempLeft[0] = leftA[i][0];
                    tempLeft[1] = leftA[i][1];
                }
            direction[0]=tempLeft[0];
            direction[1]=tempLeft[1];
            cout << "Directions:" << direction[0] << " " << direction[1] << endl;
        }

    }else{
        direction[0]=tempRight[0];
        direction[1]=tempRight[1];
    }
    maze[startingPoint[0]][startingPoint[1]]='.';
    startingPoint[0]+=direction[0];
    startingPoint[1]+=direction[1];
    maze[startingPoint[0]][startingPoint[1]]='T';
    cout << endl;
    mazeTraverse(maze, 12, startingPoint, direction);

}