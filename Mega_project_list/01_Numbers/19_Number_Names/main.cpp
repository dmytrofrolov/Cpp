//Number Names - Show how to spell out a number in English.
// You can use a preexisting implementation or roll your own,
// but you should support inputs up to at least one million
// (or the maximum value of your language's default bounded integer type, if that's less).
// Optional: Support for inputs other than positive integers
// (like zero, negative integers, and floating-point numbers).
// Dmytro Frolov
#include <iostream>
#include <string>

using namespace std;
string spellTheNumber(long long number);
string upToThousand(unsigned short int number);
string upToHundred(unsigned short int number);

int main() {
    long long number = 0;
    cout << "Please, input the number : ";
    cin >> number;
    cout << spellTheNumber(number);
    return 0;
}

string spellTheNumber(long long number) {
    string numberString = "";
    if (number<0) {
        numberString = "minus ";
        number=-number;
    }
    if(number==0)return "Zero";
    if (number>999999999999){
        return "ERROR! Too great number!";
    }
    if(number/1000000000>0){
        numberString+=upToThousand(number/1000000000) + " billion ";
        number%=1000000000;
    }
    if(number/1000000>0){
        numberString+=upToThousand(number/1000000) + " million ";
        number%=1000000;
    }
    if(number/1000>0){
        numberString+=upToThousand(number/1000) + " thousand ";
        number%=1000;
    }

    if(number>0){
        numberString+=upToThousand(number);
    }
    numberString[0]=toupper(numberString[0]);
    return numberString;
}

string upToThousand(unsigned short int number){
    string result = "";
    if(number/100>0)
        result+=upToHundred(number/100) + " hundred";
    if(number/100>0 && number%100!=0)result+= " and ";
    if (number%100!=0)result+=upToHundred(number%100);
    return result;
}

string upToHundred(unsigned short int number){
    string result = "";
    if(number>99)return "Error! Number>99";
    string numbers[10] = {"","one","two","three","four","five","six","seven","eight","nine"};
    string decNumbers[10] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    string toTwenty[10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    if(number>9 && number<20)result=toTwenty[number-10];
    else if(number<10)result=numbers[number];
    else {
        result=decNumbers[number/10];
        if(number%10!=0)
        result+=" "+numbers[number%10];
    }

    return result;
}