//
// Created by ray on 11/25/24.
//

#ifndef CODE_PIZZABUILDER_H
#define CODE_PIZZABUILDER_H

#include "Pizza.h"

class PizzaBuilder {
protected:
    Pizza* pizza;

public:
    PizzaBuilder() : pizza(nullptr) {}
    virtual ~PizzaBuilder() {}
    Pizza* getPizza() {
        return pizza;
    }
    void createNewPizzaProduct() {
        pizza = new Pizza();
    }

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;

};
#endif //CODE_PIZZABUILDER_H
