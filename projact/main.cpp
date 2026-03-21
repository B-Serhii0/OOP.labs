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

int main() {

    ElectronicProduct laptop("Laptop",25000,24);
    FoodProduct apple("Apple",30,52);

    Customer c1("Ivan",19,1);
    VIPCustomer vip("Oleg",25,2,10);

    Order o1(1,laptop,c1,2);
    Order o2(2,apple,vip,5);

    std::cout << "\n--- Products ---\n";
    laptop.showInfo();
    apple.showInfo();

    std::cout << "\n--- Customers ---\n";
    c1.showInfo();
    vip.showInfo();

    std::cout << "\n--- Orders ---\n";
    o1.showInfo();
    o2.showInfo();

    std::cout << "\n--- Operator + example ---\n";
    std::cout << "Sum of prices: "
              << laptop + apple << std::endl;

    std::cout << "\n--- Static example ---\n";
    std::cout << "Total products created: "
              << Product::getProductCount()
              << std::endl;

    std::cout << "\n--- Stream operators ---\n";
    Product p6;
    std::cin >> p6;
    std::cout << p6 << std::endl;

    return 0;
}