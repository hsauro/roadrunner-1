(*

category:        Test
synopsis:        An empty reaction's identifier used in an event assignment.
componentTags:   CSymbolTime, EventNoDelay, Parameter, Reaction
testTags:        NonConstantParameter
testType:        TimeCourse
levels:          3.2
generatedBy:     Analytic
packagesPresent: 

 A reaction with no products nor reactants, but which has a kinetic law, has its identifier used in an event assignment.

The model contains:
* 1 parameter (p1)

There is one reaction:

[{width:30em,margin: 1em auto}|  *Reaction*  |  *Rate*  |
| J0: -> | $3$ |]


There is one event:

[{width:30em,margin: 1em auto}|  *Event*  |  *Trigger*  | *Event Assignments* |
| _E0 | $time > 4.5$ | $p1 = J0$ |]

The initial conditions are as follows:

[{width:35em,margin: 1em auto}|       | *Value* | *Constant* |
| Initial value of parameter p1 | $0$ | variable |]

Note: The test data for this model was generated from an analytical
solution of the system of equations.

*)
