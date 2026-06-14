//
// Created by ray on 2026-03-23.
//

#include "ConcretePrototype2.h"
#include <iostream>
using std::cout;
using std::endl;

ConcretePrototype2::ConcretePrototype2(const string& name, double value) : Prototype(name), value(value) {}

ConcretePrototype2* ConcretePrototype2::Clone() const {
    return new ConcretePrototype2(*this);
}
void ConcretePrototype2::Show() const {
    cout << "ConcretePrototype2 -> Name: " << name << ", Value: " << value << endl;
}