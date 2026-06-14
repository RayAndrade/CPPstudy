//
// Created by ray on 2026-03-23.
//
#include "ConcretePrototype1.h"
#include <iostream>
using std::cout;
using std::endl;

ConcretePrototype1::ConcretePrototype1(const string& name, int id) : Prototype(name), id(id) {}
ConcretePrototype1* ConcretePrototype1::Clone() const {
    return new ConcretePrototype1(*this);
}

void ConcretePrototype1::Show() const {
    cout << "ConcretePrototype1 -> Name: " << name << ", ID: " << id << endl;
}