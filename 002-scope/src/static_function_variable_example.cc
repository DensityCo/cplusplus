#include <unistd.h>

#include <iostream>
#include <string>

int counter(void) {
	/* This variable lives on after the function has been exited, and it *
	 * keeps the state it had in the previous call. Pretty cool, huh?    */
	static int my_counter = 0;

	return my_counter++;
}

int main(void) {
	std::cout << counter() << std::endl;
	std::cout << counter() << std::endl;
	std::cout << counter() << std::endl;
	std::cout << counter() << std::endl;
	std::cout << counter() << std::endl;
	return EXIT_SUCCESS;
}
