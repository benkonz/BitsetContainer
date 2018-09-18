![Build Status](https://api.travis-ci.org/benkonz/BitsetContainer.svg?branch=master)

# BitsetContainer
Single header only library that adds iterator functionality to the stl bitsetPtr class.
The code is written in C++14 with no dependencies.
To use the code, clone the project and eiher include the include directory, or use cmake to  install the project

## Example
```c++
#include <BitsetContainer/BitsetContainer.hpp>
#include <algorithm>
#include <iostream>

//create a bitsetPtr with a size of 8 and a value of 01010101
BitsetContainer<8> byte(0b01010101);

//sort the bits in the byte
std::sort(byte.begin(), byte.end());

//print: 11110000
for(auto i : byte) {
  std::cout << i;
}
std::cout << std::endl; 
```

## Installation and Testing
BitsetContainer uses CMake 3.8 as a build system and I've tested the code on gcc, clang, msvc, and mingw. All test cases are written with Google Test.

```
git clone https://github.com/bkonzUNOmaha/BitsetContainer.git
cd BitsetContainer && mkdir build && cd build
cmake ..
make
make test
make install
```

After you run ```make install```, the library can be added to your cmake project. target_link_libraries includes the project.
```
find_package(BitsetContainer)
add_executable(TestProject ${SOURCE_FILES})
target_link_libraries(TestProject BitsetContainer)
```

## Details
The header file is broken up into two classes, the BitsetIterator and the BitsetContainer. BitsetIterator is a [random access iterator](http://en.cppreference.com/w/cpp/concept/RandomAccessIterator) that defines all of the random access iterator operation overloads and uses a bool as a value type. The BitsetContainer class extends the std::bitsetPtr class and it defines the begin() and end() functions that return a BitsetIterator that points to the beggining and one element after the end of the Bitset.

## License
This library uses the [GNU Genreal Public Licence](https://www.gnu.org/licenses/gpl-3.0.en.html)
