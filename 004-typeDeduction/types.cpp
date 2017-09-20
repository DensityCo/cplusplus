#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <memory>
#include <experimental/string_view>

// type_name() is taken from https://stackoverflow.com/a/20170989/4118460
// C++17 version:
template <class T>
constexpr std::experimental::string_view type_name()
{
    using namespace std::experimental;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
    return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
    return string_view(p.data() + 46, p.size() - 46 - 1);
#  endif
#elif defined(_MSC_VER)
    string_view p = __FUNCSIG__;
    return string_view(p.data() + 38, p.size() - 38 - 7);
#endif
}
// C++11 version:
//template <class T>
//std::string type_name()
//{
//    typedef typename std::remove_reference<T>::type TR;
//    std::unique_ptr<char, void(*)(void*)> own(nullptr, std::free);
//    std::string r = own != nullptr ? own.get() : typeid(TR).name();
//    if (std::is_const<TR>::value)
//        r += " const";
//    if (std::is_volatile<TR>::value)
//        r += " volatile";
//    if (std::is_lvalue_reference<T>::value)
//        r += "&";
//    else if (std::is_rvalue_reference<T>::value)
//        r += "&&";
//    return r;
//}

int foo(int x, int y)
{
    return x + 3*y;
}

void test_auto_assignment()
{
    std::cout << "\n==test auto assignment==\n";

    int a = foo(1,2);
    std::cout << "type(a)=" << type_name<decltype(a)>() << std::endl;
    
    auto c = foo(1,2);
    std::cout << "type(c)=" << type_name<decltype(c)>() << std::endl;
}

void test_auto_iterators()
{
    std::cout << "\n==test auto iterators==\n";

    std::vector<int> v{1,2,3,4,5};

//    for (const auto& e : v){
    for (const int& e : v){
        std::cout << e << " ";
    }
    std::cout << std::endl;

//    for (auto it = v.begin(); it != v.end(); ++it){
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it){
        auto item = *it;
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int global = 5;
// auto bar() -> int& // C++11
int& bar()
{
    return global;
}


void test_decltype_vs_auto()
{
    std::cout << "\n==test decltype vs auto==\n";
    decltype(bar()) a = bar(); // int& a = bar();
//    decltype(auto) a_ = bar(); // C++14 same as above
    auto b = bar();            // int b = bar();
    auto& c = bar();           // int& c = bar();
    std::cout << "type(a)= " << type_name<decltype(a)>() << std::endl;
    std::cout << "type(b)= " << type_name<decltype(b)>() << std::endl;
    std::cout << "type(c)= " << type_name<decltype(c)>() << std::endl;

    std::cout << "--Assigned a, b, c\n";
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "c=" << c << std::endl;
    std::cout << "global=" << global << std::endl;

    std::cout << "--Changed a\n";
    a++;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "c=" << c << std::endl;
    std::cout << "global=" << global << std::endl;

    std::cout << "--Changed b\n";
    b=100;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "c=" << c << std::endl;
    std::cout << "global=" << global << std::endl;
}

std::string getName(int x)
{
    if (x == 0)
        return "zero";
    else if (x == 1)
        return "one";
    else
        return "something else";
}

int getLengthOne(const std::string& s)
{
    return s.length() + 1;
}

template <typename F, typename V>
//decltype(auto) execute(F func, const V& value) // C++14
//auto execute(F func, const V& value) -> decltype(auto) // C++14
auto execute(F func, const V& value) -> decltype(func(value)) // C++11
{
    return func(value);
}

void test_decltype_template()
{
    std::cout << "\n==test decltype template==\n";
    std::cout << "getLengthOne('helloworld')="<< execute(getLengthOne, "helloworld") << std::endl;
    std::cout << "getName(0)=" << execute(getName, 0) << std::endl;
    std::cout << "getLengthOne(getName(3))=" << execute(getLengthOne, execute(getName, 3)) << std::endl;
}

int main(int argc, char** argv)
{
    std::cout << "Type deduction and definition examples" << std::endl;
    test_auto_assignment();
    test_auto_iterators();
    test_decltype_vs_auto();
    test_decltype_template();

    return 0;
}
