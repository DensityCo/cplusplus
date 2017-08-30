# 0x0001 Homework

The following exercises should be done from the command line without the use
of CMake or other build tools.

There are two source files in this directory, `main.cpp` and `name.cpp`. 
Try to do the following:

1. Compile each file into an object file.
2. Create an executable that links the two object files.
3. Make `name.cpp` into a static library (`libname.a`).
4. Link `libname.a` to main.o for a statically linked executable.
5. Make `name.cpp` into a dynamic library (`libname.so`).
6. Link `libname.so` to main.o for a dynamically linked executable.
7. Verify 6 with `ldd`.
8. Build the 0x0001 project with VERBOSE=1.
  * Figure out what flags are compiler flags, and read up on them.
  * Figure out what flags are linker flags, and read up on them.
