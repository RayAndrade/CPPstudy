Below is a **C++** implementation of the **Abstract Factory** design pattern, which is a **Creational** pattern, following the **Gang of Four (GoF)** structure. Each class is placed in its own file and created in an order that avoids dependency issues.

---

## **Class Creation Order**
To avoid dependency errors, create the classes in this order:

1. **AbstractProductA & AbstractProductB (Abstract Products)**
2. **ConcreteProductA1, ConcreteProductA2, ConcreteProductB1, ConcreteProductB2 (Concrete Products)**
3. **AbstractFactory (Factory Interface)**
4. **ConcreteFactory1 & ConcreteFactory2 (Factory Implementations)**
5. **Client Code (main.cpp)**

---

## **1. `AbstractProductA.h` & `AbstractProductB.h` (Abstract Products)**

### **`AbstractProductA.h`**
```cpp
#ifndef ABSTRACTPRODUCTA_H
#define ABSTRACTPRODUCTA_H

// Abstract Product A
class AbstractProductA {
public:
    virtual void use() = 0; // Pure virtual function
    virtual ~AbstractProductA() {} // Virtual destructor
};

#endif // ABSTRACTPRODUCTA_H
```

### **`AbstractProductB.h`**
```cpp
#ifndef ABSTRACTPRODUCTB_H
#define ABSTRACTPRODUCTB_H

// Abstract Product B
class AbstractProductB {
public:
    virtual void use() = 0;
    virtual ~AbstractProductB() {} // Virtual destructor
};

#endif // ABSTRACTPRODUCTB_H
```

### **Explanation**
- `AbstractProductA` and `AbstractProductB` define the interfaces for the two types of products.
- Each abstract product contains a `use()` method, which will be implemented by concrete products.

---

## **2. Concrete Products (`ConcreteProductA1.h` & `ConcreteProductA2.h`, etc.)**

### **`ConcreteProductA1.h`**
```cpp
#ifndef CONCRETEPRODUCTA1_H
#define CONCRETEPRODUCTA1_H

#include "AbstractProductA.h"
#include <iostream>

// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA1" << std::endl;
    }
};

#endif // CONCRETEPRODUCTA1_H
```

### **`ConcreteProductA2.h`**
```cpp
#ifndef CONCRETEPRODUCTA2_H
#define CONCRETEPRODUCTA2_H

#include "AbstractProductA.h"
#include <iostream>

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA2" << std::endl;
    }
};

#endif // CONCRETEPRODUCTA2_H
```

### **`ConcreteProductB1.h`**
```cpp
#ifndef CONCRETEPRODUCTB1_H
#define CONCRETEPRODUCTB1_H

#include "AbstractProductB.h"
#include <iostream>

// Concrete Product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void use() override {
        std::cout << "Using ConcreteProductB1" << std::endl;
    }
};

#endif // CONCRETEPRODUCTB1_H
```

### **`ConcreteProductB2.h`**
```cpp
#ifndef CONCRETEPRODUCTB2_H
#define CONCRETEPRODUCTB2_H

#include "AbstractProductB.h"
#include <iostream>

// Concrete Product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void use() override {
        std::cout << "Using ConcreteProductB2" << std::endl;
    }
};

#endif // CONCRETEPRODUCTB2_H
```

### **Explanation**
- `ConcreteProductA1`, `ConcreteProductA2` implement `AbstractProductA`.
- `ConcreteProductB1`, `ConcreteProductB2` implement `AbstractProductB`.
- These represent different product variations.

---

## **3. `AbstractFactory.h` (Abstract Factory Interface)**

```cpp
#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "AbstractProductA.h"
#include "AbstractProductB.h"

// Abstract Factory Interface
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() {} // Virtual destructor
};

#endif // ABSTRACTFACTORY_H
```

### **Explanation**
- Defines `createProductA()` and `createProductB()`, which will be implemented by concrete factories.

---

## **4. Concrete Factories (`ConcreteFactory1.h` & `ConcreteFactory2.h`)**

### **`ConcreteFactory1.h`**
```cpp
#ifndef CONCRETEFACTORY1_H
#define CONCRETEFACTORY1_H

#include "AbstractFactory.h"
#include "ConcreteProductA1.h"
#include "ConcreteProductB1.h"

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

#endif // CONCRETEFACTORY1_H
```

### **`ConcreteFactory2.h`**
```cpp
#ifndef CONCRETEFACTORY2_H
#define CONCRETEFACTORY2_H

#include "AbstractFactory.h"
#include "ConcreteProductA2.h"
#include "ConcreteProductB2.h"

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

#endif // CONCRETEFACTORY2_H
```

### **Explanation**
- `ConcreteFactory1` creates `ConcreteProductA1` and `ConcreteProductB1`.
- `ConcreteFactory2` creates `ConcreteProductA2` and `ConcreteProductB2`.

---

## **5. `main.cpp` (Client Code)**

```cpp
#include <iostream>
#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"

int main() {
    // Create a factory of type 1
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    
    productA1->use(); // Output: Using ConcreteProductA1
    productB1->use(); // Output: Using ConcreteProductB1

    // Create a factory of type 2
    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();
    
    productA2->use(); // Output: Using ConcreteProductA2
    productB2->use(); // Output: Using ConcreteProductB2

    // Cleanup
    delete productA1;
    delete productB1;
    delete factory1;

    delete productA2;
    delete productB2;
    delete factory2;

    return 0;
}
```

---

## **Final Explanation**
1. **Abstract Products (`AbstractProductA` & `AbstractProductB`)**
   - Define interfaces for different types of products.

2. **Concrete Products (`ConcreteProductA1`, `ConcreteProductA2`, etc.)**
   - Implement the abstract products.

3. **Abstract Factory (`AbstractFactory`)**
   - Declares factory methods for creating products.

4. **Concrete Factories (`ConcreteFactory1`, `ConcreteFactory2`)**
   - Implement factory methods to produce different products.

5. **Client Code (`main.cpp`)**
   - Uses the abstract factory to create product families.

---

## **Key Takeaways**
✅ **Encapsulation**: The client is independent of concrete product classes.  
✅ **Scalability**: Easily add new product families without modifying existing code.  
✅ **Consistency**: Ensures related products are created together.  

Would you like to extend this with **Singleton Factories** or **Dynamic Factory Selection**? 🚀
