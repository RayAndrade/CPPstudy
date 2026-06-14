//
// Created by ray on 2026-03-26.
//

#ifndef EXAMPLE_SINGLETON_H
#define EXAMPLE_SINGLETON_H

#include <iostream>

class Singleton {
private:
    static Singleton* _instance;
    Singleton();
public:
    static Singleton* Instance();

    void ShowMessage();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
#endif //EXAMPLE_SINGLETON_H
