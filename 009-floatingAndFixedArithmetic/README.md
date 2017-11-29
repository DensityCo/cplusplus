## 009-floatingAndFixedArithmetic

### Integers
A finite block of linear data and its size or width is platform dependent.  These number representations have some minimum and maximum possible values and depending on the processor, the size of the integer may vary.  Are there limitations with how most systems store integer data types in memory?  Such as with Booleans, although a single bit represents one of two values, usually a full byte is given for convenience and speed of access.  Why is this important?  There might become a possible non-portability issue if the implementation assumes that all computers, on which software will run, have the same word size (an integer data type).  

For example, 
       ` int variable ` // will fail on systems with 16b integers if the variable is attempting to hold values > 2 to the 15th - 1
       ` long variable ` // instead declare a long having at least 32b
        
Programmers may also incorrectly assume that a pointer can be converted to an integer without loss of information, which may work on (some) 32b computers, but fail on 64b computers with 64b pointers and 32-bit integers.  Modern C++ also allows `long long` which is as its name suggests, double the minimum capacity of the `long` type.  However, if a compatibility on older C++ standards is required, this type will not be supported by its compiler; as `long long` did not exist in C++03, for example.

Programmers might encounter **overflow** as well whereby the result of an arithmetic operation is beyond the range that can be represented based on the data type and platform. 

### Floating points
Unlike integers and integer data types, floating point number representations are not uniformly spaced and can hold values that are very small or very large.  If the software application involves intensive mathematical calculations, the speed at which the floating-point operations are executed is a very important characteristic of the computer architecture.  These values are inspired by precision; to what degree should the computer system numerically equate such arithmetic. 

Can think of floating points as a scientific notation.  Following this comparison, the method in which the significand (or number to the left of the decimal) and exponent are stored in a computer is dependent upon how the software was programmed.  The fact that floating-point numbers cannot precisely represent all real numbers, and that floating-point operations cannot precisely represent true arithmetic operations, leads to many surprising situations.  For some numbers, depending on the size allocated for the significand, might have to be rounded if the result requires more digits and in turn these numbers would be essentially lost.

### Fixed points
Uses hardware operations controlled by software design.  The hardware is less costly than floating points and can be used to perform basic integer computations as well.  Furthermore, fixed point number representation is useful if the architecture does not support Floating Point Units (FPUs) or can be utilized for improved performance and accuracy; if system does not have a powerful enough processor to handle the precision of floating point mathematics.

When storing and executing an operation using fixed points, the processor will store a value and then its `scale` location, which multiplies the value or integer by this scale, followed by displaying the result.  However, unlike floating point arithmetic, this scale is the same for all values of the same type and does not change during the entire computation.  And the maximum/minimum value is the capacity at which the displayed integer data type, after multiplying by the scale, can hold.

You can perform the basic arithmetic operations such as addition, subtraction, multiplication, division, etc. as long as no overflow occurs and as long as the numbers have the same fixed point type (e.g. integer data type) and scaling factor.  If the latter is not true, then one of the numbers must be converted to the other.  If rounding is executed, some of the information could be loss as in floating points.

#### What method is best
In general, if needed, fixed point can be implemented in the C++ language and is supported with GCC.  However, floating point representations might be more helpful because of its ability to handle a wider dynamic range and there are no requirements for programmers to define (@compile time) fixed integer values - how many digits to store after the decimal.  However, often, the trade-offs between an algorithm implementation using floating-point software emulation and a fast, albeit less accurate, fixed-point algorithm favor the latter solution.

## Possible to-do benchmarks to measure the effectiveness of floating-point to fixed-point conversions
Discuss...
