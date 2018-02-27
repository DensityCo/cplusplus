#include <iostream>
#include <memory>
#include <complex>

//int max(int a, int b)
//{
//    std::cout << "integer type\n";
//    if (a>b)
//        return a;
//    else
//        return b;
//}
//
//double max(double a, double b)
//{
//    std::cout << "double type\n";
//    if (a>b)
//        return a;
//    else
//        return b;
//}

template <typename T>
auto max(T a, T b) // auto - since c++14
{
    // function template replaces the non-tempate overloads and
    // we keep the name "max"
    std::cout << "custom type\n";
    if (a>b)
        return a;
    else
        return b;
}

template <typename T> 
bool isPairPositive(T a) {
//    if a>=0 return true; // parsing errors will be detected
//    else return false; 
    return a.first>=0? true : false;
}

template <typename TInput>
void foo(TInput arg){}

template <typename TInput>
void bar(const TInput& arg) {}

template <typename TInput>
void fun(TInput& arg) {arg++; }

template <typename T = int>
class vector
{
    public:
        explicit vector(int size)
            : m_size(size), m_data(std::make_unique<T []>(m_size)) // new T[m_size]
        {}

        vector(const vector& copy)
            : m_size(copy.m_size), m_data(std::make_unique<T []>(m_size))
        {
            std::copy(&copy.m_data[0], copy.m_data[copy.m_size], &m_data[0]);
        }

        int getSize() const {return m_size; }

        const T& operator[](int index) const 
        {
            // check index code
            return m_data[index];
        }

        // linear algebra fun
        // ...

    private:
        int m_size;
        std::unique_ptr<T[]> m_data;
};

template <typename T, typename U=T>
class pair
{};

int main()
{
    std::cout << "Templates: functions and classes.\n";

    // overloading funcs:
    // same declaration with the same name within one scope
    // but different args and diff implementations
    //
    // Overload resolution: the compiler determines the most appropriate definition to use, 
    // by comparing the argument types you have used to call the function or operator with 
    // the parameter types specified in the definitions.
    std::cout << "Template function test\n";
    std::cout << "max(3,5)=" << max(3,5) << std::endl;
    std::cout << "max(3.0, 4.5)=" << max(3.0, 4.5) << std::endl;
    std::cout << "max(3l, 5l)=" << max(3l, 5l) << std::endl;
    std::cout << "max-uint(3, 5)=" << max((unsigned int)3, (unsigned int)5) << std::endl;
    // ^ 3l and 5l are literals of type long, so the function is *Instantiated* to
    // long max(long, long);
    // likewise we have:
    // int max(int, int);
    // double max(double, double);
    // unsigned int max(unsigned int, unsigned int);
    //
    // Errata: what happens when the provided template type does not provide operator> ?
    std::complex<float> z(3, 2), c(4, 8);
//    std::cout << "max-complex(c,z)=" << ::max(c, z) << std::endl; // error: no match for operator>
    
    // Instantiation.
    // When compiler processes a generic funtion's definition, it can only detect errors that are
    // independent of the template parameters like parsing errors. 
    isPairPositive(std::make_pair<int, char>(3, 'a'));
    // we can't call isPairPositive with any intrinsic type like int or double, but the template function
    // might not be intended for intrinsic types and may with with elements of argument types.
    //
    // Compilation of function template: does not generate any code in the binary. This inly happens when
    // we call it. In this case, we instantiate this function template. Only then the compiler performs
    // a complete check of whether the genericfunction is correct for the given argument type(s).
    // Example: max() can be instantiated with int or double
    // isPairPosotive() cab be instantiated with std::pair<T1, T2>

    // From above examples: the template parameter is deduced from the arguments. 
    // To be more explicit, we can declare the type that substitutes the template parameters:
    std::cout << "max-uint(3, 5)=" << max<unsigned int>(3, 5) << std::endl;
    // implicit instatiation works in most cases as expected. The explicit nomintation
    // is mostly needed for disambiguation and special usages (e.g. std::forward).


    // Parameter type deduction: how template params are substituted when
    // arguments are passed by value, rvalue or lvalue?
    // Value parameters. Example: foo();
    int i =         0;
    int& j =        i;
    const int& k =  i;
    foo(0);
    foo(i);
    foo(j);
    foo(k);
    // in 4 cases TInput is substituted with int, so the type of arg is int as well.
    // if TInput is substituted with 'int&' or 'const int&', the arg would be passed as well, but 
    // the value of semantics would be lost (e.g.: modification of arg would modify j).
    // Thus, TInput loses all qualifiers. 
    // Note: the function accepts arguments as long as their types are copyable. 
    std::unique_ptr<int> myPtr;
//    foo(myPtr); // can only be passed as rvalue, no copy ctor!
    foo(std::move(myPtr)); // OK, use move ctor (C++11)
    // note: move ctor - move resources from one object to another instead of copying. 
    // Cast from lvalue to rvalue reference.
    // = static_cast<T&&>(t);
    //
    // LValue reference parameters. Example: bar();
    // TInput is again the argument type with all qualifiers stripped off.
    // Thus, arg is a const reference of the unqualified arguments type so we cannot modify arg.
    bar(0); // valid as exception for programmer's convinience
    bar(i);
    bar(j);
    bar(k);
    bar(myPtr);
    // Mutable reference: fun();
//    fun(0); // error, temporaries are not referable
    fun(i);
    fun(j);
//    fun(k); // if fun() modifies arg, the instantiation will fail 
    // Temporaries are refused because there exist no type for TInput such that TInput& becomes int&&.
    // const int& can be matched with TInput&, the TInput is substituted with const int. Therefore,
    // TInput& = const int&.
    // Thus, the argumnent pattern TInput& does not limit arguments to mutable references, unless arg is
    // modified.

    // Mixing types
    // try to use two different types of args for max():
    int ii=2;
    unsigned int ui=3;
//    std::cout << "max-uint-int(2,3)=" << ::max(ii, ui) << std::endl;
    std::cout << "max-uint-int(2,3)=" << ::max<unsigned int>(ui, ii) << std::endl;
    // when no exact match found - template arguments are not implicitely converted as it would happen
    // with the non-template arguments. 
    //
    // Performance.
    // Template functions perform as efficiently as their non-template counterparts. 
    // C++ generates new code for every type/type combination that the function is called with. 
    // May have longer executables because of the multiple instantiations for each type (combo).


    // Class templates.
    // The types of data memebers can be parameterized. 
    // Example: class vector
    // Template class is similar to non-template class. There is one extra parameter T for the elements type.
    // Member variables like m_size and corresponding functions getSize are not affected by that T parameter.
    // Other funcs like copy ctor and bracket operator are parameterized.
    // The member variable data is parameterized by T.
    // Template parameters can be defaulted. 
    ::vector<float> myVec(4);
    ::vector<> myVec2(4); // uses default template - int

//    ::pair<int, float> pair1;
//    ::pair<int> pair2; // template <typename T, typename U=T>

    return 0;
}
