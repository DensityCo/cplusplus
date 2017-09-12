#include <unistd.h>

#include <iostream>
#include <string>

int main(void) {
	if (true) {
		std::string name("World");
	}

	std::cout << "Hello " << name << "!" << std::endl;

	return EXIT_SUCCESS;
}
