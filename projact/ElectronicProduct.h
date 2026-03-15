//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_ELECTRONICPRODUCT_H
#define LAB2_ELECTRONICPRODUCT_H


class ElectronicProduct : public Product {
private:
    int warrantyMonths;

public:
    ElectronicProduct(std::string n, double p, int w)
        : Product(n, p), warrantyMonths(w) {}

    ~ElectronicProduct() {
        std::cout << "ElectronicProduct destroyed\n";
    }

    void showInfo() const override {
        Product::showInfo();
        std::cout << "Warranty: "
                  << warrantyMonths << " months\n";
    }
};


#endif //LAB2_ELECTRONICPRODUCT_H