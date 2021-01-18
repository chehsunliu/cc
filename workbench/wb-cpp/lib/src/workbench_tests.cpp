#include "workbench/workbench.hpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

TEST_CASE("simple") {
    auto *obj = new wb::MinStack();

    obj->push(11);
    obj->push(5);
    obj->push(11);
    obj->push(8);
    obj->push(3);

    obj->pop();

    REQUIRE(obj->top() == 8);
    REQUIRE(obj->getMin() == 5);
}
