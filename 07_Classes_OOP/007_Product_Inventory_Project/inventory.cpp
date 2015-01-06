#include "inventory.h"
#include <iostream>
#include <string>

Inventory::Inventory(std::string inventoryTitle) {
    std::cout << "Inventory created! With Title: " << inventoryTitle  << std::endl;
    inventaryItems = new std::vector<Product>;
}

Inventory::~Inventory() {
    delete inventaryItems;
    inventaryItems = nullptr;
}

bool Inventory::addItem(std::string title, float price, unsigned int quantity) {
    inventaryItems->push_back(Product(++itemsCount, title, price, quantity));
    return true;
}

void Inventory::printAll() {
    for(std::vector<Product>::iterator i = inventaryItems->begin(); i < inventaryItems->end(); i++){
        std::cout   << "Id # "      << i->getId()
                    << "\tTitle: \""   << i->getTitle()
                    << "\"\tPrice: "   << i->getPrice()
                    << "\tQuantity: "<< i->getQuantity()
                    << std::endl;
    }
}

float Inventory::summAllValue() const {
    float tempValue = 0;
    for(std::vector<Product>::iterator i = inventaryItems->begin(); i < inventaryItems->end(); i++){
        tempValue+=i->getPrice() * i->getQuantity();
    }
    return tempValue;
}
