//
// Created by ser09 on 15.03.2026.
//

#ifndef LAB2_PERSON_H
#define LAB2_PERSON_H
#include <iostream>
#include <string>


class Person : public Printable {
protected:
    string name;
public:
    Person(string n="NoName") : name(n) {}
    virtual ~Person() {}
    virtual void showInfo() const { cout << "Person: " << name << endl; }
    void print() const override { cout << "Printing Person: " << name << endl; }
};


#endif //LAB2_PERSON_H