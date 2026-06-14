#include <iostream>
#include "ConcretePrototype1.h"
#include "ConcretePrototype2.h"

using std::cout;
using std::endl;


int main() {
    cout << "Prototype Design Pattern Demo in C++" << endl;
    cout << "-----------------------------------" << endl;

    Prototype* original1 = new ConcretePrototype1("Original One", 101);
    Prototype* original2 = new ConcretePrototype2("Original Two", 99.95);

    cout << endl;
    cout << "Original objects:" << endl;
    original1->Show();
    original2->Show();

    return 0;

}
