//
// Created by ray on 12/20/24.
//

#ifndef CODE_PROTOTYPE_H
#define CODE_PROTOTYPE_H

class Prototype {
public:
    virtual ~Prototype() {}
    virtual Prototype* clone() const = 0;
};

#endif //CODE_PROTOTYPE_H
