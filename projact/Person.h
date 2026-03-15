//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_PERSON_H
#define LAB2_PERSON_H
#include <iostream>
#include <string>
#

class Person {
protected:
    std::string name;

public:
    Person(std::string n="NoName")
        : name(n) {}

    virtual ~Person() {
        std::cout << "Person destroyed: "
                  << name << std::endl;
    }

    virtual void showInfo() const {
        std::cout << "Person: "
                  << name << std::endl;
    }
};


#endif //LAB2_PERSON_H