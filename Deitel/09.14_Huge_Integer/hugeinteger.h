#ifndef HUGEINTEGER_HPP
#define HUGEINTEGER_HPP

#include <string>

class HugeInteger{
    public:
        HugeInteger(std::string number);
        void printIt();
        HugeInteger operator+ (const HugeInteger & rightHuge);
        int getNumberLength() const {return numberLength;}
        int getIDigit(int i) const;
        void setIDigit(int i, int n){hugeNumber[i]=n%10;}
    private:
        int hugeNumber[40];
        int numberLength;
};

#endif //HUGEINTEGER_HPP