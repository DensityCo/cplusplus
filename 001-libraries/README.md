# Environment Setup Ubuntu 17.04
```bash
sudo apt-get install build-essential cmake libopencv-dev qtcreator
```

# Environment Setup OSX
```bash
1. brew update && brew upgrade
2. brew install cmake opencv
3. Download and install Qt Creator https://download.qt.io/official_releases/qtcreator/4.3/4.3.1/qt-creator-opensource-mac-x86_64-4.3.1.dmg
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

# QtCreator
1. Open QtCreator
2. 

# References
* [Qt Creator|https://www.qt.io/ide/]

