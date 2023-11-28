#!/usr/bin/env python

from typing import List

from utils import read_puzzle_data

DAY = 3

TEST_DATA = [
    "vJrwpWtwJgWrhcsFMMfFFhFp",
    "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
    "PmmdzqPrVvPwwTWBwg",
    "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
    "ttgJtRGJQctTZtZT",
    "CrZsJsPPZsGzwwsLwLmpwMDw",
]

PRIORITY = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


def part_1(data: List[str]) -> int:
    total_priority = 0

    for line in data:
        n = len(line) // 2
        compartment_1_items = set(line[:n])
        compartment_2_items = set(line[n:])

        common_items = compartment_1_items & compartment_2_items
        assert len(common_items) == 1

        common_item = list(common_items)[0]
        total_priority += PRIORITY.index(common_item) + 1

    return total_priority


def part_2(data: List[str]) -> int:
    total_priority = 0

    for i in range(0, len(data), 3):
        common_items = set(data[i]) & set(data[i+1]) & set(data[i+2])
        assert len(common_items) == 1

        common_item = list(common_items)[0]
        total_priority += PRIORITY.index(common_item) + 1

    return total_priority


if __name__ == "__main__":
    assert part_1(TEST_DATA) == 157
    assert part_2(TEST_DATA) == 70

    data = read_puzzle_data(DAY)

    total_priority = part_1(data)
    print(f"Part 1: {total_priority}")

    total_priority = part_2(data)
    print(f"Part 2: {total_priority}")
