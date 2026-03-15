//
// Created by ser09 on 07.03.2026.
//
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "Person.h"

class Customer : public Person {
private:
    int age;

public:
    Customer(std::string n="No name", int a=0)
        : Person(n), age(a) {}

    ~Customer() {
        std::cout << "Customer destroyed: "
                  << name << std::endl;
    }

    void showInfo() const override {
        std::cout << "Customer: "
                  << name
                  << ", Age: "
                  << age << std::endl;
    }
};


#endif // CUSTOMER_H
