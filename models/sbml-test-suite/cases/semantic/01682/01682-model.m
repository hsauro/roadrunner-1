(*

category:        Test
synopsis:        A species conversion factor for simultaneous events.
componentTags:   CSymbolTime, Compartment, EventNoDelay, EventPriority, Parameter, Reaction, Species
testTags:        Amount, ConversionFactors
testType:        TimeCourse
levels:          3.1, 3.2
generatedBy:     Analytic
packagesPresent: 

 In this model, a species conversion factor is set for species reset partway through the simulation by two simultaneous events, whose priorities involve the species.

The model contains:
* 2 species (S1, S2)
* 1 parameter (s1_cf)
* 1 compartment (C)

There is one reaction:

[{width:30em,margin: 1em auto}|  *Reaction*  |  *Rate*  |
| J0: S1 -> S2 | $0.01$ |]

The conversion factor for the species 'S1' is 's1_cf'


There are 2 events:

[{width:35em,margin: 1em auto}|  *Event*  |  *Trigger*  |  *Priority*  | *Event Assignments* |
| E0 | $time > 3.5$ | $S1$ | $S2 = 3$ |
|  |  |  | $S1 = 1$ |
| E1 | $time > 3.5$ | $1.82$ | $S2 = 4$ |
|  |  |  | $S1 = 4$ |]

The initial conditions are as follows:

[{width:35em,margin: 1em auto}|       | *Value* | *Constant* |
| Initial amount of species S1 | $2$ | variable |
| Initial amount of species S2 | $3$ | variable |
| Initial value of parameter s1_cf | $5$ | constant |
| Initial volume of compartment 'C' | $1$ | constant |]

The species' initial quantities are given in terms of substance units to
make it easier to use the model in a discrete stochastic simulator, but
their symbols represent their values in concentration units where they
appear in expressions.

Note: The test data for this model was generated from an analytical
solution of the system of equations.

*)
