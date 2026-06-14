//
// Created by ray on 2026-04-09.
//

#ifndef EXAMPLE_EXTENDEDABSTRACTION_H
#define EXAMPLE_EXTENDEDABSTRACTION_H

#include "Abstraction.h"

class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) { }
    std::string Operation() const override {
        return "ExtendedAbstraction: Extended operation with:\n" +
               this->implementation_->OperationImplementation();
    }
};

#endif //EXAMPLE_EXTENDEDABSTRACTION_H
