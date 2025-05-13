//
// Created by ray on 5/13/25.
//

#ifndef CODE_CONCRETEPROTOTYPE1_H
#define CODE_CONCRETEPROTOTYPE1_H

#include "Prototype.h"
#include <iostream>
#include <string>

class ConcretePrototype1: public Prototype {
private:
    std::string state;

public:
    ConcretePrototype1(const std::string& initState) : state(initState) {}
    ConcretePrototype1(const ConcretePrototype1& other) : state(other.state) {}

    Prototype* clone() const override {
        return new ConcretePrototype1(*this);
    }

    void setState(const std::string& newState) {
        state = newState;
    }

    void print() const override {
        std::cout << "ConcretePrototype1 state: " << state << std::endl;
    }

    ~ConcretePrototype1() override {
        std::cout << "ConcretePrototype1 destructor called." << std::endl;
    }
};

#endif //CODE_CONCRETEPROTOTYPE1_H
