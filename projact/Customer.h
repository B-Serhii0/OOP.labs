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
    int id;
    int age;

public:
    Customer(std::string n="No name", int a=0, int i=0)
        : Person(n), id(i), age(a) {}

    ~Customer() {
        std::cout << "Customer destroyed: "
                  << name << std::endl;
    }

    void showInfo() const override {
        std::cout << "Customer ID: "
                  << id
                  << ", Name: "
                  << name
                  << ", Age: "
                  << age << std::endl;
    }
};


#endif // CUSTOMER_H
