Exceptions




Resources

Finally a resource that finally explains why to use exceptions
https://isocpp.org/wiki/faq/exceptions#why-exceptions

Why use exceptions

	Makes code cleaner - No need to check for a bad status from each constructor, or bracket function calls with
			     if statements. No need to pass the error code back up manually.
	Error notification
	is prioritized 	   - When exceptions are throw they immedietly report the error to the programmer, instead of
			     automatically continuing on with program execution.
	The alternative
	requires you to
	be clever	   - Error codes breakdown for functions that return zero, Null, or negative numbers during
			     their normal operation.

Things to know about exceptions in C++

	Exceptions in C++
	are designed to
	support error
	handling	   - Do not use exception for control flow. Exceptions are not just another method to return a value from a 				     function. exception handling code is error-handling code.

			   - Exceptions execute much slower than a standard return, but their advantage is that they
			     bubble up, notifying you of the error regardless of how many function calls deep the error
			     happened, so you do not need error checking if statements in each parent function.

			   - Exceptions are used for run-time error conditions (IO errors, out of memory, can't get a
			     database connection, etc. Exceptions may be conditions you wnat to handle and deal with.

			   - Do not throw exceptions from distructors as a rule, if you must, Catch and handle the exception
                             in the destructor. This is because of stack unwinding and all the destructor of the calling
			     object will be called until a catch statement is encountered to handle the error. If a
			     second exception is thrown during an exception, terminate is called and the program ends
			     immediatly. This can cause leaks of system resources.

			   - Use assert instead for coding errors to crash the process and collect the crash dump for
			     the developer to debug. E.g. This method doesn't accept nulls, and the developer passed
			     one anyway. Assertions test for conditions that shouldn't be handled by the program, but
			     should be corrected by the programmer instead.
			     by the programmer.

			   - For libraries with public classes, throw exceptions on the public methods. Assertions are used
			     to catch YOUR mistakes, not theirs.

Questions I have...

Why in my example can the stdexcept include be uncommented and still work?

noexcept specifiers in function definitions, it was unclear if this style of coding is still expected, or depricated



