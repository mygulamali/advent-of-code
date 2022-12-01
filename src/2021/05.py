#!/usr/bin/env python

from dataclasses import dataclass
import re
from typing import List

from utils import read_puzzle_data

DAY = 5

TEST_PUZZLE_INPUT = [
    "0,9 -> 5,9",
    "8,0 -> 0,8",
    "9,4 -> 3,4",
    "2,2 -> 2,1",
    "7,0 -> 7,4",
    "6,4 -> 2,0",
    "0,9 -> 2,9",
    "3,4 -> 1,4",
    "0,0 -> 8,8",
    "5,5 -> 8,2",
]

INPUT_LINE_RE = re.compile(r"(\d+),(\d+) -> (\d+),(\d+)")


@dataclass
class Point:
    x: int
    y: int


@dataclass
class Line:
    start: Point
    end: Point

    def horizontal(self) -> bool:
        return self.start.y == self.end.y

    def vertical(self) -> bool:
        return self.start.x == self.end.x

    def diagonal(self) -> bool:
        return abs(self.end.x - self.start.x) == abs(self.end.y - self.start.y)

    def diagonal_points(self) -> List[Point]:
        length = abs(self.end.x - self.start.x)
        points = []

        for i in range(length + 1):
            if (self.start.x < self.end.x) and (self.start.y < self.end.y):
                point = Point(self.start.x + i, self.start.y + i)
            elif (self.start.x > self.end.x) and (self.start.y < self.end.y):
                point = Point(self.start.x - i, self.start.y + i)
            elif (self.start.x < self.end.x) and (self.start.y > self.end.y):
                point = Point(self.start.x + i, self.start.y - i)
            elif (self.start.x > self.end.x) and (self.start.y > self.end.y):
                point = Point(self.start.x - i, self.start.y - i)
            else:
                raise ValueError("Line is not diagonal")
            points.append(point)

        return points


class Map:
    def __init__(self, lines: List[Line]):
        self.limit = self.determine_limit(lines)
        self.grid = self.create_grid(lines)

    def determine_limit(self, lines: List[Line]) -> Point:
        limit = Point(0, 0)

        for line in lines:
            limit.x = max([limit.x, line.start.x, line.end.x])
            limit.y = max([limit.y, line.start.y, line.end.y])

        limit.x += 1
        limit.y += 1

        return limit

    def create_grid(self, lines: List[Line]) -> List[List[int]]:
        grid = []

        for y in range(self.limit.y):
            row = [0 for x in range(self.limit.x)]
            grid.append(row)

        return grid

    def add_horizontal_lines(self, lines: List[Line]) -> None:
        for line in lines:
            if line.horizontal():
                y = line.start.y
                start, end = (
                    (line.start, line.end) if line.start.x < line.end.x else (line.end, line.start)
                )

                for x in range(start.x, end.x + 1):
                    self.grid[y][x] += 1

    def add_vertical_lines(self, lines: List[Line]) -> None:
        for line in lines:
            if line.vertical():
                x = line.start.x
                start, end = (
                    (line.start, line.end) if line.start.y < line.end.y else (line.end, line.start)
                )

                for y in range(start.y, end.y + 1):
                    self.grid[y][x] += 1


    def add_diagonal_lines(self, lines: List[Line]) -> None:
       for line in lines:
            if line.diagonal():
                for point in line.diagonal_points():
                    self.grid[point.y][point.x] += 1


    def count_overlaps(self) -> int:
        accumulator = 0

        for y in range(self.limit.y):
            for x in range(self.limit.x):
                if self.grid[y][x] > 1:
                    accumulator += 1

        return accumulator

    def __str__(self) -> str:
        output = ""

        for y in range(self.limit.y):
            row = [
                "." if self.grid[y][x] == 0 else str(self.grid[y][x])
                for x in range(self.limit.x)
            ]
            output += "".join(row) + "\n"

        return output


def process_input(puzzle_input: List[str]) -> List[Line]:
    lines = []

    for line in puzzle_input:
        matches = INPUT_LINE_RE.match(line)
        start = Point(
            int(matches.group(1)),
            int(matches.group(2)),
        )
        end = Point(
            int(matches.group(3)),
            int(matches.group(4)),
        )
        lines.append(Line(start, end))

    return lines


def part_1(puzzle_input: List[str]) -> int:
    lines = process_input(puzzle_input)
    map = Map(lines)

    map.add_horizontal_lines(lines)
    map.add_vertical_lines(lines)

    return map.count_overlaps()


def part_2(puzzle_input: List[str]) -> int:
    lines = process_input(puzzle_input)
    map = Map(lines)

    map.add_horizontal_lines(lines)
    map.add_vertical_lines(lines)
    map.add_diagonal_lines(lines)

    return map.count_overlaps()


if __name__ == "__main__":
    assert part_1(TEST_PUZZLE_INPUT) == 5
    assert part_2(TEST_PUZZLE_INPUT) == 12

    puzzle_input = read_puzzle_data(DAY)

    overlaps = part_1(puzzle_input)
    print(f"Part 1: {overlaps}")

    overlaps = part_2(puzzle_input)
    print(f"Part 2: {overlaps}")
