//
// Created by ser09 on 28.02.2026.
//

#include <iostream>
#include "Order.h"
#include "Product.h"
#include "Customer.h"
#include "VIPCustomer.h"
#include "ElectronicProduct.h"
#include "FoodProduct.h"
#include "Item.h"
#include "StaticDemo.h"

int main() {

    ElectronicProduct laptop("Laptop",25000,24);
    FoodProduct apple("Apple",30,52);

    Customer c1("Ivan",19,1);
    VIPCustomer vip("Oleg",25,2,10);

    Item* p1 = &laptop;
    Item* p2 = &apple;

    std::cout << "\n--- Runtime polymorphism (pointer) ---\n";
    p1->showInfo();
    p2->showInfo();

    std::cout << "\n--- Runtime polymorphism (reference) ---\n";
    Item& ref = laptop;
    ref.showInfo();

    Order o1(1, p1, c1, 2);
    Order o2(2, p2, vip, 5);

    std::cout << "\n--- Orders ---\n";
    o1.showInfo();
    o2.showInfo();

    std::cout << "\n--- Static binding demo ---\n";
    StaticDemo* sd = new StaticChild();
    sd->show();

    std::cout << "\n--- Interface demo ---\n";
    Printable* pr1 = &laptop;
    Printable* pr2 = &c1;

    pr1->print();
    pr2->print();

    delete sd;

    return 0;
}
