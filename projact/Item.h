//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_ITEM_H
#define LAB2_ITEM_H
#include <iostream>
#include <string>
#include "Printable.h"

class Item : public Printable {
protected:
    std::string name;

public:
    Item(std::string n = "Unknown") : name(n) {
        std::cout << "Item constructor\n";
    }

    virtual ~Item() {
        std::cout << "Item destroyed: " << name << std::endl;
    }

    virtual void showInfo() const {
        std::cout << "Item: " << name << std::endl;
    }

    virtual double getPrice() const = 0; // PURE VIRTUAL

    void print() const override {
        std::cout << "Printing Item: " << name << std::endl;
    }
};


#endif //LAB2_ITEM_H