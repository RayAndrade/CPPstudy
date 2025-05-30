//
// Created by ray on 3/16/25.
//

#ifndef CODE_CONCRETEFACTORY1_H
#define CODE_CONCRETEFACTORY1_H

#include "AbstractFactory.h"
#include "ConcreteProductA1.h"
#include "ConcreteProductB1.h"

class ConcreteFactory1: public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

#endif //CODE_CONCRETEFACTORY1_H
