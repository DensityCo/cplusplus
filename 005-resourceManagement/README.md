# Resource Management In C++14
Goal is to demonstrate how resources are managed in C++14.

# Discussion Points
* Demonstrate the problem we are trying to solve.
* How do python and java solve this problem.
    * Note that resource management issues exist in all languages.
* Scope
* Deterministic resource management
* Pass-by-value vs. pass-by-reference
* Memory is NOT the only resource that needs to be managed.
    * Mutexes
    * OS resources
    * Database connections
* Compare with Python "with" statement
* Why no finally is necessary
* Order of deletion

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
