//
// Created by ray on 3/16/25.
//


#ifndef CODE_CONCRETEPRODUCTB1_H
#define CODE_CONCRETEPRODUCTB1_H

#include "AbstractProductB.h"
#include <iostream>

class ConcreteProductB1: public AbstractProductB{
public:
    void use() override {
        std::cout << "Using ConcreteProductB1" << std::endl;
    }
};

#endif //CODE_CONCRETEPRODUCTB1_H
