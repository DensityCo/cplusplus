# Generic programming: templates

Templates: feature of C++ to create functions and classes to operate on parameteric (generic) types.

Result: such function or class can work with many different types of data without being manually rewritten for each type. 

## Function templates

A *function template*, aka *generic function*: a blueprint to generate a potentially infinite number of function overloads.

* Simple function, e.g., `max()`.
* Instantiation.
* Parameter type deduction: value parameters, lvalue-reference parameters.
* Errata.
* Mixing types.
* Automatic return types.

## Class templates

A *template class*, aka *generic class*: the types of data members can be parameterized. 

E.g.: vectors and matrices. 

* Class example: `vector` (as in linear algebra).
* A set of type requirements.

## More to generic programming

* Lambda, variadic templates, functors...
