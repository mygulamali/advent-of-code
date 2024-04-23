#!/usr/bin/env python

import copy

FILENAME = "../../data/2023/11.txt"


class Galaxy:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def distance(self, galaxy: "Galaxy") -> int:
        return abs(self.x - galaxy.x) + abs(self.y - galaxy.y)


class Universe:
    def __init__(self, data: list[str]):
        self.galaxies = []
        self.height = len(data)
        self.width = len(data[0])

        for y, line in enumerate(data):
            for x, char in enumerate(line):
                if char == "#":
                    self.galaxies.append(Galaxy(x, y))

    def expand(self, amount: int = 2) -> None:
        x_voids = set(range(self.width))
        y_voids = set(range(self.height))

        for g in self.galaxies:
            x_voids.discard(g.x)
            y_voids.discard(g.y)

        new_galaxies = copy.deepcopy(self.galaxies)
        new_width = self.width
        new_height = self.height
        expansion = amount - 1

        for i, galaxy in enumerate(self.galaxies):
            for x in x_voids:
                if galaxy.x > x:
                    new_galaxies[i].x += expansion
                    new_width = max(new_width, new_galaxies[i].x)

            for y in y_voids:
                if galaxy.y > y:
                    new_galaxies[i].y += expansion
                    new_height = max(new_height, new_galaxies[i].y)

        self.galaxies = copy.deepcopy(new_galaxies)
        self.width = new_width
        self.height = new_height

    def __repr__(self) -> str:
        u = []
        for y in range(self.height):
            u.append([])
            for x in range(self.width):
                u[y].append(".")
            u.append("\n")
        u.append("\n")

        for g in self.galaxies:
            u[g.y][g.x] = "#"

        return "".join(
            [u[y][x] for x in range(self.height) for y in range(self.width)]
        )


def part_1(data: list[str]) -> int:
    return part_2(data, 2)


def part_2(data: list[str], amount: int) -> int:
    universe = Universe(data)
    universe.expand(amount)

    total_distance = 0
    n = len(universe.galaxies)
    for i in range(n):
        for j in range(i + 1, n):
            distance = universe.galaxies[i].distance(universe.galaxies[j])
            total_distance += distance

    return total_distance



if __name__ == "__main__":
    test_data = [
        "...#......",
        ".......#..",
        "#.........",
        "..........",
        "......#...",
        ".#........",
        ".........#",
        "..........",
        ".......#..",
        "#...#.....",
    ]

    total_distance = part_1(test_data)
    assert total_distance == 374

    total_distance = part_2(test_data, 100)
    assert total_distance == 8410

    with open(FILENAME, "r") as f:
        data = [line.rstrip("\n") for line in f]

    print(f"Part 1: {part_1(data)}")
    print(f"Part 2: {part_2(data, 1000000)}")
