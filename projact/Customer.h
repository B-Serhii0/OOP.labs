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
    Customer(string n="NoName", int a=0, int i=0) : Person(n), id(i), age(a) {}
    void showInfo() const override {
        cout << "Customer ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }
    string getName() const { return name; }
};


#endif // CUSTOMER_H
