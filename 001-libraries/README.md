# Environment Setup Ubuntu 17.04
```bash
sudo apt-get install build-essential cmake libopencv-dev
```

# Environment Setup OSX
```bash
3. brew update && brew upgrade
4. brew install cmake opencv
```

# Build it
```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=DEBUG
make VERBOSE=1
./helloworld
```

# Debug on Linux
```bash
gdb ./helloworld
```

# Debug on OSX
```bash
lldb ./helloworld
```

# Inspect Return Code
```bash
./helloworld
echo $?
```

# Reference
* [C Bit-wise Arithmetic](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)
* [GDB & LLDB Cheatsheet](https://lldb.llvm.org/lldb-gdb.html)
* [std::cout reference](http://en.cppreference.com/w/cpp/io/cout)
* [iostream reference](http://en.cppreference.com/w/cpp/header/iostream)
* [Fixed width types](http://en.cppreference.com/w/cpp/types/integer)
* [Static cast](http://en.cppreference.com/w/cpp/language/static_cast)
* [input / output manipulators](http://en.cppreference.com/w/cpp/io/manip/hex)
* [GCC command line cheatsheet](http://lzone.de/cheat-sheet/GCC)
* [CMake Cheat Sheet](http://jbrd.github.io/2011/07/16/cmake-cheat-sheet.html)

