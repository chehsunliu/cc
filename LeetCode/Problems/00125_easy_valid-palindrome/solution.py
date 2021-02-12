import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r"[^a-zA-Z0-9]", "", s).lower()
        middle = len(s) // 2

        s_left = s[0:middle]
        s_right = s[middle + len(s) % 2:len(s)]
        return s_right == "".join(list(reversed(s_left)))


def test_solution() -> None:
    sol = Solution()

    assert sol.isPalindrome("A man, a plan, a canal: Panama")
    assert not sol.isPalindrome("race a car")
