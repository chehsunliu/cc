from typing import List

from leetcode import ListNode


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        history = set(nums)
        max_value = max(history)

        if max_value + 1 == n:
            return max_value + 1
        else:
            return (set(list(range(max_value + 1))) - history).pop()


def test_solution1() -> None:
    _sol = Solution()
    assert _sol.missingNumber([3, 0, 1]) == 2


def test_solution2() -> None:
    _sol = Solution()
    assert _sol.missingNumber([0, 1]) == 2


def test_solution3() -> None:
    _sol = Solution()
    assert _sol.missingNumber([9, 6, 4, 2, 3, 5, 7, 0, 1]) == 8


def test_solution4() -> None:
    _sol = Solution()
    assert _sol.missingNumber([0]) == 1
