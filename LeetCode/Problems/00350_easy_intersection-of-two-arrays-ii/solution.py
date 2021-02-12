from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        map1 = {}
        map2 = {}

        for n in nums1:
            if n not in map1:
                map1[n] = 0
            map1[n] += 1

        for n in nums2:
            if n not in map2:
                map2[n] = 0
            map2[n] += 1

        overlapped = set(map1.keys()).intersection(set(map2.keys()))
        ans = []
        for n in overlapped:
            ans += [n] * min(map1[n], map2[n])
        return ans


def test_example1() -> None:
    _sol = Solution()
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]

    assert _sol.intersect(nums1, nums2) == [2, 2]


def test_example2() -> None:
    _sol = Solution()
    nums1 = [4, 9, 5]
    nums2 = [9, 4, 9, 8, 4]

    assert _sol.intersect(nums1, nums2) == [9, 4]
