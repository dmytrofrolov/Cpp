//Binary to Decimal and Back Converter - Develop a converter
// to convert a decimal number to binary
// or a binary number to its decimal equivalent.
// Dmytro Frolov

#include <iostream>
#include <cmath>
using namespace std;

long long decToBin(long int decNum);
long int binToDec(long long binNum);
int main() {
    cout << binToDec(11111011111) << endl;
    cout << decToBin(2015) << endl;
    return 0;
}


long long decToBin(long int decNum) {
    short int sign = 1;
    if(decNum<0){
        sign=-1;
        decNum=-decNum;
    }
    long long binNum = 0;
    unsigned int i = 0;
    while(decNum>0){
        binNum += (decNum%2)*ceil(pow(10,i++));
        decNum/=2;
    }
    return binNum*sign;
}


long int binToDec(long long binNum) {
    short int sign = 1;
    if(binNum<0){
        sign=-1;
        binNum=-binNum;
    }
    long int decNum = 0;
    unsigned int i = 0;
    while(binNum>0){
        decNum+=(binNum%10)*ceil(pow(2,i++));
        binNum/=10;
    }
    return decNum*sign;
}