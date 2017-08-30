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
./opencv
```

# Debug on Linux
```bash
gdb ./opencv
```

# Debug on OSX
```bash
lldb ./opencv
```

