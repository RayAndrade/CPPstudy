cmake_minimum_required(VERSION 3.30)
project(code)

set(CMAKE_CXX_STANDARD 20)

add_executable(code main.cpp
        AbstractProductA.h
        AbstractProductB.h
        ConcreteProductA1.h
        ConcreteProductA2.h
        ConcreteProductB1.h
        ConcreteProductB2.h
        AbstractFactory.h
        ConcreteFactory1.h
        ConcreteFactory2.h)
