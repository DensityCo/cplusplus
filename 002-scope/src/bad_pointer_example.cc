#include <unistd.h>

#include <iostream>
#include <string>

struct MyThing {
	int a;
	int b;
	std::string c; // THIS IS JUST A STRING
};

struct MyOtherThing {
	std::string *c; // THIS IS A POINTER TO A STRING
};

void pointer_math_error(void) {
	/* NOTE (BNB): auto is a way to avoid typing so much. It lets the    *
	 *             compiler deduce the type of the thing on the right    *
	 *             hand side of the assignment.                          */
	auto things = new MyThing[3] {
		{1, 1, "a"},
		{2, 2, "b"},
		{3, 3, "c"}
	};

	/* If we try to access things on the heap that are not defined we    *
	 * get big ugly errors sometimes. Even though we don't segfault      *
	 * every time, it's still really, really bad.                        *
	 *                                                                   *
	 * NOTE (BNB): add -fstack-protector-all to your compile flags for   *
	 *             this to actually segfault.                            */
	std::cout << things[999999999999999999].c << std::endl;

	/* Some old C programmers will actually use math for this sort of    *
	 * thing, and that's terrible because it's hard to read and error    *
	 * prone.                                                            */
	std::cout << (things+1)->c <<std::endl;
}

void no_delete_error(void) {
	/* If we allocate something on the heap and never delete it we leak  *
	 * those bytes. Don't do that.                                       */
	auto thing1 = new MyThing { 1, 2, "a"};

	/* It's also bad if you create an object with pointers in it and     *
	 * free what's in the pointers before freeing the top object. You'll *
	 * loose those bytes forever.                                        */
	auto thing2 = new MyOtherThing { new std::string("Hello") };
	delete thing2; // Now I can't get at "Hello".
}

void double_delete_error(void) {
	/* If we double delete we'll corrupt memory. That's no good either. */
	auto thing = new MyThing { 1, 2, "a" };
	delete thing;
	delete thing;
}

int main(void) {
	pointer_math_error();
	no_delete_error();
	double_delete_error();
	
	return EXIT_SUCCESS;
}
