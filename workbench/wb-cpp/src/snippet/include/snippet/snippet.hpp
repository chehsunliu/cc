#ifndef __SNIPPET_H__
#define __SNIPPET_H__

#include <iostream>
#include <vector>

namespace snippet {

template <class T> void print_vector(const std::vector<T> &vec) {
    for (auto &item : vec) {
        std::cerr << item << " ";
    }
    std::cerr << std::endl;
}

}

#endif
