#include <vector>

#include "catch2/catch.hpp"
#include "codebook/io.hpp"

TEST_CASE("Simple call for print_vector should work normally") {
    std::vector<int> nums({11, 22, 33});
    codebook::io::print_vector(nums);
}