# 0x0002 Scope, Stack and Heap

## Global Scope

C/C++ supports global and static variables. Both global and static variables
can be used to store read-only or read-write data. Static variables behave
differently depending on where they are declared.

 * [Global variable example][1]
 * [Static variable example][2]
 * [Static function example][3]

Global variables are stored in a variety of locations in the executable.
Constant global or static data are declared in the [.TEXT][4] segment of a
binary. Uninitialized global or static data are stored in the [.BSS][5] segment
of a binary. Initialized global or static data are stored in the [.DATA][6]
segment of a binary. Globals and statics are only deleted when the application
exits.

While this doesn't mean a whole lot in practice it's important to know that
globals and statics are stored in different locations than other variables.


## Block Scope

C/C++ is a block scoped language. This differs from Python in subtle, but
important ways. In Python, variables declared in blocks exist for the lifetime
of a function.

 * [Python scope example][7]
 * [C/C++ scope example][8]

Blocks can be used in three main settings, function definitions, data structure
definitions (both classes and structures), control flow, and anonymous (naked)
blocks.

 * [Different blocks example][9]

Anonymous blocks are rarely used in practice. They offer more fine grained
control over the lifetime of variables. Check out [this example][10] to see 
anonymous blocks in action.

All variables defined within a block are defined on the stack.

## Stack

The stack is a region of memory where block scoped variables live. The stack is
also responsible for containing function call frames. The stack starts at a
high address and moves down.

All variables declared on the stack will be cleared when they leave scope. Most
often this is due to the end curly brace of a function or control flow
construct. Throwing an exception will end scope of the variables within a
function (will cover exceptions later).

![The stack][11]

### Functions

Function calls are defined in a processor's Application Binary Interface (ABI).
Most ABI's allow for a limited amount of arguments to be passed via general
purpose registers instead of being placed on the stack.

In terms of memory allocation, registered data and stack data perform exactly
the same. When the scope is left the variables are cleared. There are just
fewer instructions needed to use data contained in registers.

## Heap

Variables with longer lifetimes than a single scope are declared on the heap.
The heap is a section of memory sandwiched between code and the stack. The heap
starts at a low address and moves upward.

Heap is used by creating space for data, initializing that data, and storing a
pointer to that data. Initialization of objects is handled by the objects
constructor (will be covered later).

C and C++ have different mechanisms for creating space on the heap. C uses a
function called `malloc`, C++ uses an operator called `new`. 

Because data declared on the heap never goes out of scope, it must be cleaned
manually. C and C++ also have different mechanisms for deleting objects created
on the heap. C uses `free` and C++ uses `delete`. 

 * [C heap example][12]
 * [C++ heap example][13]

## Raw Pointers

As illustrated in the previous examples, pointers are used to store the address
of data on the stack. Pointers and the data they point to can be manipulated in
a variety of ways.

 * [Pointer example][14]
 * [Common pointer errors example][15]

The previous example briefly touches on some of the ways pointers can be
manipulated. Modern C++ discourages the use of raw pointers; smart pointers or
references should be used instead.

## Additional References
[System V Application Binary Interface][16]


[1]: src/global_example.cc
[2]: src/static_global_example.cc
[3]: src/static_function_variable_example.cc
[4]: https://www.wikiwand.com/en/Code_segment
[5]: https://www.wikiwand.com/en/.bss
[6]: https://www.wikiwand.com/en/Data_segment
[7]: src/scope_example.py
[8]: src/scope_example.cc
[9]: src/block_scope_example.cc
[10]: http://git.denx.de/?p=u-boot.git;a=blob;f=drivers/usb/gadget/f_mass_storage.c;h=1ecb92ac6b81ed3db82a08b6e1a7d554003c0aec;hb=HEAD#l2588
[11]: img/stack.gif
[12]: src/c_heap_example.c
[13]: src/cc_heap_example.cc
[14]: src/raw_pointer_example.cc
[15]: src/bad_raw_pointer_example.cc
[16]: http://refspecs.linuxfoundation.org/elf/x86_64-abi-0.95.pdf
