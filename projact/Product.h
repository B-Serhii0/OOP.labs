//
// Created by ser09 on 28.02.2026.
//
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    double price;

public:
    Product() : Product("Unknown", 0.0) {}

    Product(std::string n, double p)
    : name(std::move(n)), price(p) {}

    ~Product() {
        std::cout << "Product destroyed: " << name << std::endl;
    }

    void showInfo() const {
        std::cout << "Product: " << name << ", Price: " << price << std::endl;
    }

    double getPrice() const {
        return price;
    }
};





#endif // PRODUCT_H
