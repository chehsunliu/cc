#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("example1") {
    wb::MyStack *obj = new wb::MyStack();

    obj->push(3);
    obj->push(4);
    obj->push(5);

    REQUIRE(obj->top() == 5);
    REQUIRE(obj->pop() == 5);
    REQUIRE(obj->top() == 4);

    REQUIRE(obj->pop() == 4);
    REQUIRE(obj->empty() == false);
    REQUIRE(obj->pop() == 3);
    REQUIRE(obj->empty() == true);
}