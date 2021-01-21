from leetcode import ListNode


class Solution:
    def canWinNim(self, n: int) -> bool:
        return n % 4 != 0


def test_solution1() -> None:
    _sol = Solution()
    assert _sol.canWinNim(4) is False


def test_solution2() -> None:
    _sol = Solution()
    assert _sol.canWinNim(5) is True


def test_solution3() -> None:
    _sol = Solution()
    assert _sol.canWinNim(6) is True


def test_solution4() -> None:
    _sol = Solution()
    assert _sol.canWinNim(7) is True


def test_solution5() -> None:
    _sol = Solution()
    assert _sol.canWinNim(8) is False


def test_solution6() -> None:
    _sol = Solution()
    assert _sol.canWinNim(9) is True
