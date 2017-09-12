#include <unistd.h>

#include <iostream>
#include <string>

/* This is a static global variable; this variable is only accessible from   *
 * this translation unit (file).                                             */
static std::string name("Bradford");

int main(void) {
	std::cout << "Hello " << name << std::endl;
	return EXIT_SUCCESS;
}
