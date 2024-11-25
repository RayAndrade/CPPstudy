#include <iostream>
#include "Pizza.h"
#include "PizzaBuilder.h"
#include "HawaiianPizzaBuilder.h"
#include "PizzaDirector.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    PizzaDirector director;
    HawaiianPizzaBuilder hawaiianPizzaBuilder;

    director.construct(hawaiianPizzaBuilder);
    Pizza* pizza = hawaiianPizzaBuilder.getPizza();
    pizza->display();

    delete pizza; // Don't forget to deallocate memory!
    return 0;
}

