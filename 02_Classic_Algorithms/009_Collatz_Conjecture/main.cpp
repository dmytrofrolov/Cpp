//**Collatz Conjecture** - Start with a number *n > 1*.
// Find the number of steps it takes to reach one using the following process:
// If *n* is even, divide it by 2. If *n* is odd, multiply it by 3 and add 1.
//Dmytro Frolov

#include <iostream>

using namespace std;

int main() {
    unsigned long long steps = 0, n = 0,max = 0;
    cout << "Input number to calculate: ";
    cin >> n;
    while(n!=1){
        steps++;
        if(n%2==0 && n!=0){
            n/=2;
        }else{
            n*=3;
            n++;
        }
        if(n>max)max=n;
    }
    cout << "It takes " << steps << " steps to get one! Max is " << max  << endl;
    return 0;
}