//Alarm Clock - A simple clock where it
//plays a sound after X number of minutes/seconds or at a particular time.
// Dmytro Frolov
#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
void playAlarm(int numberOfTimes);

int main() {

    cout << "Timer - 1 \tAlarm - 2 \n Input : ";
    int choice = 0;
    cin >> choice;
    if(choice == 1){
        cout << "Please enter minutes to alarm: ";
        int minutes = 0, seconds = 0;
        cin >> minutes;
        cout << "Please enter seconds to alarm: ";
        cin >> seconds;
        cout << "Print seconds? y/n : ";
        char isSeconds = 'n';
        cin >> isSeconds;
        time_t currentTime;
        time(&currentTime);
        time_t timeToAlarm = currentTime;
        timeToAlarm+=minutes*60+seconds;
        int secondsTo = 0;
        while((secondsTo = abs(currentTime-timeToAlarm)) > 1){
            Sleep(1000);
            time(&currentTime);
            if(isSeconds=='y') {
                cout << secondsTo << " ";
                cout.flush();
            }
        }
        playAlarm(8);
    }
    else if(choice == 2) {
        cout << "Input hours: ";
        int hours = 0;
        cin >> hours;
        while(hours > 23 || hours < 0){
            cout << "ERROR! Invalid hours! It should be 00~23.\nInput hours: ";
            cin >> hours;
        }

        int minutes = 0;
        cout << "Input minutes: ";
        cin >> minutes;
        while(minutes > 59 || minutes < 0){
            cout << "ERROR! Invalid minutes! It should be 00~59.\nInput hours: ";
            cin >> minutes;
        }
        time_t currentTime;
        time(&currentTime);

        struct tm alarmTime;
        alarmTime = *localtime(&currentTime);
        alarmTime.tm_hour = hours;
        alarmTime.tm_min = minutes;
        alarmTime.tm_sec = 0;
        time_t timeToAlarm = mktime(&alarmTime);
        if(currentTime-timeToAlarm > 1)timeToAlarm+=60*60*24;
        while(abs(currentTime-timeToAlarm)>0){
            Sleep(1000);
            time(&currentTime);
        }
        playAlarm(8);
    }
    return 0;
}


void playAlarm(int numberOfTimes) {
    for(int i = 0; i < numberOfTimes; i++){
        for(int j = 0; j < 4; j++){
            Beep(523,150);
            Sleep(15);
        }
        Sleep(400);
    }
}