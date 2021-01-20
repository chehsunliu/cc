#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("GG #1") {
    int _nums[] = {1, 2};
    std::vector<int> nums(_nums, _nums + 2);
    wb::ListNode *head = wb::ListNode::from_vector(nums);

    wb::Solution sol;
    REQUIRE(sol.isPalindrome(head) == false);

    delete head;
}

TEST_CASE("GG #2") {
    int _nums[] = {1, 2, 2, 1};
    std::vector<int> nums(_nums, _nums + 4);
    wb::ListNode *head = wb::ListNode::from_vector(nums);

    wb::Solution sol;
    REQUIRE(sol.isPalindrome(head) == true);

    delete head;
}
