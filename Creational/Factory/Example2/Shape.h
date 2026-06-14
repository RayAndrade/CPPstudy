//
// Created by ray on 2026-03-18.
//

#ifndef EXAMPLE2_SHAPE_H
#define EXAMPLE2_SHAPE_H
#include <iostream>

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

#endif //EXAMPLE2_SHAPE_H