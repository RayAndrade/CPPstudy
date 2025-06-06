//
// Created by ray on 4/19/25.
//

#ifndef CODE_BUILDER_H
#define CODE_BUILDER_H

#include "Product.h"

class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Product* getResult() = 0;
    virtual ~Builder() {}
};

#endif //CODE_BUILDER_H
