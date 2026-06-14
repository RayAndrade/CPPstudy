//
// Created by ray on 2026-03-23.
//

#ifndef BEGINNING_PROTOTYPE_H
#define BEGINNING_PROTOTYPE_H

#include <string>
using std::string;

class Prototype {
protected:
    string name;
public:
    Prototype(const string& name) : name(name) {}
    virtual Prototype* Clone() const = 0;
    virtual void Show() const = 0;
};

#endif //BEGINNING_PROTOTYPE_H