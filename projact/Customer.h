//
// Created by ser09 on 07.03.2026.
//
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

class Customer {
private:
    std::string name;
    int age;

public:
    Customer() : Customer("No name", 0) {}

    Customer(std::string n, int a)
    : name(std::move(n)), age(a) {}

    ~Customer() {
        std::cout << "Customer destroyed: " << name << std::endl;
    }

    void showInfo() const {
        std::cout << "Customer: " << name << ", Age: " << age << std::endl;
    }
};


#endif // CUSTOMER_H
