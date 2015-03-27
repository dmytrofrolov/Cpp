//**Fast Exponentiation** - Ask the user to enter 2 integers
// a and b and output a^b (i.e. pow(a,b)) in O(lg n) time complexity.

#include <iostream>

using namespace std;
long long toPow(long int a, unsigned long int b);

int main() {
    long int a = 0;
    unsigned long int b = 0;
    cout << "Solve a^b \nPlease input any a :";
    cin >> a;
    short int sign = 1;
    if(a<0){
        sign=-1;
        a=-a;
    }
    cout << "Input positive b : ";
    cin >> b;

    cout << "a^b=" << sign*toPow(a, b) << endl;
    return 0;
}

long long toPow(long int a, unsigned long int b) {
    unsigned int multiplier = 1;
    int steps = 0;
    long long product = 0;
    while(b!=1){
        if(b%2==0){
            b/=2;
            a*=a;
        }else{
            multiplier*=a;
            b--;
        }
        steps++;
    }
    cout << "Steps : " << steps << endl;
    return a*multiplier;

}

//complexity is really smaller than O(n)
//but I'm not sure is it O(lg n)