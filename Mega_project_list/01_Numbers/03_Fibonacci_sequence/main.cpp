//Fibonacci Sequence - Enter a number and have the program generate
// the Fibonacci sequence to that number or to the Nth number.
//Implemented by recursion and with static variables
//Dmytro Frolov

#include <iostream>
using namespace std;

unsigned int fibo(int n);
unsigned int fiboRec(int n);    //find seq element number N

int main()
{
    bool rec = false; // use recursive - true; static - false

    int n = 45; // depth of recursion

    if (rec)
        cout << fiboRec(n);
    else
        cout << fibo(n) << endl << endl;

    cout << "How much Fibo elements do you want? : ";
    cin >> n;

    for(int i = 0; i<n; i++)
        cout << fibo(i) << " ";
    cout << endl;


    cout << endl << "To what number genetate the seq? : ";
    cin >> n;
    for(int i = 0; fibo(i)<n; i++)cout << fibo(i) << " " ;
    cout << endl;


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

    fib[n-2]=fibo(n-2);
    fib[n-1]=fibo(n-1);

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
