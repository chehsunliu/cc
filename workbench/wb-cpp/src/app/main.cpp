#include <vector>

#include "snippet/snippet.hpp"

int main() {
    std::vector<int> a(2, 3);

    snippet::print_vector<int>(a);

    return 0;
}