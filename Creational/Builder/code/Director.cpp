//
// Created by ray on 4/19/25.
//
#include "Director.h"

void Director::construct(Builder* builder) {
    builder->buildPartA();
    builder->buildPartB();
}