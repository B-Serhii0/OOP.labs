//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_ELECTRONICPRODUCT_H
#define LAB2_ELECTRONICPRODUCT_H


class ElectronicProduct : public Product {
private:
    int warrantyMonths;
public:
    ElectronicProduct(string n, double p, int w) : Product(n,p), warrantyMonths(w) {}
    void showInfo() const override {
        cout << "[Electronic] " << name
             << " Price: " << price
             << " Warranty: " << warrantyMonths << " months" << endl;
    }
    int getWarranty() const { return warrantyMonths; }
};

#endif //LAB2_ELECTRONICPRODUCT_H