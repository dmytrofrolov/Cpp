// This is a program from Karan project list
// Prime Factorization - Have the user enter a number and
// find all Prime Factors (if there are any) and display them.
// Dmytro Frolov

#include <iostream>
#include <vector>

using namespace std;

// notPrime return 0 if number is prime or the smallest divisor
int notPrime(int num);

int main(){
    vector<int> primes;     //for Prime factors
    int numForPF = 0;       // Number for Prime factorization
    cout << "Please, input number for Prime Factorization : ";
    cin >> numForPF;
    int simplePrime = notPrime(numForPF);  //current smallest Prime factor
    while(simplePrime){     // while numForPF is not prime, add current Prime factor to vector
        primes.push_back(simplePrime);
        numForPF/=simplePrime;
        simplePrime = notPrime(numForPF);
        if(simplePrime==0)primes.push_back(numForPF); // if numForPF is the last Prime factor
    }
    if(primes.size() == 0){ //if there are none Prime factors (if numForPF is prime)
        cout << "You entered prime number " << numForPF;
    } else {
        cout << "Prime factors: ";
        for(int i = 0; i < primes.size(); i++){
            cout << primes[i] << " ";
        }
    }

    cout << endl;
    return 0;
}

int notPrime(int num){
    int smallestDivisor = 0;
    for (int i = 2; i < num; i++){
        if(num%i==0){
            smallestDivisor = i;
            break;
        }
    }
    return  smallestDivisor;
}