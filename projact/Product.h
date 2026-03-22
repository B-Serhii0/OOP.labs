//
// Created by ser09 on 28.02.2026.
//
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include "Item.h"

class Product : public Item {
protected:
    double price;
    static int productCount;

public:
    Product() : Item("Unknown"), price(0.0) {
        productCount++;
    }

    Product(std::string n, double p)
        : Item(n), price(p)
    {
        productCount++;
    }

    virtual ~Product() {
        std::cout << "Product destroyed: " << name << std::endl;
    }

    void showInfo() const override {
        std::cout << "Product: " << name
                  << ", Price: " << price << std::endl;
    }

    double getPrice() const override {
        return price;
    }

    static int getProductCount() {
        return productCount;
    }
};

int Product::productCount = 0;



#endif // PRODUCT_H
