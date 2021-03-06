(*

category:        Test
synopsis:        A reaction with a local parameter named 'avogadro'.
componentTags:   Compartment, Reaction, Species
testTags:        Amount, LocalParameters
testType:        TimeCourse
levels:          1.2, 2.1, 2.2, 2.3, 2.4, 2.5, 3.1, 3.2
generatedBy:     Analytic
packagesPresent: 

 In this model, a local parameter is given the id 'avogadro', which the kinetic law references.

The model contains:
* 1 species (S1)
* 1 local parameter (J0.avogadro)
* 1 compartment (C)

There is one reaction:

[{width:30em,margin: 1em auto}|  *Reaction*  |  *Rate*  |
| J0: -> S1 | $avogadro$ |]

The initial conditions are as follows:

[{width:35em,margin: 1em auto}|       | *Value* | *Constant* |
| Initial concentration of species S1 | $1$ | variable |
| Initial value of local parameter 'J0.avogadro' | $0.1$ | constant |
| Initial volume of compartment 'C' | $1$ | constant |]

Note: The test data for this model was generated from an analytical
solution of the system of equations.

*)
