#include <unistd.h>

#include <iostream>
#include <string>

int main(void) {
	/* This is how we define a pointer. */
	int *ptr = NULL;

	/* It's important to initialize pointers to null so you know you     *
	 * haven't used it yet.                                              */

	/* This is how we declare a variable. */
	int i = 200;

	/* To set the pointer to an address of a variable we need to use the *
	 * & operator. Prefacing the name of a variable with an & will give  *
	 * us the address of the variable.                                   *
	 *                                                                   *
	 * This pointer is actually pointing to a memory location on the     *
	 * the stack. Pointers don't care where the memory is, as long as    *
	 * the application has the correct permissions to access that memory */
	ptr = &i;

	/* Let's print out the addresses of i and ptr. Notice how the        *
	 * addresses are different.                                          */
	std::cout << "&ptr: " << &ptr << std::endl;
	std::cout << "&i:   " << &i << std::endl;

	/* Now lets point out the value of ptr. Notice how it's the same as  *
	 * address of i.                                                     */
	std::cout << "ptr:  " << ptr << std::endl;

	/* To get the contents of the pointer we need to dereference the     *
	 * pointer. This can be accomplished with the * (dereference)        *
	 * operator.                                                         */
	std::cout << "*ptr: " << *ptr << std::endl;
	std::cout << "i:    " << i << std::endl;

	/* We can even set the value of i through the pointer using the      *
	 * dereference operator.                                             */
	*ptr = 3000;
	std::cout << "i:    " << i << std::endl;

	/* Because the data pointed to by ptr is stack allocated we don't    *
	 * need to call delete.                                              */

	return EXIT_SUCCESS;
}
