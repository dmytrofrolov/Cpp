#include "product.h"
#include <string>
#include <iostream>

void Product::setTitle(std::string newTitle) {
    std::cout << "Title of product id #" << id << " changed from " << title << " to " << newTitle << std::endl;
    title = newTitle;
}


void Product::setPrice(float newPrice) {
    std::cout << "Price of product id #" << id << " changed from " << price << " to " << newPrice << std::endl;
    price = newPrice;
}

void Product::setQuantity(unsigned int newQuantity) {
    std::cout << "Quantity of product id #" << id << " changed from " << quantity << " to " << newQuantity << std::endl;
    quantity = newQuantity;
}
