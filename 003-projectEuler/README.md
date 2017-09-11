# Environment Setup Ubuntu 17.04
```bash
sudo apt-get install build-essential cmake
```

# Environment Setup OSX
```bash
1. brew update && brew upgrade
2. brew install cmake
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
