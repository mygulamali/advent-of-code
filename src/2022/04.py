#!/usr/bin/env python

from typing import List

from utils import read_puzzle_data

DAY = 4

TEST_DATA = [
    "2-4,6-8",
    "2-3,4-5",
    "5-7,7-9",
    "2-8,3-7",
    "6-6,4-6",
    "2-6,4-8",
]


def part_1(data: List[str]) -> int:
    total_overlaps = 0

    for line in data:
         first, second = line.split(",")
         first = [int(x) for x in first.split("-")]
         second = [int(x) for x in second.split("-")]

         if ((first[0] <= second[0]) and (first[1] >= second[1]) or
             (first[0] >= second[0]) and (first[1] <= second[1])):
             total_overlaps += 1

    return total_overlaps


def part_2(data: List[str]) -> int:
    total_overlaps = 0

    for line in data:
         first, second = line.split(",")
         first = [int(x) for x in first.split("-")]
         second = [int(x) for x in second.split("-")]

         first_range_set = set(range(first[0], first[1] + 1))
         second_range_set = set(range(second[0], second[1] + 1))

         if len(first_range_set & second_range_set) > 0:
             total_overlaps += 1

    return total_overlaps


if __name__ == "__main__":
    assert part_1(TEST_DATA) == 2
    assert part_2(TEST_DATA) == 4

    data = read_puzzle_data(DAY)

    total_overlaps = part_1(data)
    print(f"Part 1: {total_overlaps}")

    total_overlaps = part_2(data)
    print(f"Part 2: {total_overlaps}")
