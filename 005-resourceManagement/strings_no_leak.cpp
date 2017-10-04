#include <iostream>
#include <string>

std::string append_strings(const std::string& s1, const std::string& s2)
{
    return s1 + s2;
}

int run()
{
    std::string s1("density ");
    std::string s2("is awesome");

    std::cout << append_strings(s1, s2) << std::endl;
}

int main(int argc, char** argv)
{
    run();
    //No memory leak here.  Why?

    return 0;
}
