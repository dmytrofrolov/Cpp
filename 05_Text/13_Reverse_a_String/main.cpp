//**Reverse a String** - Enter a string and the program will reverse it and print it out.
//Dmytro Frolov
#include <iostream>
#include <string>
using namespace std;

int main() {
    string someString = "";
    cout << "Enter a string :" << endl;
    getline(cin, someString);
    for(int i = someString.size(); i>0; i--)
        cout << someString[i-1];
    cout << endl;
    return 0;
}