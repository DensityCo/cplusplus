#include <iostream>
#include <memory>
#include <vector>

/*
 * C++ has strong scoping rules: http://en.cppreference.com/w/cpp/language/scope
 *
 * For these examples, the below scopes are sufficient:
 * 1. namespace
 * 2. object
 * 3. block
 */

//Take input from fifo
//Write to log
//calculate primes

namespace
{
    struct RAIIExampleStruct
    {
        int val;

        RAIIExampleStruct(int val)
            : val(val)
        {

        }

        ~RAIIExampleStruct()
        {
            std::cerr << "My Destructor: " << val << std::endl;
        }
    };

    struct OuterObject
    {
        //Object Scope
        RAIIExampleStruct inner;

        OuterObject(int val)
            : inner(val) //initialization list.
        {}
    };
}

namespace
{

    //Namespace scope
    std::unique_ptr<RAIIExampleStruct> ns_scoped;
}

void copy_argument_example(RAIIExampleStruct copied_arg)
{
    (void)copied_arg;
}

void reference_argument_example(RAIIExampleStruct& ref_arg)
{
    (void)ref_arg;
}

void unique_ptr_argument_example(std::unique_ptr<RAIIExampleStruct> up_arg)
{
    (void)up_arg;
}

int main(int argc, char** argv)
{
    //function scope
    std::unique_ptr<RAIIExampleStruct> function_scoped(new RAIIExampleStruct(0));
    ns_scoped.reset(new RAIIExampleStruct(1));

    std::vector<RAIIExampleStruct> v;
    v.emplace_back(2);

    OuterObject outer(3);

    RAIIExampleStruct copy_object(4);
    copy_argument_example(copy_object);

    RAIIExampleStruct ref_object(5);
    reference_argument_example(ref_object);

    unique_ptr_argument_example(std::move(function_scoped));

    {
        RAIIExampleStruct block_scoped(6);
    }
}
