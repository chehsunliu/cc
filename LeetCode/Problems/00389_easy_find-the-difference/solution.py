from typing import Dict


def count_to_map(s: str) -> Dict[str, int]:
    ans = {}
    for c in s:
        if c not in ans:
            ans[c] = 0
        ans[c] += 1
    return ans


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        count_s = count_to_map(s)
        count_t = count_to_map(t)

        for k in count_t:
            value_t = count_t[k]
            value_s = count_s.get(k, 0)

            if value_t != value_s:
                return k

        return None
