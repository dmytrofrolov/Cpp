//**Complex Number Algebra** - Show addition, multiplication, negation,
// and inversion of complex numbers in separate functions.
// (Subtraction and division operations can be made with pairs of these operations.)
// Print the results for each operation tested.
// The seperate class is added for this purpose
// Dmytro Frolov
#include <iostream>
#include "complex.h"

using namespace std;

int main() {
    Complex a(1,2);
    Complex b(5,4);
    Complex c = a + b;
    c.printIt();
    (a-b).printIt();
    (a*b).printIt();
    (a/b).printIt();
    return 0;
}