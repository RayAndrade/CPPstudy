//
// Created by ray on 5/13/25.
//

#ifndef CODE_CONCRETEPROTOTYPE2_H
#define CODE_CONCRETEPROTOTYPE2_H

#include "Prototype.h"
#include <iostream>

class ConcretePrototype2 : public Prototype {
private:
    int number;
public:
    ConcretePrototype2(int initNumber) : number(initNumber) {}
    ConcretePrototype2(const ConcretePrototype2& other) : number(other.number) {}
    Prototype* clone() const override {
        return new ConcretePrototype2(*this);
    }
    void setNumber(int newNumber) {
        number = newNumber;
    }
    void print() const override {
        std::cout << "ConcretePrototype2 number: " << number << std::endl;
    }
    ~ConcretePrototype2() override {
        std::cout << "ConcretePrototype2 destructor called." << std::endl;
    }
};

#endif //CODE_CONCRETEPROTOTYPE2_H
