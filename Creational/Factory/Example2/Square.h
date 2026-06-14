//
// Created by ray on 2026-03-18.
//

#ifndef EXAMPLE2_SQUARE_H
#define EXAMPLE2_SQUARE_H

#include "Shape.h"

class Square: public Shape {
public:
    void draw() const override {
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};

#endif //EXAMPLE2_SQUARE_H