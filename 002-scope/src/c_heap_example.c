#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct person {
	int age;
	char *name;
};

void single_structure(void) {
	/* Create a pointer for a person struct. */
	struct person *person_ptr = NULL;

	/* Create the space for a person struct. */
	person_ptr = (struct person *)malloc(sizeof(struct person));

	/* Initialize the person struct. */
	person_ptr->age = 1;
	person_ptr->name = "a";

	printf("Name: %s\n", person_ptr->name);
	printf("Age: %d\n", person_ptr->age);

	/* Free the person struct. */
	if (person_ptr != NULL) {
		free(person_ptr);
		person_ptr = NULL;
	}
}

void array_of_structures(void) {
	/* Create a pointers for 3 people. */
	struct person *people_ptr = NULL;

	/* Create the space for 3 people. */
	people_ptr = malloc(sizeof(struct person) * 3);

	/* Initialize the person struct. */
	people_ptr[0].age = 1;
	people_ptr[0].name = "a";

	people_ptr[1].age = 2;
	people_ptr[1].name = "b";

	people_ptr[2].age = 3;
	people_ptr[2].name = "c";

	for (int i = 0; i < 3; i++) {
		printf("Name: %s\n", people_ptr[i].name);
		printf("Age: %d\n", people_ptr[i].age);
	}

	/* Free the people. */
	if (people_ptr != NULL) {
		free(people_ptr);
		people_ptr = NULL;
	}
}

int main(void) {
	single_structure();
	array_of_structures();

	return EXIT_SUCCESS;
}
