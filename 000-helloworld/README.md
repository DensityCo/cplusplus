# Environment Setup Ubuntu 17.04
```bash
sudo apt-get install build-essential cmake
```

# Environment Setup OSX
```bash
1. Install HomeBrew
2. Install XCode & XCode Commandline
3. brew update && brew upgrade
4. brew install cmake
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

# Reference
[C Bit-wise Arithmetic](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)
[GDB & LLDB Cheatsheet](https://lldb.llvm.org/lldb-gdb.html)

