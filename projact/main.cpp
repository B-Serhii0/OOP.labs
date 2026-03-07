//
// Created by ser09 on 28.02.2026.
//

#include <iostream>
#include "Order.h"
#include "Product.h"
#include "Customer.h"

int main() {

    Product p1("Laptop", 25000);
    Product p2("Mouse", 500);

    Product p3 = p1;

    Product p4 = std::move(p2);

    const Product p5("Keyboard", 1200);

    Customer c1("Ivan", 19);

    Order o1(1, p1, 2);
    Order o2(2, p3, 1);

    std::cout << "\n--- Product Info ---\n";
    p1.showInfo();
    p3.showInfo();

    std::cout << "\n--- Const object ---\n";
    p5.showInfo();

    std::cout << "\n--- Operator + example ---\n";
    std::cout << "Sum of prices: " << p1 + p3 << std::endl;

    std::cout << "\n--- Orders ---\n";
    o1.showInfo();
    o2.showInfo();

    std::cout << "\nTotal of two orders: " << o1 + o2 << std::endl;

    std::cout << "\n--- Static example ---\n";
    std::cout << "Total products created: "
              << Product::getProductCount() << std::endl;

    std::cout << "\n--- Stream operators ---\n";
    Product p6;
    std::cin >> p6;
    std::cout << p6 << std::endl;

    return 0;
}