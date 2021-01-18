import sys
import math


def main():
    for line in sys.stdin:
        n = int(line.strip())
        acc = 0
        for nn in range(1, n + 1):
            acc += math.log10(nn)
        acc = int(acc) + 1
        print(acc)


if __name__ == "__main__":
    main()
