# Resource Management In C++14
Goal is to demonstrate how resources are managed in C++14.

# Discussion Points
* C++ requires manual resource management
    * Why don't I need to de-allocate a string?
* Demonstrate the problem we are trying to solve.
* How do python and java solve this problem.
    * Note that resource management issues exist in all languages.
* Scope
    * namespace
    * object
    * local
* C++ provides pointer, object and reference, constructors, destructors.
* stl provides smart pointers.
* Deterministic resource management
    * Resource management is a "class invariant"
* Pass-by-value vs. pass-by-reference
    * Copy and move constructors
* Memory is NOT the only resource that needs to be managed.
    * Mutexes
    * OS resources
    * Database connections
* Compare with Python "with" statement
* Why finally is not necessary
* Order of deletion
* Rule of 3/5.
    * https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)

## References vs. Smart Pointers vs. Raw Pointers
* Discuss Object Ownership
* When to uses references
* When to use smart pointers
  * Different types of smart pointers
    * unique_ptr <most widely used> . Good example of decltype here.
    * shared_ptr. Shared ownership, sometimes useful.  Supports <void> type which is very useful.
    * weak_ptr. reference a shared_ptr without participating in ownership.
  * Raw pointer
    * Still necessary when you need to reference an object that you don't own and the reference may change.
