//Labyrinth task
//Dmytro Frolov
#include <iostream>

#ifndef NOLOGGING
#define LOG(msg)
#else
#define LOG(msg) std::cout << "[LOG] (" __FILE__ ":" << __LINE__ << ") from " << __func__ << "()\n    " << msg << "\n";
#endif

using namespace std;
void mazeTraverse(char *maze, int size, int startingPoint[2]);
int main() {
    char *maze[] = {
             "####",
             "#...",
             "#..#",
             "##.#"
    };
    int startingPoint[2] = {1,3};
    mazeTraverse( maze, 4, startingPoint);
    cout << "Hello, World!" << endl;
    return 0;
}



void mazeTraverse(char *maze, int size, int startingPoint[2]) {
    //maze[startingPoint[0]][startingPoint[1]] = 'T';
    cout << startingPoint[0] << " " << startingPoint[1] << endl;
    cout << maze[startingPoint[0]][startingPoint[1]]  << endl;
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}