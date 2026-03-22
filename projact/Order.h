//
// Created by ser09 on 07.03.2026.
//
#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "Product.h"
#include "Customer.h"

class Order {
private:
    int orderID;
    Item* item;
    Customer customer;
    int quantity;

public:
    Order(int id, Item* i, const Customer& c, int q)
        : orderID(id), item(i), customer(c), quantity(q) {}

    ~Order() {
        std::cout << "Order destroyed: ID "
                  << orderID << std::endl;
    }

    void showInfo() const {

        std::cout << "\nOrder ID: "
                  << orderID << std::endl;

        customer.showInfo();

        item->showInfo();

        std::cout << "Quantity: "
                  << quantity << std::endl;

        std::cout << "Total: "
                  << quantity * item->getPrice()
                  << std::endl;
    }
};


#endif // ORDER_H
