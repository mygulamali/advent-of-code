#!/usr/bin/env python

from typing import List

from utils import read_puzzle_data

DAY = 6

TEST_PUZZLE_DATA = [
    "3,4,3,1,2",
]

TOTAL_DAYS = 80


def process_puzzle_data(puzzle_data: List[str]):
    return [int(n) for n in puzzle_data[0].split(",")]


def part_1(puzzle_data: List[str], total_days: int) -> int:
    fishes = process_puzzle_data(puzzle_data)

    day = 0
    while day < total_days:
        new_fishes = 0
        for i in range(len(fishes)):
            if fishes[i] == 0:
                fishes[i] = 6
                new_fishes += 1
            else:
                fishes[i] -= 1

        fishes += [8 for j in range(new_fishes)]
        day += 1

    return len(fishes)


def part_2(puzzle_data: List[str], total_days: int) -> int:
    fishes = process_puzzle_data(puzzle_data)

    table = [0 for i in range(9)]
    for fish in fishes:
        table[fish] += 1

    for day in range(total_days):
        n_zeros = table[0]
        for i in range(8):
            table[i] = table[i + 1]
        table[6] += n_zeros
        table[8] = n_zeros

    return sum(table)


if __name__ == "__main__":
    assert part_1(TEST_PUZZLE_DATA, 18) == 26
    assert part_1(TEST_PUZZLE_DATA, 80) == 5934
    assert part_2(TEST_PUZZLE_DATA, 18) == 26
    assert part_2(TEST_PUZZLE_DATA, 80) == 5934
    assert part_2(TEST_PUZZLE_DATA, 256) == 26984457539

    puzzle_input = read_puzzle_data(DAY)

    fishes = part_1(puzzle_input, 80)
    print(f"Part 1: {fishes}")

    fishes = part_2(puzzle_input, 256)
    print(f"Part 2: {fishes}")
