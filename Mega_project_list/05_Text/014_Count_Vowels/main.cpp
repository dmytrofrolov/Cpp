//Count Vowels - Enter a string and the program counts
// the number of vowels in the text. For added complexity
// have it report a sum of each vowel found.
// Dmytro Frolov

#include <iostream>
#include <string>
using namespace std;

int main() {
    int letters[26] = {0};
    string someString = "";
    cout << "Please, input the string : " << endl;
    getline(cin, someString);
    for(int i = 0; i < someString.size(); i++){
        someString[i]=tolower(someString[i]);
        letters[int(someString[i])-97]++;
    }
    cout << "a : " << letters[int('a')-97] << endl;
    cout << "e : " << letters[int('e')-97] << endl;
    cout << "i : " << letters[int('i')-97] << endl;
    cout << "o : " << letters[int('o')-97] << endl;
    cout << "u : " << letters[int('u')-97] << endl;
    cout << "Total vovels: " << letters[int('a')-97]+letters[int('e')-97] +letters[int('i')-97] +letters[int('o')-97] +letters[int('u')-97] << endl;

    return 0;
}