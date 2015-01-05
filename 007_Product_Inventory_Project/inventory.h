#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include "product.h"
#include <vector>
class Inventory{
    public:
        Inventory(std::string inventoryTitle = "Default inventory");
        ~Inventory();
        bool addItem(std::string title, float price, unsigned int quantity);
        void printAll();
    private:
        std::vector<Product> * inventaryItems;
        unsigned int itemsCount = 0;
};

#endif