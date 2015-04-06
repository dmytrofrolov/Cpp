#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product{
    public:
        Product(int idC, std::string titleC, float priceC, unsigned int quantityC){
            id = idC;
            title = titleC;
            price = priceC;
            quantity = quantityC;
        }
        void setTitle(std::string newTitle);
        void setPrice(float newPrice);
        void setQuantity(unsigned int newQuantity);
        unsigned int getId() const {return id;}
        std::string getTitle() const {return title;}
        float getPrice() const {return price;}
        unsigned int getQuantity() const {return quantity;}

    private:
        unsigned int id = 0;
        std::string title = "";
        float price = 0.00;
        unsigned int quantity = 0;

};

#endif