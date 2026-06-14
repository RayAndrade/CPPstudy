//
// Created by ray on 2026-04-09.
//

#ifndef EXAMPLE_IMPLEMENTATION_H
#define EXAMPLE_IMPLEMENTATION_H

#include <iostream>

class Implementation {
public:
    virtual ~Implementation() {}
    virtual std::string OperationImplementation() const = 0;
};
#endif //EXAMPLE_IMPLEMENTATION_H
