Below is a **C#** implementation of the **Abstract Factory** design pattern, a **Creational** pattern, following the **Gang of Four (GoF)** structure. Each class is placed in its own file and created in an order that avoids dependency issues.

---

## **Class Creation Order**
To avoid dependency issues, create the classes in this order:

1. **AbstractProductA & AbstractProductB (Abstract Products)**
2. **ConcreteProductA1, ConcreteProductA2, ConcreteProductB1, ConcreteProductB2 (Concrete Products)**
3. **AbstractFactory (Factory Interface)**
4. **ConcreteFactory1 & ConcreteFactory2 (Factory Implementations)**
5. **Client Code (Program.cs)**

---

## **1. Abstract Products (`IAbstractProductA.cs` & `IAbstractProductB.cs`)**

### **`IAbstractProductA.cs`**
```csharp
namespace AbstractFactoryPattern
{
    // Abstract Product A
    public interface IAbstractProductA
    {
        void Use();
    }
}
```

### **`IAbstractProductB.cs`**
```csharp
namespace AbstractFactoryPattern
{
    // Abstract Product B
    public interface IAbstractProductB
    {
        void Use();
    }
}
```

### **Explanation**
- `IAbstractProductA` and `IAbstractProductB` define the interfaces for two types of products.
- Each product type has a `Use()` method, which will be implemented by concrete products.

---

## **2. Concrete Products (`ConcreteProductA1.cs`, `ConcreteProductA2.cs`, etc.)**

### **`ConcreteProductA1.cs`**
```csharp
using System;

namespace AbstractFactoryPattern
{
    // Concrete Product A1
    public class ConcreteProductA1 : IAbstractProductA
    {
        public void Use()
        {
            Console.WriteLine("Using ConcreteProductA1");
        }
    }
}
```

### **`ConcreteProductA2.cs`**
```csharp
using System;

namespace AbstractFactoryPattern
{
    // Concrete Product A2
    public class ConcreteProductA2 : IAbstractProductA
    {
        public void Use()
        {
            Console.WriteLine("Using ConcreteProductA2");
        }
    }
}
```

### **`ConcreteProductB1.cs`**
```csharp
using System;

namespace AbstractFactoryPattern
{
    // Concrete Product B1
    public class ConcreteProductB1 : IAbstractProductB
    {
        public void Use()
        {
            Console.WriteLine("Using ConcreteProductB1");
        }
    }
}
```

### **`ConcreteProductB2.cs`**
```csharp
using System;

namespace AbstractFactoryPattern
{
    // Concrete Product B2
    public class ConcreteProductB2 : IAbstractProductB
    {
        public void Use()
        {
            Console.WriteLine("Using ConcreteProductB2");
        }
    }
}
```

### **Explanation**
- `ConcreteProductA1`, `ConcreteProductA2` implement `IAbstractProductA`.
- `ConcreteProductB1`, `ConcreteProductB2` implement `IAbstractProductB`.
- These represent different product variations.

---

## **3. Abstract Factory (`IAbstractFactory.cs`)**
```csharp
namespace AbstractFactoryPattern
{
    // Abstract Factory Interface
    public interface IAbstractFactory
    {
        IAbstractProductA CreateProductA();
        IAbstractProductB CreateProductB();
    }
}
```

### **Explanation**
- Defines `CreateProductA()` and `CreateProductB()`, which will be implemented by concrete factories.

---

## **4. Concrete Factories (`ConcreteFactory1.cs` & `ConcreteFactory2.cs`)**

### **`ConcreteFactory1.cs`**
```csharp
namespace AbstractFactoryPattern
{
    // Concrete Factory 1
    public class ConcreteFactory1 : IAbstractFactory
    {
        public IAbstractProductA CreateProductA()
        {
            return new ConcreteProductA1();
        }

        public IAbstractProductB CreateProductB()
        {
            return new ConcreteProductB1();
        }
    }
}
```

### **`ConcreteFactory2.cs`**
```csharp
namespace AbstractFactoryPattern
{
    // Concrete Factory 2
    public class ConcreteFactory2 : IAbstractFactory
    {
        public IAbstractProductA CreateProductA()
        {
            return new ConcreteProductA2();
        }

        public IAbstractProductB CreateProductB()
        {
            return new ConcreteProductB2();
        }
    }
}
```

### **Explanation**
- `ConcreteFactory1` creates `ConcreteProductA1` and `ConcreteProductB1`.
- `ConcreteFactory2` creates `ConcreteProductA2` and `ConcreteProductB2`.

---

## **5. Client Code (`Program.cs`)**
```csharp
using System;

namespace AbstractFactoryPattern
{
    class Program
    {
        static void Main(string[] args)
        {
            // Create a factory of type 1
            IAbstractFactory factory1 = new ConcreteFactory1();
            IAbstractProductA productA1 = factory1.CreateProductA();
            IAbstractProductB productB1 = factory1.CreateProductB();
            
            productA1.Use(); // Output: Using ConcreteProductA1
            productB1.Use(); // Output: Using ConcreteProductB1

            // Create a factory of type 2
            IAbstractFactory factory2 = new ConcreteFactory2();
            IAbstractProductA productA2 = factory2.CreateProductA();
            IAbstractProductB productB2 = factory2.CreateProductB();
            
            productA2.Use(); // Output: Using ConcreteProductA2
            productB2.Use(); // Output: Using ConcreteProductB2
        }
    }
}
```

---

## **Final Explanation**
1. **Abstract Products (`IAbstractProductA`, `IAbstractProductB`)**
   - Define interfaces for different types of products.

2. **Concrete Products (`ConcreteProductA1`, `ConcreteProductA2`, etc.)**
   - Implement the abstract product interfaces.

3. **Abstract Factory (`IAbstractFactory`)**
   - Declares factory methods for creating products.

4. **Concrete Factories (`ConcreteFactory1`, `ConcreteFactory2`)**
   - Implement factory methods to produce different products.

5. **Client Code (`Program.cs`)**
   - Uses the abstract factory to create product families.

---

## **Key Takeaways**
✅ **Encapsulation**: The client is independent of concrete product classes.  
✅ **Scalability**: Easily add new product families without modifying existing code.  
✅ **Consistency**: Ensures related products are created together.  

Would you like to extend this with **Singleton Factories** or **Dynamic Factory Selection**? 🚀
