//**Factorial Finder** - The Factorial of a positive integer, n,
// is defined as the product of the sequence n, n-1, n-2, ...1
// and the factorial of zero, 0, is defined as being 1.
// Solve this using both loops and recursion.
// Dmytro Frolov

#include <iostream>

using namespace std;

long int recursiveFactorial(unsigned int number);

int main() {
    cout << recursiveFactorial(5) << endl;
    return 0;
}



long int recursiveFactorial(unsigned int number) {
    if(number==1)return 1;
    else return number* recursiveFactorial(number-1);
}
