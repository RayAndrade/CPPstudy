#include "ShapeFactory.h"
#include <memory>

int main() {
    ShapeFactory shapeFactory;
    std::unique_ptr<Shape> shape1(shapeFactory.getShape("CIRCLE"));
    if (shape1 != nullptr) {
        shape1->draw();
    }
    std::unique_ptr<Shape> shape2(shapeFactory.getShape("SQUARE"));
    if (shape2 != nullptr) {
        shape2->draw();
    }
    return 0;
}
