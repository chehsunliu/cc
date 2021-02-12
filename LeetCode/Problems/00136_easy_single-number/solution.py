from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = nums[0]
        for n in nums[1:]:
            ans ^= n
        return ans


def test_solution() -> None:
    sol = Solution()

    assert sol.singleNumber([2, 2, 1]) == 1
    assert sol.singleNumber([4, 1, 2, 1, 2]) == 4
    assert sol.singleNumber([1]) == 1
