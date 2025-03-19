//
// Created by ray on 3/16/25.
//

#ifndef CODE_ABSTRACTFACTORY_H
#define CODE_ABSTRACTFACTORY_H

#include "AbstractProductA.h"
#include "AbstractProductB.h"

class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() {} // Virtual destructor
};

#endif //CODE_ABSTRACTFACTORY_H
