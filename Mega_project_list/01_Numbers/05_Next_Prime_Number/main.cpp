//**Next Prime Number** - Have the program find prime numbers
// until the user chooses to stop asking for the next one.
// Dmytro Frolov
#include <iostream>
#include <cmath>

using namespace std;
bool isPrime(unsigned int number);

int main() {
    cout << "Input positive number : ";
    unsigned int number = 0;
    cin >> number;
    unsigned short int searchNext = 0;
    unsigned int nextPrime = number;
    do{
        cout << "Next Prime is : ";
        while(1)if(isPrime(++nextPrime))break;
        cout << nextPrime << endl;
        cout << "Do you want to search next one? 1 - yes : ";
        cin >> searchNext;
    }while(searchNext==1);
    return 0;
}


bool isPrime(unsigned int number) {
    for(unsigned int i = 2; i < ceil(sqrt(number)); i++)
        if(number%i==0)
            return false;
    return true;
}