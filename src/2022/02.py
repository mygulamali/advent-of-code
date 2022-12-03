#!/usr/bin/env python

from typing import List

from utils import read_puzzle_data

DAY = 2

TEST_DATA = [
    "A Y",
    "B X",
    "C Z",
]

WINNING_SCORE_MATRIX = [
    # X  Y  Z
    [ 3, 6, 0], # A
    [ 0, 3, 6], # B
    [ 6, 0, 3], # C
]

SELECTION_SCORE_MATRIX = [
    # lose draw  win
    [    3,   1,   2], # A
    [    1,   2,   3], # B
    [    2,   3,   1], # C
]


def part_1(data: List[str]) -> int:
    total_score = 0

    for line in data:
        opponent_play_index = "ABC".index(line[0])
        my_play_index = "XYZ".index(line[2])

        selection_score = my_play_index + 1
        round_score = WINNING_SCORE_MATRIX[opponent_play_index][my_play_index]
        total_score += selection_score + round_score

    return total_score


def part_2(data: List[str]) -> int:
    total_score = 0

    for line in data:
        opponent_play_index = "ABC".index(line[0])
        my_strategy_index = "XYZ".index(line[2])

        selection_score = SELECTION_SCORE_MATRIX[opponent_play_index][my_strategy_index]
        round_score = 3 * my_strategy_index
        total_score += selection_score + round_score

    return total_score


if __name__ == "__main__":
    assert part_1(TEST_DATA) == 15
    assert part_2(TEST_DATA) == 12

    data = read_puzzle_data(DAY)

    total_score = part_1(data)
    print(f"Part 1: {total_score}")

    total_score = part_2(data)
    print(f"Part 2: {total_score}")
