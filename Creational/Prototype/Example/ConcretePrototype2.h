//
// Created by ray on 2026-03-23.
//

#ifndef BEGINNING_CONCRETEPROTOTYPE2_H
#define BEGINNING_CONCRETEPROTOTYPE2_H

#include "ConcretePrototype1.h"
#include <iostream>
using std::cout;
using std::endl;

class ConcretePrototype2: public Prototype {
private:
    double value;
public:
    ConcretePrototype2(const string& name, double value);
    ConcretePrototype2* Clone() const override;
    void Show() const override;
};

#endif //BEGINNING_CONCRETEPROTOTYPE2_H