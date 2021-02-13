from typing import Callable

from pytest_mock import MockerFixture


def isBadVersion(version: int) -> bool:
    raise Exception("QQ")


class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 1
        right = n

        while left <= right:
            middle = (left + right) // 2
            if isBadVersion(middle):
                right = middle - 1
            else:
                left = middle + 1

        return left


def fake_is_bad_version(bad: int) -> Callable[[int], bool]:
    def f(version: int) -> bool:
        return version >= bad

    return f


def test_example1(mocker: MockerFixture) -> None:
    mock_f = mocker.patch("lib.isBadVersion", autospec=True)
    mock_f.side_effect = fake_is_bad_version(4)

    _sol = Solution()
    assert _sol.firstBadVersion(5) == 4


def test_example2(mocker: MockerFixture) -> None:
    mock_f = mocker.patch("lib.isBadVersion", autospec=True)
    mock_f.side_effect = fake_is_bad_version(1)

    _sol = Solution()
    assert _sol.firstBadVersion(1) == 1
