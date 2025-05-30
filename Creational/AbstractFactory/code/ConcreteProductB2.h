//
// Created by ray on 3/16/25.
//

#ifndef CODE_CONCRETEPRODUCTB2_H
#define CODE_CONCRETEPRODUCTB2_H

#include "AbstractProductB.h"
#include <iostream>

class ConcreteProductB2 : public AbstractProductB {
public:
    void use() override {
        std::cout << "Using ConcreteProductB2" << std::endl;
    }
};

#endif //CODE_CONCRETEPRODUCTB2_H
