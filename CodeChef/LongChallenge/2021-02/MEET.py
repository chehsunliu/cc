#!/usr/bin/env python
import sys
from datetime import datetime
from typing import List


def main() -> None:
    number_of_tests: int = int(sys.stdin.readline().strip())

    for _ in range(number_of_tests):
        answers: List[str] = []
        meeting_time = datetime.strptime(sys.stdin.readline().strip(), "%I:%M %p")

        number_of_friends: int = int(sys.stdin.readline().strip())
        for _ in range(number_of_friends):
            l0, l1, r0, r1 = sys.stdin.readline().strip().split(" ")
            l_time = datetime.strptime(l0 + " " + l1, "%I:%M %p")
            r_time = datetime.strptime(r0 + " " + r1, "%I:%M %p")

            if l_time <= meeting_time <= r_time:
                answers.append("1")
            else:
                answers.append("0")

        print("".join(answers))


if __name__ == "__main__":
    main()
