//
// Created by ray on 11/25/24.
//

#ifndef CODE_PIZZADIRECTOR_H
#define CODE_PIZZADIRECTOR_H

#include "PizzaBuilder.h"

class PizzaDirector {
public:
    void construct(PizzaBuilder& builder) {
        builder.createNewPizzaProduct();
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};
#endif //CODE_PIZZADIRECTOR_H
