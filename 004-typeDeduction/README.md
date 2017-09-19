# 0x0004 - Type Deduction and Definition

Both `auto` and `decltype` are of C++11 features. 

## Automatic Variable Type - `auto` (C++11)

Given a function, e.g.:
```cpp
int foo(int x, int y){
    return x + 3*y;
}
```

**Before** the C++11 standards, when we assign the result of the function to a variable, we would need to know the *type* of this function:
```cpp
int a = foo(1,2);
float b = foo(1,2);
```
and if we assign to a type to which the result is not convertible, the compiler would complain that the types are incompatible. This shows that the compiler knows the type, and **after** C++11, this knowledge is shared with the programmer.

Using the type info:
```cpp
auto c = foo(1,2);
``` 

**Note:** the `auto` type is not a dynamic type (e.g. like in Python), and cannot be re-defined at every new assignment. The type itself is determined only once:
```python
# python code
a = 1
a = 'string'
```

```cpp
// cpp code
int a = 1;
a = "string"; // Error: invalid convertion
```

It is possible to declare multiple `auto` variables in the same statement as long as they are all initialized with an expression of the same type: 
```cpp
auto i = 2.0, j = 3.4; // OK: both are double
auto i = 2, j = 3.4;   // Error: i is int, j is double
auto i = 2, j;         // Error: j is not initialized
auto x = foo(1,2);
```

We can qualify `auto` with `const` and refenence attributes:
```cpp
auto& ri = i;        // reference on i
const auto& cri = i; // const reference on i
```

**To conclude:** in the provided examples the use of `auto` keyword is a convinience that saves unnecessary thinking and typing, and it makes the code to look neater. 

## Type of an Expression - `decltype` (C++11)

`decltype` is like a function that returns the type of an expression. E.g., the function `const int& bar();` return value `const int&` could also be expressed with `decltype`:
```cpp
decltype(bar()) a = bar();
// same type as
const auto& b = bar();
// is equivalent
const int& c = bar();

const std::vector<int> v{1,2,3};
auto x = v[0];        // int
decltype(v[0]) y = 1; // const int&, the return type of std::vector<int>::operator[]
```

The two features `auto` and `decltype` differ in their application, and the type deduction mechanism is different. Simply speaking, `auto` follows the rules of function template parameters and often drops reference and `const` qualifiers, meanwhile `decltype` takes the expression type as it is.

The `decltype` becomes really useful in generic programming when used **with templates**:
```cpp
// using auto as return type of function - use trailing return type (another C++11 feature)
auto bar() -> const int&; 

// when using templates, cannot use auto to define the return type, so use decltype
template <typename F, typename V>
auto execute(F func, const V& value) -> decltype(func(value));
auto a = execute(func1, "string");
auto b = execute(func2, 3.14);
```

## `decltype(auto)` (C++14)

With `decltype(auto)` we can declare `auto` variables that have the same type as with `decltype`:
```cpp
decltype(bar()) a = bar();
// identical to
decltype(auto) b = bar();
```

When using template functions:
```cpp
template<typename F, typename V>
decltype(auto) execute(F func, const V& value);
```
