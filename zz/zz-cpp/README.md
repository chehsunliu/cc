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
    │   └── main.cpp               <-- for CodeChef, Codeforces, and etc.
    ├── appless
    │   ├── CMakeLists.txt
    │   ├── include
    │   │   └── appless
    │   │       ├── appless.hpp    <-- for LeetCode
    │   │       └── leetcode.hpp
    │   └── src
    │       ├── appless_tests.cpp
    │       └── catch2_runner.cpp
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
