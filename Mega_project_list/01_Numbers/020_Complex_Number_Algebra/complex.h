#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex{
    public:
        Complex(double realP, double imageP);
        Complex operator+ (const Complex &comp);
        Complex operator- (const Complex &comp);
        Complex operator* (const Complex &comp);
        Complex operator/ (const Complex &comp);
        void printIt();
        double getReal() const {return realPart;}
        double getImaginary() const {return imaginaryPart;}

    private:
        double realPart;
        double imaginaryPart;
};

#endif //COMPLEX_HPP