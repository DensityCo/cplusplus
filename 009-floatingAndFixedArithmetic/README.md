## 009-floatingAndFixedArithmetic

### Integers
A finite block of linear data and its size or width is platform dependent.  These number representations have some minimum and maximum possible values and depending on the processor, the size of the integer may vary.  Are there limitations with how most systems store integer data types in memory.  Such as with Booleans, although a single bit represents one of two values, usually a full byte is given for convenience and speed of access.  Why is this important?  There might become a possible non-portability issue if the implementation assumes that all computers, on which software will run, have the same word size - an integer data type.  For example, 
        `int variable // will fail on systems with 16b integers`
        `long variable // instead declare a long having at least 32b`
        
 Programmers may also incorrectly assume that a pointer can be converted to an integer without loss of information, which may work on (some) 32b computers, but fail on 64b computers with 64b pointers and 32-bit integers.

### Floating points
