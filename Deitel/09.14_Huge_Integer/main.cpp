#include <iostream>
#include "hugeinteger.h"
using namespace std;

int main() {
    HugeInteger a("1234567890123546890");
    a.printIt();
    cout << endl;
    HugeInteger b("1234578905233735675");
    b.printIt();
    cout << endl;
    (a+b).printIt();
    return 0;
}