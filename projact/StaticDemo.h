//
// Created by ser09 on 22.03.2026.
//

#ifndef LAB2_STATICDEMO_H
#define LAB2_STATICDEMO_H


class StaticDemo {
public:
    void show() {
        std::cout << "Base show\n";
    }
};

class StaticChild : public StaticDemo {
public:
    void show() {
        std::cout << "Child show\n";
    }
};

#endif //LAB2_STATICDEMO_H