//
// Created by ser09 on 07.03.2026.
//
#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "Product.h"

class Order {
private:
    int orderID;
    Product product;
    int quantity;

public:
    Order(int id = 0, int q = 1)
    : orderID(id), product(), quantity(q) {}

    Order(int id, Product p, int q)
    : orderID(id), product(p), quantity(q) {}

    ~Order() {
        std::cout << "Order destroyed: ID " << orderID << std::endl;
    }

    void showInfo() const {
        std::cout << "Order ID: " << orderID << std::endl;
        product.showInfo();
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total: " << quantity * product.getPrice() << std::endl;
    }
};


#endif // ORDER_H
