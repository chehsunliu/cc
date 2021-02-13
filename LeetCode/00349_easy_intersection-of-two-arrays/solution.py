from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1 = set(nums1)
        set2 = set(nums2)
        return list(set1.intersection(set2))


def test_example1() -> None:
    _sol = Solution()
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]

    assert _sol.intersection(nums1, nums2) == [2]


def test_example2() -> None:
    _sol = Solution()
    nums1 = [4, 9, 5]
    nums2 = [9, 4, 9, 8, 4]

    assert _sol.intersection(nums1, nums2) == [9, 4]
