//**Product Inventory Project** - Create an application which manages an inventory of products.
// Create a product class which has a price, id, and quantity on hand.
// Then create an *inventory* class which keeps track of various products and can sum up the inventory value.
//Dmytro Frolov

#include <iostream>
#include "inventory.h"
using namespace std;

int main()
{
    Inventory * defaultInventory = new Inventory("My inventory");
    for(int j = 0; j < 10; j++)
        defaultInventory->addItem("New item", 22.43*j + 14, j*4+12);
    defaultInventory->printAll();

    cout << "Summary value : " << defaultInventory->summAllValue() << endl;

    delete defaultInventory;
    defaultInventory = nullptr;

    return 0;
}
