#include <iostream>
#include "IntegerSet.h"
using std::cout;
using std::endl;

int main()
{
    int initialArray1[] = {1, 2, 3, 6, 5, 4};
    IntegerSet set1(initialArray1, 6);
    set1.printIt();

    cout << endl;

    int initialArray2[] = {5, 8, 12, 6, 23, 4};
    IntegerSet set2(initialArray2, 6);
    set2.printIt();

    cout << endl;

    IntegerSet set3;
    set3.printIt();

    cout << endl;

    set3 = IntegerSet::unionOfSet(set1, set2);
    set3.printIt();

    cout << endl;

    IntegerSet set4(initialArray1, 6);

    cout << IntegerSet::isEqual(set1, set4) << endl;

    return 0;
}
