## Pattern: Prototype

### Participant: Prototype

1. Declares a pure virtual `Clone()` method that returns a pointer to a copied object.
2. Provides a common interface so all derived classes can be cloned polymorphically.
3. Enables object creation without specifying the exact concrete class.
4. Acts as a base class ensuring consistent cloning behavior across all prototypes.

---

### Participant: ConcretePrototype

1. Implements the `Clone()` method to return a copy of itself using its copy constructor or custom logic.
2. Ensures the correct concrete type is preserved when cloning (no slicing).
3. Handles deep or shallow copying depending on internal resource ownership (e.g., pointers).
4. Encapsulates the details of object duplication, including memory allocation.

---

### Participant: Client

1. Creates new objects by calling `Clone()` on a prototype instance.
2. Interacts only with the `Prototype` interface, not concrete classes.
3. Avoids direct instantiation using `new ConcreteClass`, reducing coupling.
4. Relies on polymorphism to generate objects dynamically at runtime.

---

## Student Summary

* **Prototype** → Defines a virtual `Clone()` so objects can copy themselves.
* **ConcretePrototype** → Implements how the copy is actually made (safe and correct).
* **Client** → Uses cloning instead of constructors to create new objects.

