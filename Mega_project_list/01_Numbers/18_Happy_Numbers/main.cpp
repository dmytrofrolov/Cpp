// Happy Numbers - A happy number is defined by the following process. Starting with any
// positive integer, replace the number by the sum of the squares of its digits, and repeat
// the process until the number equals 1 (where it will stay), or it loops endlessly in
// a cycle which does not include 1. Those numbers for which this process ends in 1 are
// happy numbers, while those that do not end in 1 are unhappy numbers. Display an example
// of your output here. Find first 8 happy numbers.
//Dmytro Frolov
#include <iostream>
#include <set>
using namespace std;

unsigned int digitSquareSum(unsigned int number);
bool isHappySimple(unsigned int number);
bool isHappyWithSet(unsigned int number);

int main() {
    cout << "Input number : " << endl;
    unsigned int number = 0;
    cin >> number;
    cout << "Simple method - " <<(isHappySimple(number)?"Number is Happy":"Number is unhappy") << endl;
    cout << "Method with set - " <<(isHappyWithSet(number)?"Number is Happy":"Number is unhappy") << endl;
    cout << endl;
    unsigned short int happyNumbersCounter = 0;
    unsigned int happyNumber = 1;
    while(happyNumbersCounter<8){
        if(isHappyWithSet(happyNumber)){
            cout << "Happy number #" << happyNumbersCounter+1 << " is " << happyNumber << endl;
            cout.flush();
            happyNumbersCounter++;
        }
        happyNumber++;

    }
    return 0;
}




bool isHappyWithSet(unsigned int number) {
    bool isHappy = false;
    set<unsigned int> digitSquareSums;
    set<unsigned int>::iterator findPos;
    unsigned int currentSum = 0;
    do{
        currentSum = digitSquareSum(number);
        findPos = digitSquareSums.find(currentSum);
        digitSquareSums.insert(currentSum);
        if(currentSum==1)isHappy = true;
        number = currentSum;
    }while(isHappy!=true && findPos==digitSquareSums.end());
    return isHappy;
}

bool isHappySimple(unsigned int number) {
    unsigned int currentSum = 0;
    do{
        currentSum = digitSquareSum(number);
        number = currentSum;
        if(currentSum==1)return true;
        else if (currentSum>1 && currentSum<10)return false;
    }while(1);
}

unsigned int digitSquareSum(unsigned int number) {
    unsigned int tempSum = 0;
    while(number>0){
        tempSum+=(number%10)*(number%10);
        number/=10;
    }
    return tempSum;
}