#include <string>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("example1") {
    wb::Solution sol;

    int _nums[] = {0, 1, 2, 4, 5, 7};
    vector<int> nums(_nums, _nums + 6);
    vector<string> ans = sol.summaryRanges(nums);

    REQUIRE(ans.size() == 3);
    REQUIRE(ans[0] == "0->2");
    REQUIRE(ans[1] == "4->5");
    REQUIRE(ans[2] == "7");
}

TEST_CASE("example2") {
    wb::Solution sol;

    int _nums[] = {0, 2, 3, 4, 6, 8, 9};
    vector<int> nums(_nums, _nums + 7);
    vector<string> ans = sol.summaryRanges(nums);

    REQUIRE(ans.size() == 4);
    REQUIRE(ans[0] == "0");
    REQUIRE(ans[1] == "2->4");
    REQUIRE(ans[2] == "6");
    REQUIRE(ans[3] == "8->9");
}

TEST_CASE("example3") {
    wb::Solution sol;

    vector<int> nums;
    vector<string> ans = sol.summaryRanges(nums);

    REQUIRE(ans.empty());
}

TEST_CASE("example4") {
    wb::Solution sol;

    int _nums[] = {-1};
    vector<int> nums(_nums, _nums + 1);
    vector<string> ans = sol.summaryRanges(nums);

    REQUIRE(ans.size() == 1);
    REQUIRE(ans[0] == "-1");
}

TEST_CASE("example5") {
    wb::Solution sol;

    int _nums[] = {0};
    vector<int> nums(_nums, _nums + 1);
    vector<string> ans = sol.summaryRanges(nums);

    REQUIRE(ans.size() == 1);
    REQUIRE(ans[0] == "0");
}
