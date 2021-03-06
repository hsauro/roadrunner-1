(*

category:        Test
synopsis:        A replaced species reference whose ID is used in an assignment rule.
componentTags:   AssignmentRule, Compartment, Parameter, Reaction, Species, comp:ModelDefinition, comp:ReplacedElement, comp:Submodel
testTags:        Amount, InitialValueReassigned, NonUnityStoichiometry, SpeciesReferenceInMath, comp:SubmodelOutput
testType:        TimeCourse
levels:          3.1, 3.2
generatedBy:     Analytic
packagesPresent: comp

 In this model, a replaced submodel species reference (itself in a replaced reaction) is used in an assignment rule.

The 'flattened' version of this hierarchical model contains:
* 1 species (S1)
* 1 parameter (A__x)
* 1 compartment (C)
* 1 species reference (J1_sr)

There is one reaction:

[{width:30em,margin: 1em auto}|  *Reaction*  |  *Rate*  |
| J1: -> 5S1 | $1$ |]


There is one rule:

[{width:30em,margin: 1em auto}|  *Type*  |  *Variable*  |  *Formula*  |
| Assignment | A__x | $J1_sr$ |]

The initial conditions are as follows:

[{width:35em,margin: 1em auto}|       | *Value* | *Constant* |
| Initial concentration of species S1 | $3$ | variable |
| Initial value of parameter A__x | $J1_sr$ | variable |
| Initial volume of compartment 'C' | $1$ | constant |]

Note: The test data for this model was generated from an analytical
solution of the system of equations.

*)
