cmake_minimum_required(VERSION 3.31)
project(code)

set(CMAKE_CXX_STANDARD 20)

add_executable(code main.cpp
        Product.h
        Product.cpp
        Builder.h
        ConcreteBuilder.h
        ConcreteBuilder.cpp
        Director.h
        Director.cpp
)
