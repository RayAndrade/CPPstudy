# 🌟 Builder — Participants (for C*++ Students)

## **Builder**

* Defines the steps for creating a complex object.
* Provides method names that ConcreteBuilder must implement.
* Does not assemble or store the final object.

## **ConcreteBuilder**

* Implements all building steps defined in Builder.
* Actually creates and assembles the product’s parts.
* Returns the finished Product at the end.

## **Director**

* Controls the order of building steps.
* Uses a Builder to construct the Product.
* Ensures constructions follow a consistent sequence.

## **Product**

* The final complex object being built.
* Contains many parts assembled by ConcreteBuilder.
* Returned to the Client after construction.

