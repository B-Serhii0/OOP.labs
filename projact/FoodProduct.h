//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_FOODPRODUCT_H
#define LAB2_FOODPRODUCT_H


class FoodProduct : public Product {
private:
    int calories;

public:
    FoodProduct(std::string n, double p, int c)
        : Product(n, p), calories(c) {}

    ~FoodProduct() {
        std::cout << "FoodProduct destroyed\n";
    }

    void showInfo() const override {
        Product::showInfo();
        std::cout << "Calories: "
                  << calories << std::endl;
    }
};


#endif //LAB2_FOODPRODUCT_H