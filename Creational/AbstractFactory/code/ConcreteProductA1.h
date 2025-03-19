//
// Created by ray on 3/16/25.
//

#ifndef CODE_CONCRETEPRODUCTA1_H
#define CODE_CONCRETEPRODUCTA1_H

#include "AbstractProductA.h"
#include <iostream>

class ConcreteProductA1: public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA1" << std::endl;
    }
};

#endif //CODE_CONCRETEPRODUCTA1_H
