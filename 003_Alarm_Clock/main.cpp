//Alarm Clock - A simple clock where it
//plays a sound after X number of minutes/seconds or at a particular time.
// Dmytro Frolov
#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main() {
    cout << "Timer - 1 \tAlarm - 2 \n Input : ";
    int choice = 0;
    cin >> choice;
    if(choice == 1){
        cout << "Please enter minutes to alarm: ";
        int minutes = 0, seconds = 0;
        cin >> minutes;
        while(minutes>0){
            for(int i = 0; i < 60; i++) {
                cout << i << " ";
                Sleep(1000);
            }
            cout << endl;
            minutes--;
        }
        Beep(523,500);
    }
    else if(choice == 2){

    }
    cout << "Hello, World!" << endl;
    return 0;
}