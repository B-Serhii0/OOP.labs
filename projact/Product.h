//
// Created by ser09 on 28.02.2026.
//
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include "Item.h"
class Product : public Item {
private:
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

    Product(const Product& other)
        : Item(other.name), price(other.price)
    {
        productCount++;
    }

    Product(Product&& other) noexcept
        : Item(std::move(other.name)), price(other.price)
    {
        other.price = 0;
        productCount++;
    }

    Product& operator=(const Product& other)
    {
        if (this != &other) {
            name = other.name;
            price = other.price;
        }
        return *this;
    }

    virtual ~Product() {
        std::cout << "Product destroyed: " << name << std::endl;
    }

    void showInfo() const override {
        std::cout << "Product: " << name
                  << ", Price: " << price << std::endl;
    }

    double getPrice() const {
        return price;
    }

    static int getProductCount() {
        return productCount;
    }

    double operator+(const Product& other) const {
        return this->price + other.price;
    }

    Product operator-() const {
        return Product(this->name, -this->price);
    }

    friend std::ostream& operator<<(std::ostream& os, const Product& p) {
        os << "Product: " << p.name << " Price: " << p.price;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Product& p) {
        std::cout << "Enter product name: ";
        is >> p.name;
        std::cout << "Enter price: ";
        is >> p.price;
        return is;
    }
};

int Product::productCount = 0;





#endif // PRODUCT_H
