//
// Created by ray on 11/25/24.
//

#ifndef CODE_PIZZA_H
#define CODE_PIZZA_H
#include <iostream>
#include <vector>

class Pizza {
private:
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;

public:
    void setDough(const std::string& d) {
        dough = d;
    }

    void setSauce(const std::string& s) {
        sauce = s;
    }

    void addTopping(const std::string& topping) {
        toppings.push_back(topping);
    }

    void display() const {
        std::cout << "Pizza with " << dough << " dough, " << sauce << " sauce, toppings: ";
        for (const auto& topping : toppings) {
            std::cout << topping << " ";
        }
        std::cout << std::endl;
    }
};
#endif //CODE_PIZZA_H
