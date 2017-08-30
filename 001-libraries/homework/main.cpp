#include <iostream>
#include <string>

std::string get_name(void);

int main(void) {
	std::cout << "Hello " << get_name() << std::endl;
	return 0;
}
