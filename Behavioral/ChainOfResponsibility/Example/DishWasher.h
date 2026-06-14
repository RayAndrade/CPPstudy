//
// Created by ray on 2026-02-15.
//

#ifndef EXAMPLE_DISHWASHER_H
#define EXAMPLE_DISHWASHER_H
#include <iostream>
#include <memory>

class DishWasher {
public:
    virtual ~DishWasher() = default;
    void setNext(std::shared_ptr<DishWasher> nextWasher) { this->nextWasher = nextWasher; }
    virtual void washDishes(const std::string& dishType) = 0;

protected:
    std::shared_ptr<DishWasher> nextWasher;
};

#endif //EXAMPLE_DISHWASHER_H