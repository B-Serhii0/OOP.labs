//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_ITEM_H
#define LAB2_ITEM_H
using namespace std;
#include "Printable.h"
#include <iostream>
#include <string>


class Item : public Printable {
protected:
    string name;
public:
    Item(string n = "Unknown") : name(n) {}
    virtual ~Item() {}
    virtual void showInfo() const {
        cout << "Item: " << name << endl;
    }
    virtual double getPrice() const = 0;
    void print() const override {
        cout << "Printing Item: " << name << endl;
    }
    string getName() const { return name; }
};

#endif //LAB2_ITEM_H