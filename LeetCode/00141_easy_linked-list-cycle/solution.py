from leetcode import ListNode


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False

        ptr = head
        while ptr:
            if ptr.val is None:
                return True

            ptr.val = None
            ptr = ptr.next

        return False


def test_solution() -> None:
    _sol = Solution()
