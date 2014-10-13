//Simple program of Fibonacci seq with recursion
//and with static vars
//Dmytro Frolov Oct 2014

#include <iostream>
using namespace std;

unsigned int fibo(int n);
unsigned int fiboRec(int n);

int main()
{
    bool rec = false; // use recursive - true; static - false

    int n = 45; // depth of recursion

    if (rec)
        cout << fiboRec(n);
    else
        cout << fibo(n);


    return 0;
}

unsigned int fiboRec(int n){
    if(n==1||n==0)return 1;
    return fiboRec(n-1)+fiboRec(n-2);
}

unsigned int fibo(int n){
    static unsigned int fib[50];
    if(n==1||n==0)return 1;

    if(fib[n]!=0)return fib[n];

    if (fib[n-1]!=0&&fib[n-2]!=0)
        return fib[n-1]+fib[n-2];

    fib[n-1]=fibo(n-1);
    fib[n-2]=fibo(n-2);

    return fib[n-1]+fib[n-2];
}


/*
int n = 45;

with simple recursion
1836311903
Process returned 0 (0x0)   execution time : 32.500 s
Press any key to continue.

with static recursion
1836311903
Process returned 0 (0x0)   execution time : 0.094 s
Press any key to continue.

*/
