from typing import List


def check(num: int, power: int, power_limit: int, acc: int, acc_limit: int, results: List[int]) -> None:
    if power > power_limit:
        if num == 0 and acc <= acc_limit:
            results.append(acc)
        return

    check(num - 1, power + 1, power_limit, acc + pow(2, power), acc_limit, results)
    check(num, power + 1, power_limit, acc, acc_limit, results)


class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        ans = []

        for top_lights in range(num + 1):
            bot_lights = num - top_lights

            top_outcomes = []
            check(top_lights, 0, 3, 0, 11, top_outcomes)

            bot_outcomes = []
            check(bot_lights, 0, 5, 0, 59, bot_outcomes)

            for hours in top_outcomes:
                for minutes in bot_outcomes:
                    ans.append("%d:%02d" % (hours, minutes))

        return ans
