
# 🧬 Prototype Design Pattern in C++

**Pattern Category**: Creational
**Based on**: *Design Patterns: Elements of Reusable Object-Oriented Software*
**Language**: C++
**Demo File**: `main.cpp`

---

## 📖 Intent

The **Prototype pattern** lets you create new objects by copying existing ones, without knowing their exact class. This is useful when object creation is expensive or complex.

---

## ✅ Class Creation Order

To avoid dependency issues, create classes in this order:

1. `Prototype.h` (interface)
2. `ConcretePrototype1.h`
3. `ConcretePrototype2.h`
4. `main.cpp` (client)

---

## 🧱 Source Code

### 🔹 `Prototype.h`

```cpp
#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>

// Abstract base class for all prototypes
class Prototype {
public:
    virtual ~Prototype() {
        std::cout << "Prototype destructor called." << std::endl;
    }

    // Enforces deep copying behavior for subclasses
    virtual Prototype* clone() const = 0;

    // Optional: lets us inspect the state of the object
    virtual void print() const = 0;
};

#endif
```

**Why**:
Defines the interface for cloning objects. The `clone()` method is pure virtual and must be implemented by all concrete subclasses.

---

### 🔹 `ConcretePrototype1.h`

```cpp
#ifndef CONCRETEPROTOTYPE1_H
#define CONCRETEPROTOTYPE1_H

#include "Prototype.h"
#include <iostream>
#include <string>

// Concrete implementation of a prototype using std::string
class ConcretePrototype1 : public Prototype {
private:
    std::string state;

public:
    ConcretePrototype1(const std::string& initState) : state(initState) {}

    ConcretePrototype1(const ConcretePrototype1& other) : state(other.state) {}

    Prototype* clone() const override {
        return new ConcretePrototype1(*this);
    }

    void setState(const std::string& newState) {
        state = newState;
    }

    void print() const override {
        std::cout << "ConcretePrototype1 state: " << state << std::endl;
    }

    ~ConcretePrototype1() override {
        std::cout << "ConcretePrototype1 destructor called." << std::endl;
    }
};

#endif
```

**Why**:
This class shows how to implement deep cloning via the copy constructor and supports internal state modification.

---

### 🔹 `ConcretePrototype2.h`

```cpp
#ifndef CONCRETEPROTOTYPE2_H
#define CONCRETEPROTOTYPE2_H

#include "Prototype.h"
#include <iostream>

// Another implementation using an integer to show flexibility
class ConcretePrototype2 : public Prototype {
private:
    int number;

public:
    ConcretePrototype2(int initNumber) : number(initNumber) {}

    ConcretePrototype2(const ConcretePrototype2& other) : number(other.number) {}

    Prototype* clone() const override {
        return new ConcretePrototype2(*this);
    }

    void setNumber(int newNumber) {
        number = newNumber;
    }

    void print() const override {
        std::cout << "ConcretePrototype2 number: " << number << std::endl;
    }

    ~ConcretePrototype2() override {
        std::cout << "ConcretePrototype2 destructor called." << std::endl;
    }
};

#endif
```

**Why**:
Demonstrates a second kind of product that can also be cloned. Uses `int` for simplicity and variation.

---

### 🔹 `main.cpp`

```cpp
#include "ConcretePrototype1.h"
#include "ConcretePrototype2.h"

int main() {
    // --- Prototype 1 ---
    Prototype* original1 = new ConcretePrototype1("Initial");
    original1->print();

    Prototype* clone1 = original1->clone();
    static_cast<ConcretePrototype1*>(clone1)->setState("Modified Clone");
    clone1->print();
    original1->print(); // should still be "Initial"

    std::cout << std::endl;

    // --- new ConcretePrototype1 ---
    Prototype* original2 = new ConcretePrototype2(42);
    original2->print();

    Prototype* clone2 = original2->clone();
    static_cast<ConcretePrototype2*>(clone2)->setNumber(99);
    clone2->print();
    original2->print(); // should still be 42

    std::cout << std::endl;

    // Cleanup
    delete original1;
    delete clone1;
    delete original2;
    delete clone2;

    return 0;
}
```

**What this does**:

* Creates original instances of `ConcretePrototype1` and `ConcretePrototype2`
* Clones each one
* Modifies the clone
* Confirms the original remains unchanged
* Deletes everything safely using virtual destructors

---

## 💡 Key Concepts

| Concept             | Purpose                                                                |
| ------------------- | ---------------------------------------------------------------------- |
| `clone()`           | Provides polymorphic copying                                           |
| Virtual destructors | Ensures proper cleanup from base pointer                               |
| Copy constructors   | Required to implement deep copy in concrete prototypes                 |
| `static_cast<>`     | Downcasts safely to access subclass-specific methods like `setState()` |

---

## ✅ Expected Output

```
ConcretePrototype1 state: Initial
ConcretePrototype1 state: Modified Clone
ConcretePrototype1 state: Initial

ConcretePrototype2 number: 42
ConcretePrototype2 number: 99
ConcretePrototype2 number: 42

ConcretePrototype1  called.
ConcretePrototype1 destructor called.
ConcretePrototype2 destructor called.
ConcretePrototype2 destructor called.
Prototype destructor called.
Prototype destructor called.
Prototype destructor called.
Prototype destructor called.
```

> This confirms proper cloning and object independence.

---

## 🧼 Memory Safety

All objects are cleaned up properly. Virtual destructors guarantee no memory leaks or partial deletes. There is no SIGSEGV (segmentation fault).

---

## 🧪 Demo Behavior

> ✔ Modifying a clone **does not** affect the original
> ✔ Clone is created via **deep copy**
> ✔ Clean separation of interface and implementation
> ✔ Safe use of polymorphism

---

