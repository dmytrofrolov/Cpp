//Is there a triangle with integer sides, medians and area
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned long int a = 0, b = 0, c = 0;
    double ma = 0, mb = 0, mc = 0, p = 0, square = 0;
    for(a = 1; a < 10000; a++){
        for(b = a; b < 10000; b++)
            for(c = b; c < 10000; c++)
                if(a+b>c && a+c>b && c+b>a){
                    p = (a + b + c)*1.0/2.0;
                    square = sqrt(p*(p-a)*(p-b)*(p-c));
                    ma = sqrt((2*b*b+2*c*c-a*a)/4.0);
                    mb = sqrt((2*a*a+2*c*c-b*b)/4.0);
                    mc = sqrt((2*b*b+2*a*a-c*c)/4.0);
                    if(square - round(square)==0 && ma - round(ma)==0 && mb - round(mb)==0 && mc - round(mc)==0)
                        cout << a << " " << b << " " << c << " " << endl;
                }
    cout << "a=" << a << endl;
    }
    return 0;
}