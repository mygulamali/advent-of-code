#!/usr/bin/env python

from math import inf
from typing import List

from utils import read_puzzle_data

DAY = 7

TEST_PUZZLE_DATA = [
    "16,1,2,0,4,2,7,1,2,14",
]


def process_puzzle_data(puzzle_data: List[str]):
    return [int(n) for n in puzzle_data[0].split(",")]


def part_1(puzzle_data: List[str]) -> int:
    horizontal_distances = process_puzzle_data(puzzle_data)

    horizontal_distances.sort()
    middle_indx = len(horizontal_distances) // 2 - 1
    median = horizontal_distances[middle_indx]

    total_fuel = 0
    for distance in horizontal_distances:
        total_fuel += abs(distance - median)

    return total_fuel


def part_2(puzzle_data: List[str]) -> int:
    horizontal_distances = process_puzzle_data(puzzle_data)
    horizontal_distances.sort()

    min_total_fuel = inf
    for position in range(horizontal_distances[-1] + 1):
        total_fuel = 0
        for distance in horizontal_distances:
            distance_moved = abs(distance - position)
            total_fuel += distance_moved * (distance_moved + 1) // 2

        min_total_fuel = min(min_total_fuel, total_fuel)

    return min_total_fuel


if __name__ == "__main__":
    assert part_1(TEST_PUZZLE_DATA) == 37
    assert part_2(TEST_PUZZLE_DATA) == 168

    puzzle_input = read_puzzle_data(DAY)

    total_fuel = part_1(puzzle_input)
    print(f"Part 1: {total_fuel}")

    total_fuel = part_2(puzzle_input)
    print(f"Part 2: {total_fuel}")
