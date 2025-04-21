//
// Created by ray on 4/19/25.
//

#ifndef CODE_CONCRETEBUILDER_H
#define CODE_CONCRETEBUILDER_H

#include "Builder.h"

class ConcreteBuilder : public Builder{
private:
    Product* product;
public:
    ConcreteBuilder();
    ~ConcreteBuilder();

    void buildPartA() override;
    void buildPartB() override;

    Product* getResult() override;


};

#endif //CODE_CONCRETEBUILDER_H
