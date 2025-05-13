#include "ConcretePrototype1.h"
#include "ConcretePrototype2.h"

// Created by ray on 5/8/25.
//
int main() {

    Prototype* original1 = new ConcretePrototype1("Initial");
    original1->print();

    Prototype* clone1 = original1->clone();
    static_cast<ConcretePrototype1*>(clone1)->setState("Modified Clone");
    clone1->print();
    original1->print();

    Prototype* original2 = new ConcretePrototype2(42);
    original2->print();

    Prototype* clone2 = original2->clone();
    static_cast<ConcretePrototype2*>(clone2)->setNumber(99);
    clone2->print();
    original2->print();

    std::cout << std::endl;

    delete original1;
    delete clone1;
    delete original2;
    delete clone2;
    return 0;
}