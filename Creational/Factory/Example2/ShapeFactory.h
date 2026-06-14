//
// Created by ray on 2026-03-18.
//

#ifndef EXAMPLE2_SHAPEFACTORY_H
#define EXAMPLE2_SHAPEFACTORY_H

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <string>

class ShapeFactory {
public:
    Shape* getShape(const std::string& shapeType) {
        if (shapeType == "CIRCLE") {
            return new Circle();
        } else if (shapeType == "SQUARE") {
            return new Square();
        }
        return nullptr;
    }
};

#endif //EXAMPLE2_SHAPEFACTORY_H