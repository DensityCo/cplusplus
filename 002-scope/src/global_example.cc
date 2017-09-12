#include <unistd.h>

#include <iostream>
#include <string>

/* This is a global variable; we can access it from anywhere. */
std::string name("Bradford");

int main(void) {
	std::cout << "Hello " << name << std::endl;
	return EXIT_SUCCESS;
}
