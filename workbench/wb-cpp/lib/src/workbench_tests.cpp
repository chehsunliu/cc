#include <string>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("GG #1") {
    wb::MyQueue q;
    REQUIRE(q.empty() == true);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    REQUIRE(q.peek() == 1);
    REQUIRE(q.empty() == false);
    REQUIRE(q.pop() == 1);
    REQUIRE(q.pop() == 2);
    REQUIRE(q.pop() == 3);
    REQUIRE(q.peek() == 4);
    REQUIRE(q.pop() == 4);

    q.push(5);
    REQUIRE(q.pop() == 5);
    REQUIRE(q.empty() == true);
}
