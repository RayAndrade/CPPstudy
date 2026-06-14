//
// Created by ray on 2026-04-09.
//

#ifndef EXAMPLE_ABSTRACTION_H
#define EXAMPLE_ABSTRACTION_H

#include <string>
#include "Implementation.h"

class Abstraction {
protected:
    Implementation* implementation_;
public:
    Abstraction(Implementation* implementation) : implementation_(implementation) {}
    virtual ~Abstraction() {}
    virtual std::string Operation() const {
        return "Abstraction: Base operation with:\n" +
               this->implementation_->OperationImplementation();
    }

};
#endif //EXAMPLE_ABSTRACTION_H
