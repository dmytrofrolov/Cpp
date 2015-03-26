#include "complex.h"
#include <iostream>
#include <iomanip>
void Complex::printIt() {
    std::cout << std::setprecision(3) <<realPart << " + " << std::setprecision(3) <<imaginaryPart << " i" << std::endl;
}

Complex::Complex(double realP, double imageP) {
    realPart = realP;
    imaginaryPart = imageP;
}

Complex Complex::operator+(const Complex &comp) {
    Complex complexToReturn(realPart+comp.getReal(),imaginaryPart+comp.getImaginary());
    return complexToReturn;
}

Complex Complex::operator-(const Complex &comp) {
    Complex complexToReturn(realPart-comp.getReal(),imaginaryPart-comp.getImaginary());
    return complexToReturn;
}

Complex Complex::operator*(const Complex &comp) {
    Complex complexToReturn(realPart*comp.getReal()-imaginaryPart*comp.getImaginary(),
            imaginaryPart*comp.getReal()+realPart*comp.getImaginary());
    return complexToReturn;
}

Complex Complex::operator/(const Complex &comp) {
    Complex complexToReturn((realPart*comp.getReal()+imaginaryPart*comp.getImaginary())/(comp.getReal()*comp.getReal()+comp.getImaginary()*comp.getImaginary()),
            (imaginaryPart*comp.getReal()-realPart*comp.getImaginary())/(comp.getReal()*comp.getReal()+comp.getImaginary()*comp.getImaginary()) );
    return complexToReturn;
}
