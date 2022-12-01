#!/usr/bin/env python

from typing import List

from utils import read_puzzle_data

DAY = 1

TEST_DATA = [
    199,
    200,
    208,
    210,
    200,
    207,
    240,
    269,
    260,
    263,
]


def part_1(depths: List[int]) -> int:
    counter = 0

    for i in range(1, len(depths)):
        if (depths[i] - depths[i - 1]) > 0:
            counter += 1

    return counter


def part_2(depths: List[int]) -> int:
    windowed_depths = [
        depths[i - 2] + depths[i - 1] + depths[i]
        for i in range(2, len(depths))
    ]
    counter = part_1(windowed_depths)

    return counter


if __name__ == "__main__":
    assert part_1(TEST_DATA) == 7
    assert part_2(TEST_DATA) == 5

    data = read_puzzle_data(DAY)
    depths = [int(datum) for datum in data]

    n_increasing_depths = part_1(depths)
    print(f"Part 1: {n_increasing_depths}")

    n_increasing_depths = part_2(depths)
    print(f"Part 2: {n_increasing_depths}")
