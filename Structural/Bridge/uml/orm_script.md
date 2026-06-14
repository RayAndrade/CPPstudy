## UML for the Pattern: Structural Bridge for the C++ Student

---

### Participant: Abstraction

1. Defines the high-level interface that the client uses.
2. Holds a pointer or reference to an `Implementor` 
3. Delegates actual work to the `Implementor` object instead of doing it directly.
4. In C++, often implemented as a base class with virtual functions.

---

### Participant: RefinedAbstraction

1. Extends `Abstraction` with more specific behavior.
2. Uses the inherited `Implementor` pointer to perform operations.
3. Adds or overrides functionality without changing the implementation layer.
4. In C++, typically overrides virtual functions from `Abstraction`.

---

### Participant: Implementor

1. Defines the interface for implementation classes.
2. Provides low-level operations that `Abstraction` relies on.
3. Does not need to match the `Abstraction` interface exactly.
4. In C++, usually an abstract base class with pure virtual functions.

---

### Participant: ConcreteImplementorA

1. Implements the `Implementor` interface with specific behavior.
2. Provides concrete definitions for all required operations.
3. Can vary independently from other implementors.
4. In C++, overrides all pure virtual functions from `Implementor`.

---

### Participant: ConcreteImplementorB

1. Provides an alternative implementation of the `Implementor` interface.
2. Implements the same operations differently than `ConcreteImplementorA`.
3. Allows switching implementations at runtime via pointers.
4. In C++, used interchangeably through base-class (`Implementor*`) pointers.

---

### Participant: Client

1. Interacts only with the `Abstraction` interface.
2. Does not directly depend on concrete implementation classes.
3. Supplies or selects a `ConcreteImplementor` to be used.
4. In C++, typically creates objects and passes `Implementor*` to `Abstraction`.

---

## Student Summary

* **Abstraction**: The main interface your program uses; holds a pointer to the implementation.
* **RefinedAbstraction**: A specialized version of the abstraction with added behavior.
* **Implementor**: The interface for low-level work; defines what implementations must do.
* **ConcreteImplementorA**: One specific way to implement the low-level operations.
* **ConcreteImplementorB**: Another interchangeable implementation with different behavior.
* **Client**: The user of the abstraction; wires everything together using pointers.



































