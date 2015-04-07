//**Factorial Finder** - The Factorial of a positive integer, n,
// is defined as the product of the sequence n, n-1, n-2, ...1
// and the factorial of zero, 0, is defined as being 1.
// Solve this using both loops and recursion.
// Dmytro Frolov

#include <iostream>

using namespace std;

unsigned long int recursiveFactorial(unsigned int number);
static unsigned long int recursiveStaticFactorial(unsigned int number);
unsigned long int loopFactorial(unsigned int number);

int main() {
    cout << recursiveFactorial(5) << endl;
    cout << recursiveStaticFactorial(5) << endl;
    cout << loopFactorial(5) << endl;
    return 0;
}


unsigned long int recursiveFactorial(unsigned int number) {
    if(number==1)return 1;
    else return number* recursiveFactorial(number-1);
}



unsigned long int static recursiveStaticFactorial(unsigned int number) {
    static unsigned int factorial[50];
    if(number==1)return 1;
    if(factorial[number]!=0)return factorial[number];
    else{
        factorial[number]=number * recursiveStaticFactorial(number-1);
        return factorial[number];
    }
}

unsigned long int loopFactorial(unsigned int number) {
    long int factorial = 1;
    while(number>1){
        factorial*=number--;
    }
    return factorial;
}