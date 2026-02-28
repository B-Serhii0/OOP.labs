//
// Created by ser09 on 28.02.2026.
//
#include <iostream>
#include <string>
#ifndef LAB2_MAIN_H
#define LAB2_MAIN_H


/* ---------- Class Product ---------- */
class Product {
private:
    std::string name;
    double price;

public:
    // Конструктор за замовчуванням (делегує іншому)
    Product() : Product("Unknown", 0.0) {}

    // Конструктор з параметрами
    Product(std::string n, double p)
    : name(std::move(n)), price(p) {}

    // Деструктор
    ~Product() {
        std::cout << "Product destroyed: " << name << std::endl;
    }

    // Методи
    void showInfo() const {
        std::cout << "Product: " << name << ", Price: " << price << std::endl;
    }

    double getPrice() const {
        return price;
    }
};

/* ---------- Клас Customer ---------- */
class Customer {
private:
    std::string name;
    int age;

public:
    // Конструктор за замовчуванням
    Customer() : Customer("No name", 0) {}

    // Перевантажений конструктор
    Customer(std::string n, int a)
    : name(std::move(n)), age(a) {}

    // Деструктор
    ~Customer() {
        std::cout << "Customer destroyed: " << name << std::endl;
    }

    // Метод
    void showInfo() const {
        std::cout << "Customer: " << name << ", Age: " << age << std::endl;
    }
};

/* ---------- Клас Order ---------- */
class Order {
private:
    int orderID;
    Product product;
    int quantity;

public:
    // Конструктор з параметрами за замовчуванням
    Order(int id = 0, int q = 1)
    : orderID(id), product(), quantity(q) {}

    // Перевантажений конструктор
    Order(int id, Product p, int q)
    : orderID(id), product(p), quantity(q) {}

    // Деструктор
    ~Order() {
        std::cout << "Order destroyed: ID " << orderID << std::endl;
    }

    // Метод
    void showInfo() const {
        std::cout << "Order ID: " << orderID << std::endl;
        product.showInfo();
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total: " << quantity * product.getPrice() << std::endl;
    }
};


#endif //LAB2_MAIN_H