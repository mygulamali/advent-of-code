#!/usr/bin/env python

from typing import List

from utils import read_puzzle_data

DAY = 2

TEST_DATA = [
    "forward 5",
    "down 5",
    "forward 8",
    "up 3",
    "down 8",
    "forward 2",
]


def part_1(commands: List[str]) -> int:
    horizontal = 0
    depth = 0

    for command in commands:
        direction, value = command.split()
        if direction == "forward":
            horizontal += int(value)
        elif direction == "up":
            depth -= int(value)
        elif direction == "down":
            depth += int(value)
        else:
            raise ValueError(f"Unknown direction: {direction}")

    return horizontal * depth


def part_2(commands: List[str]) -> int:
    aim = 0
    horizontal = 0
    depth = 0

    for command in commands:
        direction, value = command.split()
        if direction == "up":
            aim -= int(value)
        elif direction == "down":
            aim += int(value)
        elif direction == "forward":
            horizontal += int(value)
            depth += aim * int(value)
        else:
            raise ValueError(f"Unknown direction: {direction}")

    return horizontal * depth


if __name__ == "__main__":
    assert part_1(TEST_DATA) == 150
    assert part_2(TEST_DATA) == 900

    commands = read_puzzle_data(DAY)

    multiplied_positions = part_1(commands)
    print(f"Part 1: {multiplied_positions}")

    multiplied_positions = part_2(commands)
    print(f"Part 2: {multiplied_positions}")
