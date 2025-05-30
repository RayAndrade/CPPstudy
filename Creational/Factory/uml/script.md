##UML##

*Product* defines the interface of objects the factory method creates.

*Concrete Product* Implements the *Product* interface.

*Creator* delclares the factory method which returns a object of type Product.
May also define a default implementation of the factory method that returns a default Concreate Product object.

*Concrete Creator* overrides the factory method to return a instance of a Concrete Product

*Collaboration*
Createor relies on its subclass to define the facory method so it returns an instance of the appropraite Concrete Product
