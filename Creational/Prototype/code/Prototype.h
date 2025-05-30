//
// Created by ray on 5/13/25.
//
#include <iostream>
#ifndef CODE_PROTOTYPE_H
#define CODE_PROTOTYPE_H

class Prototype {
public:
    virtual ~Prototype() {
        std::cout << "Prototype destructor called." << std::endl;
    }
    virtual Prototype* clone() const = 0;
    virtual void print() const = 0;
};

#endif //CODE_PROTOTYPE_H
