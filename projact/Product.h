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
    Product(string n="Unknown", double p=0.0) : Item(n), price(p) { productCount++; }
    virtual ~Product() {}
    void showInfo() const override {
        cout << "Product: " << name << ", Price: " << price << endl;
    }
    double getPrice() const override { return price; }
    static int getProductCount() { return productCount; }
};
int Product::productCount = 0;


#endif // PRODUCT_H
