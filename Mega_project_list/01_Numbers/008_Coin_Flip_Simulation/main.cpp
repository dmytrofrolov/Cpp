//Coin Flip Simulation - Write some code that simulates flipping a
// single coin however many times the user decides. The code should
// record the outcomes and count the number of tails and heads.
// Dmytro Frolov

#include <iostream>
#include <windows.h>//for Sleep and rand
#include <conio.h>  //for keys
#include <ctime>    //for time
using namespace std;

int main() {
    int input = 0, first = 0, second = 0;
    cout << "Press any key to flip the coin..." << endl;
    getch();
    srand(time(0));
    do{
        for(int i = 3; i>0; i--){
            cout << i << " ";
            cout.flush();
            Sleep(700);
        }
        for(int i = 3; i>0; i--) {
            cout << ".";
            cout.flush();
            Sleep(500);
        }
        cout << endl;
        int coin = rand()%2;
        if(coin==1){
            cout << "\tFirst side!" << endl;
            first++;
        }
        else {
            cout << "\tSecond side!" << endl;
            second++;
        }
        cout << "Press any key to continue, ESC to exit:" << endl;
        input = getch();
    }while(input!=27);
    cout << "Total:\nFirst side:\t" << first << "\tSecond side:\t" << second << endl;
    cout << "Press any key to exit..." << endl;
    getch();
    return 0;
}