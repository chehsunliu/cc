#ifndef __SNIPPET_IO_H__
#define __SNIPPET_IO_H__

#include <iostream>
#include <vector>

namespace codebook {
namespace io {

template <class T> void print_vector(const std::vector<T *> &vec, int n, bool reverse = false) {
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

template <class T> void print_vector(const std::vector<T> &vec, int n, bool reverse = false) {
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

template <class T> void print_vector(const std::vector<T> &vec) { print_vector(vec, vec.size()); }
template <class T> void print_vector(const std::vector<T> &vec, int n) { print_vector(vec, n); }

} // namespace io
} // namespace codebook

#endif // WB_CPP_IO_HPP
