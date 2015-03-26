//**Count Words in a String** - Counts the number of
// individual words in a string. For added complexity read
// these strings in from a text file and generate a summary.
// Dmytro Frolov

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

unsigned int countWordsInString(string someString);

int main() {
    fstream txtFile;
    int wordNumbers = 0;
    string someString;
    txtFile.open("textFile.txt", std::fstream::in);
    if(!txtFile.is_open())cout << "NOT OPEN!" << endl;
    else{

        while(getline(txtFile, someString, '\n')){
            wordNumbers+=countWordsInString(someString);
        }
    }
    cout << "Total words in file : " << wordNumbers << endl;
    txtFile.close();
    return 0;
}



unsigned int countWordsInString(string someString) {
    unsigned int words = 0;
    int multSpaces = 0;
    while(someString[0]==' ')someString.erase(0, 1);
    do{
        multSpaces = 0;
        for(int i = 0; i<someString.size(); i++)
            if((someString[i]==' ' && someString[i+1]==' ') || (i==someString.size()-2) && someString[i+1]==' '){
                someString.erase(i+1, 1);
                multSpaces++;
            }
    }
    while(multSpaces!=0);

    for(int i = 0; i<someString.size(); i++)
        if(someString[i]==' ')words++;
    if(someString!="")words++;
    return words;

}