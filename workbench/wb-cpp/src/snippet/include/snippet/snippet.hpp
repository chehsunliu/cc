#ifndef __SNIPPET_H__
#define __SNIPPET_H__

#include <iostream>
#include <vector>

namespace snippet {

template <class T> void print_vector(const std::vector<T*> &vec, int n, bool reverse) {
    if (reverse) {
        for (int i = 0; i < n && vec.size() - 1 - i >= 0; i++) {
            std::cerr << *vec[vec.size() - 1 - i] << " ";
        }
    } else {
        for (int i = 0; i < n && i < vec.size(); i++) {
            std::cerr << *vec[i] << " ";
        }
    }
    std::cerr << std::endl;
}

template <class T> void print_vector(const std::vector<T> &vec, int n, bool reverse) {
    if (reverse) {
        for (int i = 0; i < n && vec.size() - 1 - i >= 0; i++) {
            std::cerr << vec[vec.size() - 1 - i] << " ";
        }
    } else {
        for (int i = 0; i < n && i < vec.size(); i++) {
            std::cerr << vec[i] << " ";
        }
    }
    std::cerr << std::endl;
}

template <class T> void print_vector(const std::vector<T> &vec) { print_vector(vec, vec.size(), false); }
template <class T> void print_vector(const std::vector<T> &vec, int n) { print_vector(vec, n, false); }

} // namespace snippet

#endif
