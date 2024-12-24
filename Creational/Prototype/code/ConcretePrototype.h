//
// Created by ray on 12/20/24.
//

#ifndef CODE_CONCRETEPROTOTYPE_H
#define CODE_CONCRETEPROTOTYPE_H

#include "Prototype.h"
#include <string>

class ConcretePrototype : public Prototype {
private:
    std::string data;

public:
    ConcretePrototype(std::string data) : data(data) {}
    ConcretePrototype(const ConcretePrototype& other) : data(other.data) {}
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    std::string getData() const {
        return data;
    }
};

#endif //CODE_CONCRETEPROTOTYPE_H
