#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdexcept>

using namespace std;

int multiply(int number){

    int result;

    if(__builtin_smul_overflow(number, 2 , &result))
    {
        throw overflow_error("Number too large. Signed int overflow detected");
    }

    return(result);

}

int main(int argc, char ** argv)
{

    int population = 2;

    try {
        for(auto x=0; x < 40 ; x++) {
            population = multiply(population);
            cout << "Population for year " << x << " is " << population << endl;
        }
    }
    catch(const std::exception& e) {
        std::cout << "Caught " << e.what() << '\n';
    }
    catch(...) {
        cout << "This is the default catch-all for errors" << endl;
    }



}
