import re
import sys
import math


pattern = re.compile("(RED|GREEN)")


def main():
    for line in sys.stdin:
        line = line.strip()
        match = pattern.findall(line)
        print("1/%d" % math.pow(2, len(match)))


if __name__ == "__main__":
    main()
