//
// Created by ray on 11/25/24.
//

#ifndef CODE_HAWAIIANPIZZABUILDER_H
#define CODE_HAWAIIANPIZZABUILDER_H

#include "PizzaBuilder.h"

class HawaiianPizzaBuilder : public PizzaBuilder {

    void buildDough() override {
        pizza->setDough("cross");
    }

    void buildSauce() override {
        pizza->setSauce("mild");
    }

    void buildTopping() override {
        pizza->addTopping("ham");
        pizza->addTopping("pineapple");
    }

public:
    virtual ~HawaiianPizzaBuilder() {}
};
#endif //CODE_HAWAIIANPIZZABUILDER_H
