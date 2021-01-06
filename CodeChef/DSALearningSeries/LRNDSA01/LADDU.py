import sys
from typing import TextIO


def main(f: TextIO):
    t: int = int(f.readline())

    for _ in range(t):
        activities_raw, origin = f.readline().split(maxsplit=2)
        activities = int(activities_raw)
        laddus = 0

        for _ in range(activities):
            line = f.readline()

            if line.startswith("CONTEST_WON"):
                _, rank_raw = line.split()
                laddus += 300 + max(20 - int(rank_raw), 0)

            elif line.startswith("TOP_CONTRIBUTOR"):
                laddus += 300

            elif line.startswith("BUG_FOUND"):
                _, severity_raw = line.split()
                laddus += int(severity_raw)

            else:
                laddus += 50

        if origin == "INDIAN":
            print(laddus // 200)
        else:
            print(laddus // 400)


if __name__ == "__main__":
    main(sys.stdin)
