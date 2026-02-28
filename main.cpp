//
// Created by ser09 on 28.02.2026.
//

#include "main.h"
int main() {
    // Створення товару
    Product p1("Laptop", 25000);
    Product p2;

    // Створення клієнта
    Customer c1("Ivan", 19);
    Customer c2;

    // Створення замовлень
    Order o1(1, p1, 2);
    Order o2;

    std::cout << "\n--- Product Info ---\n";
    p1.showInfo();
    p2.showInfo();

    std::cout << "\n--- Customer Info ---\n";
    c1.showInfo();
    c2.showInfo();

    std::cout << "\n--- Order Info ---\n";
    o1.showInfo();
    o2.showInfo();

    return 0;
}