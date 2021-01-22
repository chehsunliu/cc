from collections import Counter


class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        ans = []
        for hour in range(12):
            for minute in range(60):
                if Counter(bin(hour))["1"] + Counter(bin(minute))["1"] == num:
                    ans.append("%d:%02d" % (hour, minute))
        return ans
