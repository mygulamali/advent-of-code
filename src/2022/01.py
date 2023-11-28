#!/usr/bin/env python

from typing import List

from utils import read_puzzle_data

DAY = 1

TEST_DATA = [
    "1000",
    "2000",
    "3000",
    "",
    "4000",
    "",
    "5000",
    "6000",
    "",
    "7000",
    "8000",
    "9000",
    "",
    "10000",
]


def part_1(data: List[str]) -> int:
    total_calories = 0
    max_calories = -1

    for line in data:
        if line == "":
            if total_calories >= max_calories:
                max_calories = total_calories
            total_calories = 0
            continue

        total_calories += int(line)

    return max_calories


def part_2(data: List[str]) -> int:
    calories = [0]
    counter = 0

    for line in data:
        if line == "":
            counter += 1
            calories.append(0)
            continue

        calories[counter] += int(line)

    sorted_calories = sorted(calories, reverse=True)
    return sum(sorted_calories[:3])


if __name__ == "__main__":
    assert part_1(TEST_DATA) == 24000
    assert part_2(TEST_DATA) == 45000

    data = read_puzzle_data(DAY)

    max_calories = part_1(data)
    print(f"Part 1: {max_calories}")

    summed_max_calories = part_2(data)
    print(f"Part 2: {summed_max_calories}")
