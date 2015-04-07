// This is a program from Karan project list
//Find PI to the Nth Digit - Enter a number and have the program generate PI
// up to that many decimal places. Keep a limit to how far the program will go.
// Dmytro Frolov

#include <iostream>
#include <math.h>
using namespace std;
int factorial(int n);

// todo implement class to operate with big numbers

int main()
{

// do while iteration is less than precision
//input how much numbers do we need
    unsigned short int precision = 0;
    cout << "Enter precision (number of digits after decimal point): ";
    cin >> precision;
    char *pi = new char;
    double doublePi = 0, previousPi = 0;
    double difference = 2;
    //cout << pow(10, -precision);
    double multiplier = 0;
    int k = 0;
    do{
        if(doublePi>0) doublePi=1.0/(doublePi);
        doublePi += 12*((pow(-1, k)*factorial(6*k)*(13591409.0000 + 545140134.0000 * k))/(factorial(3*k)*pow(factorial(k),3)*pow(640320.0000,(3*k+3.0/2.0))));
        doublePi = 1.0000 / doublePi;
        //cout << "DoublePi = " << doublePi << endl;
        k++;
        difference = doublePi - previousPi ;
        //cout << "difference== " << difference << " k== " << k <<  endl;

        if(previousPi > 0){
            double tempPi = doublePi;
            for(int i = 0; i<precision+2; i++){
                if(i==1){pi[i]='.';continue;}
                pi[i] = '0'+floor(tempPi);
                tempPi-= floor(tempPi);
                tempPi*=10;
            }

        }

        previousPi = doublePi;
    }while(difference > pow(10, -precision));
    cout << "pi == ";
    for(int i = 0; i < precision + 2; i ++ ){
        cout << pi[i];
        if((i-1)%5 == 0)cout << " ";
    }

    cout << endl;
    return 0;
}


int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
