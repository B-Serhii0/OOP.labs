//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_FOODPRODUCT_H
#define LAB2_FOODPRODUCT_H


class FoodProduct : public Product {
private:
    int calories;
public:
    FoodProduct(string n, double p, int c) : Product(n,p), calories(c) {}
    void showInfo() const override {
        cout << "[Food] " << name
             << " Price: " << price
             << " Calories: " << calories << endl;
    }
    int getCalories() const { return calories; }
};


#endif //LAB2_FOODPRODUCT_H