#!/usr/bin/env python

from typing import List, Tuple

from utils import read_puzzle_data

DAY = 9

TEST_PUZZLE_DATA = [
    "2199943210",
    "3987894921",
    "9856789892",
    "8767896789",
    "9899965678",
]


class PuzzleMap:
    def __init__(self, puzzle_data: List[str]):
        self.puzzle_map, self.width, self.height = self.build_map(puzzle_data)

    @staticmethod
    def build_map(puzzle_data: List[str]) -> Tuple[List[List[int]], int, int]:
        width = len(puzzle_data[0])
        height = len(puzzle_data)

        puzzle_map = [[] for i in range(height)]
        for i in range(height):
            for j in range(width):
                puzzle_map[i].append(int(puzzle_data[i][j]))

        return (puzzle_map, width, height)

    def low_points(self) -> List[int]:
        points = []

        for i in range(self.height):
            for j in range(self.width):
                if self.lowest_point(i, j):
                    points.append(self.puzzle_map[i][j])

        return points

    def lowest_point(self, i: int, j: int) -> bool:
        sorted_adjacent_heights = self.sorted_adjacent_heights(i, j)
        if self.puzzle_map[i][j] < sorted_adjacent_heights[0]:
            return True
        return False

    def sorted_adjacent_heights(self, i: int, j: int) -> List[int]:
        if (i == 0) and (j == 0):
            adjacent_heights = [
                self.puzzle_map[i][j + 1],
                self.puzzle_map[i + 1][j],
            ]
        elif (i == 0) and (j == self.width - 1):
            adjacent_heights = [
                self.puzzle_map[i][j - 1],
                self.puzzle_map[i + 1][j],
            ]
        elif (i == self.height - 1) and (j == 0):
            adjacent_heights = [
                self.puzzle_map[i][j + 1],
                self.puzzle_map[i - 1][j],
            ]
        elif (i == self.height - 1) and (j == self.width - 1):
            adjacent_heights = [
                self.puzzle_map[i][j - 1],
                self.puzzle_map[i - 1][j],
            ]
        elif (i == 0) and (0 < j < self.width - 1):
            adjacent_heights = [
                self.puzzle_map[i + 1][j],
                self.puzzle_map[i][j - 1],
                self.puzzle_map[i][j + 1],
            ]
        elif (i == self.height - 1) and (0 < j < self.width - 1):
            adjacent_heights = [
                self.puzzle_map[i - 1][j],
                self.puzzle_map[i][j - 1],
                self.puzzle_map[i][j + 1],
            ]
        elif (0 < i < self.height - 1) and (j == 0):
            adjacent_heights = [
                self.puzzle_map[i][j + 1],
                self.puzzle_map[i - 1][j],
                self.puzzle_map[i + 1][j],
            ]
        elif (0 < i < self.height - 1) and (j == self.width - 1):
            adjacent_heights = [
                self.puzzle_map[i][j - 1],
                self.puzzle_map[i - 1][j],
                self.puzzle_map[i + 1][j],
            ]
        elif (0 < i < self.height - 1) and (0 < j < self.width - 1):
            adjacent_heights = [
                self.puzzle_map[i + 1][j],
                self.puzzle_map[i - 1][j],
                self.puzzle_map[i][j - 1],
                self.puzzle_map[i][j + 1],
            ]
        else:
            raise ValueError("Point outside boundary")

        return sorted(adjacent_heights)


def part_1(puzzle_data: List[str]) -> int:
    puzzle_map = PuzzleMap(puzzle_data)

    low_points = puzzle_map.low_points()
    risk = sum(low_points) + len(low_points)

    return risk


def part_2(puzzle_data: List[str]) -> int:
    puzzle_map = PuzzleMap(puzzle_data)

    return 0


if __name__ == "__main__":
    assert part_1(TEST_PUZZLE_DATA) == 15
    assert part_2(TEST_PUZZLE_DATA) == 1134

    puzzle_input = read_puzzle_data(DAY)

    risk = part_1(puzzle_input)
    print(f"Part 1: {risk}")

    # total = part_2(puzzle_input)
    # print(f"Part 2: {total}")
