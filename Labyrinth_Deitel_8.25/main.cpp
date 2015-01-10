//Labyrinth task
//Dmytro Frolov
#include <iostream>
#include <fstream>
using namespace std;
void mazeTraverse(char **maze, int size, int startingPoint[2]);
int main() {
    fstream labyrinth;
    labyrinth.open("labyrinth_1.txt");
    if(!labyrinth.is_open()){
        cout << "ERROR! With file opening" << endl;
        return -1;
    }
    char row[100];
    char **maze;
    maze = new char *[20];
    for(int i = 0; i <20; i++)
        maze[i] = new char[20];
    int j = 0;
    while(!labyrinth.eof()){
        labyrinth >> row;
        for(int i = 0; i<12; i++)
            maze[j][i] = row[i];
        j++;
    }


    int startingPoint[2] = {4,11};
    mazeTraverse( maze, 12, startingPoint);
    labyrinth.close();
    return 0;
}



void mazeTraverse(char **maze, int size, int startingPoint[2]) {
    
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}