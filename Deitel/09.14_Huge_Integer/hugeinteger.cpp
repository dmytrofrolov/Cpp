#include "hugeinteger.h"
#include <string>
#include <iostream>

HugeInteger::HugeInteger(std::string number) {
    for(int i = 0; i<40;hugeNumber[i++]=0);
    for(int i = 0; i<number.length() && i<40; i++){
        hugeNumber[i+40-number.length()]=number[i]-'0';
    }
}

void HugeInteger::printIt() {
    int i = 0;
    while(hugeNumber[i++]==0);i--;
    for(; i<40; i++){
        std::cout << hugeNumber[i];
    }
}

HugeInteger HugeInteger::operator+(const HugeInteger &rightHuge) {
    int tempInMemory = 0;
    HugeInteger tempHuge("0");
    for(int i = 39; i >=0; i--){
        int tempSum = hugeNumber[i]+rightHuge.getIDigit(i)+tempInMemory;
        tempInMemory=0;
        if(tempSum>9){
            tempInMemory=tempSum/10;
            tempSum%=10;
        }
        tempHuge.setIDigit(i, tempSum);
    }

    return tempHuge;
}

int HugeInteger::getIDigit(int i) const {
    if(i>=0&&i<40)return hugeNumber[i];
    return 0;
}
