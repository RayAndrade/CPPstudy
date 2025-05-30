Participants

**Handler** 

defines an interface for handling request

implememts the successor link (optional)

**ConcreteHandler**

handles requests it is resonsible for

can access its successor

if the ConcreteHandler can handle the reuest, it does so, otherwise it forwards the request to it successor.

**Client** 

initiates the request to a ConcreteHandler object on the chain

==============

**Collaborations**

When a client issues a request, the request propagates along the chain until a ConcreteHandler object takes respomsibility for handling it.

