from typing import List, Set, Tuple

import pytest


class Solution:
    # O(n^3)
    def threeSumBF(self, nums: List[int]) -> List[List[int]]:
        ans: Set[Tuple[int, ...]] = set()

        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                for k in range(j + 1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        entry = sorted([nums[i], nums[j], nums[k]])
                        ans.add(tuple(entry))

        return [list(entry) for entry in ans]

    # O(n^2)
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans: Set[Tuple[int, ...]] = set()

        lookup = {}
        for i, num in enumerate(nums):
            lookup[-num] = i

        for i in range(0, len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, len(nums)):
                current_sum = nums[i] + nums[j]
                if current_sum in lookup:
                    k = lookup[current_sum]
                    if k != i and k != j:
                        entry = sorted([nums[i], nums[j], nums[k]])
                        ans.add(tuple(entry))

        return [list(entry) for entry in ans]


examples = [
    ([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),
    ([], []),
    ([0], []),
]


@pytest.mark.parametrize("nums,expected", examples)
def test_bf(nums, expected) -> None:
    sol = Solution()
    assert sorted(sol.threeSum(nums)) == expected


@pytest.mark.parametrize("nums,expected", examples)
def test_hash(nums, expected) -> None:
    sol = Solution()
    assert sorted(sol.threeSum(nums)) == expected
