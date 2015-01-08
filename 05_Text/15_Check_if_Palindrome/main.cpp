//**Check if Palindrome** - Checks if the string entered
// by the user is a palindrome. That is that it
// reads the same forwards as backwards like “racecar”
// Dmytro Frolov

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Please, input string : " << endl;
    string someString = "", newString = "";
    getline(cin, someString);
    for(int i = 0; i < someString.size(); i++){
        someString[i] = char(tolower(someString[i]));
        newString=someString[i]+newString;
    }
    if(newString==someString)
        cout << "It is a Palindrome!" << endl;
    else
        cout << "It is not a Palindrome" << endl;
    return 0;
}