import sys
from typing import TextIO, Tuple, List, NamedTuple


class Event(NamedTuple):
    timestamp: float
    athletes: List


def process(speeds: List[int]) -> Tuple[int, int]:
    events: List[Event] = []
    num_of_athletes = len(speeds)

    for i in range(num_of_athletes - 1):
        for j in range(i + 1, num_of_athletes):
            if speeds[i] == speeds[j]:
                continue

            timestamp = -(i - j) / (speeds[i] - speeds[j])
            if timestamp >= 0:
                events.append(Event(timestamp, [i, j]))

    if not events:
        return 1, 1

    events.sort(key=lambda k: k.timestamp)

    smallest_infected_group = num_of_athletes
    largest_infected_group = 0

    for i in range(num_of_athletes):
        infected = [False for _ in range(num_of_athletes)]
        infected[i] = True

        for j in range(len(events)):
            a0, a1 = events[j].athletes
            if infected[a0] or infected[a1]:
                infected[a0] = infected[a1] = True

            if j > 0 and events[j - 1].timestamp == events[j].timestamp and not set(events[j - 1].athletes).isdisjoint(
                    set(events[j].athletes)):
                b0, b1 = events[j - 1].athletes
                if infected[b0] or infected[b1] or infected[a0] or infected[a1]:
                    infected[b0] = infected[b1] = infected[a0] = infected[a1] = True

        count = len([a for a in infected if a])
        smallest_infected_group = min(smallest_infected_group, count)
        largest_infected_group = max(largest_infected_group, count)

    return smallest_infected_group, largest_infected_group


def main(f: TextIO) -> None:
    t = int(f.readline())

    for _ in f:
        speeds = [int(s) for s in f.readline().split()]
        print("%d %d" % process(speeds))


if __name__ == "__main__":
    main(sys.stdin)
