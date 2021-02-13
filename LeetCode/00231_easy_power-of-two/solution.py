from leetcode import ListNode


class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        count1 = 0
        while n > 0:
            if n % 2 == 1:
                count1 += 1

            n //= 2

        return count1 == 1


def test_solution() -> None:
    _sol = Solution()

    assert _sol.isPowerOfTwo(2) is True
    assert _sol.isPowerOfTwo(4) is True
    assert _sol.isPowerOfTwo(64) is True
    assert _sol.isPowerOfTwo(65536) is True

    assert _sol.isPowerOfTwo(123) is False
    assert _sol.isPowerOfTwo(12) is False
    assert _sol.isPowerOfTwo(0) is False
    assert _sol.isPowerOfTwo(235645) is False
