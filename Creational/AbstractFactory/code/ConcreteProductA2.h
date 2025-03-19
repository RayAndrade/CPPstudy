//
// Created by ray on 3/16/25.
//

#ifndef CODE_CONCRETEPRODUCTA2_H
#define CODE_CONCRETEPRODUCTA2_H

#include "AbstractProductA.h"
#include <iostream>

class ConcreteProductA2 : public AbstractProductA{
public:
    void use() override {
        std::cout << "Using ConcreteProductA2" << std::endl;
    }
};

#endif //CODE_CONCRETEPRODUCTA2_H
