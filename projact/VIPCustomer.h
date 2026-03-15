//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_VIPCUSTOMER_H
#define LAB2_VIPCUSTOMER_H


class VIPCustomer : public Customer {
private:
    double discount;

public:
    VIPCustomer(std::string n, int a, double d)
        : Customer(n,a), discount(d) {}

    ~VIPCustomer() {
        std::cout << "VIPCustomer destroyed\n";
    }

    void showInfo() const override {
        Customer::showInfo();
        std::cout << "Discount: "
                  << discount << "%\n";
    }
};


#endif //LAB2_VIPCUSTOMER_H