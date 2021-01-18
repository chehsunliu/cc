import sys
import math


def f_init(n):
    ans = 0
    for nn in range(1, n + 1):
        ans += (n - nn + 1) * math.log10(nn)
    return ans


def main():
    ns = list()
    for index, line in enumerate(sys.stdin):
        if index == 0:
            continue

        ns.append(int(line.strip()))

    new_ns = sorted(ns)
    dp_b = dict()
    dp_f = dict()

    for index, n in enumerate(new_ns):
        if index == 0:
            ans = f_init(n)

        elif n in dp_f:
            ans = dp_f[n]

        else:
            prev_n = new_ns[index - 1]

            b = 0
            for nn in range(n, 0, -1):
                if nn in dp_b:
                    b += dp_b[nn]
                    break
                else:
                    b += math.log10(nn)
            dp_b[n] = b
            b *= (n - prev_n)

            tri = 0
            for nn in range(prev_n + 2, n + 1):
                tri += math.log10(nn) * (nn - (prev_n + 2) + 1)

            ans = dp_f[prev_n] + b - tri

        dp_f[n] = ans

    for nn in ns:
        print(int(dp_f[nn]) + 1)


if __name__ == "__main__":
    main()
