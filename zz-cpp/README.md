# Zz C++

This project is managed by CMake with the following structure:

```
.
├── CMakeLists.txt
├── Makefile
├── README.md
└── src
    ├── 3rd_party
    │   └── catch2
    │       └── CMakeLists.txt
    ├── app
    │   ├── CMakeLists.txt
    │   └── main.cpp              <-- CodeChef / Codeforces
    ├── appless
    │   ├── CMakeLists.txt
    │   ├── appless.hpp           <-- LeetCode
    │   ├── appless_tests.cpp
    │   ├── catch2_runner.cpp
    │   └── leetcode.hpp
    └── snippet
        ├── CMakeLists.txt
        ├── include
        │   └── snippet
        │       ├── io.hpp
        │       ├── prime.hpp
        │       └── snippet.hpp
        └── src
            ├── catch2_runner.cpp
            ├── io_tests.cpp
            └── prime_tests.cpp
```
