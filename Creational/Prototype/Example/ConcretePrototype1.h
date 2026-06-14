//
// Created by ray on 2026-03-23.
//

#ifndef BEGINNING_CONCRETEPROTOTYPE1_H
#define BEGINNING_CONCRETEPROTOTYPE1_H

#include "Prototype.h"
#include <string>

class ConcretePrototype1 : public Prototype {
private:
    int id;
public:
    ConcretePrototype1(const string& name, int id);
    ConcretePrototype1* Clone() const override;
    void Show() const override;
};

#endif //BEGINNING_CONCRETEPROTOTYPE1_H