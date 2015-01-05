//**Product Inventory Project** - Create an application which manages an inventory of products.
// Create a product class which has a price, id, and quantity on hand.
// Then create an *inventory* class which keeps track of various products //and can sum up the inventory value.
//Dmytro Frolov

#include <iostream>
#include "inventory.h"
#include <string>
using namespace std;

int main()
{
    int i;
    cin >> i;
    Inventory * defaultInventory = new Inventory("My inventory");
    for(int j = 0; j < 10000; j++)
        defaultInventory->addItem("New item", 12.45*j, 121+j*4);

    defaultInventory->printAll();
    cout << "Hello world!" << endl;
    cin >> i;
    delete defaultInventory;
    defaultInventory = nullptr;
    cin >> i;
    return 0;
}
