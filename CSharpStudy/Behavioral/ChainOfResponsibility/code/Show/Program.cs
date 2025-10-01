// See https://aka.ms/new-console-template for more information

using Show;

Address address = new Address("123 Fake St", "Springfield");
Person person1 = new Person("Homer", address);

Person shallowCopy = person1.ShallowCopy();
Person deepCopy = person1.DeepCopy();

// Change the address
person1.Address.Street = "321 Real St";

System.Console.WriteLine($"Original Address: {person1.Address.Street}");
System.Console.WriteLine($"Shallow Copy Address: {shallowCopy.Address.Street}");
System.Console.WriteLine($"Deep Copy Address: {deepCopy.Address.Street}");
