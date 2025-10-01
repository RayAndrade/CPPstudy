namespace TheRayCode;

class Program
{
    static void Main(string[] args)
    {
        IAbstractFactory factory1 = new ConcreteFactory1();
        IAbstractProductA productA1 = factory1.CreateProductA();
        IAbstractProductB productB1 = factory1.CreateProductB();
        
        productA1.Use();
        productB1.Use(); 
        
        IAbstractFactory factory2 = new ConcreteFactory2();
        IAbstractProductA productA2 = factory2.CreateProductA();
        IAbstractProductB productB2 = factory2.CreateProductB();
        
        productA2.Use(); 
        productB2.Use(); 
  
    }
}