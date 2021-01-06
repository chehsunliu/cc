import sys
from typing import TextIO


def main(f: TextIO) -> None:
    t = int(f.readline())

    for _ in range(t):
        n = int(f.readline())
        s = f.readline().strip()
        assert len(s) == n * 2

        # n: 3
        # a: 0 2 4
        # b: 1 3 5
        # --
        # a: 1 1 1
        # b: 0 0 1

        scores = [0, 0]
        ans = -1
        total_turns = 2 * n
        for turn in range(total_turns):
            scores[turn % 2] += int(s[turn])

            if turn % 2 == 0:
                if scores[0] > scores[1] + (total_turns - turn) // 2:
                    ans = turn
                    break
                elif scores[0] + (total_turns - turn) // 2 - 1 < scores[1]:
                    ans = turn
                    break

            else:
                if scores[1] > scores[0] + (total_turns - turn) // 2:
                    ans = turn
                    break
                elif scores[1] + (total_turns - turn) // 2 < scores[0]:
                    ans = turn
                    break

        print((ans + 1) if ans >= 0 else total_turns)


if __name__ == "__main__":
    main(sys.stdin)
