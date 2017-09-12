#include <unistd.h>

#include <iostream>
#include <string>

int main(void) {
	std::cout << "This is a function block scope." << std::endl;

	if (true) {
		std::cout << "This is a conditional block scope." << std::endl;
	}

	do {
		std::cout << "This is a do-while block scope." << std::endl;
	} while(false);

	while(true) {
		std::cout << "This is a while block scope." << std::endl;
		break;
	}

	for (int i = 0; i < 5; i++) {
		/* The i declared in the top of the function only lives as   *
		 * long as the end of the loop                               */

		std::cout << "This is a for block scope." << std::endl;
	}

	return EXIT_SUCCESS;
}
