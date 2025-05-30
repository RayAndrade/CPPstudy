//
// Created by ray on 3/16/25.
//

#ifndef CODE_CONCRETEFACTORY2_H
#define CODE_CONCRETEFACTORY2_H

#include "AbstractFactory.h"
#include "ConcreteProductA2.h"
#include "ConcreteProductB2.h"

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

#endif //CODE_CONCRETEFACTORY2_H
