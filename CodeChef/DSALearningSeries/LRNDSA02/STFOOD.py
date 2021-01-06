import sys
from typing import TextIO


def main(f: TextIO) -> None:
    t = int(f.readline())

    for _ in range(t):
        n = int(f.readline())
        ans = 0

        for _ in range(n):
            s, p, v = [int(x) for x in f.readline().split()]

            customers = p // (s + 1)
            profit = customers * v
            ans = max(profit, ans)

        print(ans)


if __name__ == "__main__":
    main(sys.stdin)
