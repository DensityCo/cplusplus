#include <unistd.h>

#include <iostream>
#include <new>
#include <string>

struct Person {
	int age;
	std::string name;
};

void single_structure(void) {
	/* Create a pointer for a person struct. */
	Person *person_ptr = NULL;

	/*                                                                   *
	 * Create the space for a person struct.                             *
	 *                                                                   *
	 * NOTE (BNB): This fancy curly brace thing is called an initializer *
	 *             list. It's basically a quick way to initialize a      *
	 *             struct or object. We'll cover this more later.        */
	person_ptr = new Person {1, "a"};

	std::cout << "Name: " << person_ptr->name << std::endl;
	std::cout << "Age: " << person_ptr->age << std::endl;

	/* Free the person struct. */
	if (person_ptr != NULL) {
		delete person_ptr;
		person_ptr = NULL;
	}
}

void array_of_structures(void) {
	/* Create a pointer for some person structs. */
	Person *people_ptr = NULL;

	/*                                                                   *
	 * Create the space for three people, initialize them too.           *
	 *                                                                   *
	 * NOTE (BNB): Initializer lists can be used to initialize multiple  *
	 *             thing too!                                            */
	people_ptr = new Person[3] {
		{1, "a"},
		{2, "b"},
		{3, "c"}
	};

	for (int i = 0; i < 3; i++) {
		std::cout << "Name: " << people_ptr[i].name << std::endl;
		std::cout << "Age: " << people_ptr[i].age << std::endl;
	}

	/* Free the people. */
	if (people_ptr != NULL) {
		delete[] people_ptr;
		people_ptr = NULL;
	}
}

int main(void) {
	single_structure();
	array_of_structures();

	return EXIT_SUCCESS;
}
