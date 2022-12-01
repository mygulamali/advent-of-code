#!/usr/bin/env python

from typing import List, Optional

from utils import read_puzzle_data

DAY = 4

TEST_DATA = [
    "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
    "",
    "22 13 17 11  0",
    " 8  2 23  4 24",
    "21  9 14 16  7",
    " 6 10  3 18  5",
    " 1 12 20 15 19",
    "",
    " 3 15  0  2 22",
    " 9 18 13 17  5",
    "19  8  7 25 23",
    "20 11 10 24  4",
    "14 21 16 12  6",
    "",
    "14 21 17 24  4",
    "10 16 15  9 19",
    "18  8 23 26 20",
    "22 11 13  6  5",
    " 2  0 12  3  7",
]


class Mark:
    def __init__(self, number: str):
        self.number = int(number)
        self.marked = False


class Board:
    N: int = 5

    def __init__(self, lines: List[str]):
        self.last_mark = None
        self.board = [[] for i in range(self.N)]
        for i, line in enumerate(lines):
            self.board[i] = [Mark(number) for number in line.split()]
        self.won = False

    def mark(self, number: int) -> None:
        if self.won:
            return

        for i in range(self.N):
            for j in range(self.N):
                if self.board[i][j].number == number:
                    self.last_mark = number
                    self.board[i][j].marked = True

    def bingo(self) -> bool:
        if self.won:
            return True

        for i in range(self.N):
            row = [self.board[i][j].marked for j in range(self.N)]
            if all(row):
                self.won = True
                return True

        for j in range(self.N):
            column = [self.board[i][j].marked for i in range(self.N)]
            if all(column):
                self.won = True
                return True

        return False

    def sum_of_unmarked(self) -> int:
        accumulator = 0
        for i in range(self.N):
            for j in range(self.N):
                if not self.board[i][j].marked:
                    accumulator += self.board[i][j].number

        return accumulator

    def __str__(self) -> str:
        output = ""
        for i in range(self.N):
            for j in range(self.N):
                if self.board[i][j].marked:
                    output += "    X"
                else:
                    output += f"{self.board[i][j].number:5}"
            output += "\n"

        return output


def process_input(puzzle_input: List[str]) -> (List[int], List[Board]):
    draws = [int(number) for number in puzzle_input[0].split(",")]

    boards = []
    cursor = 2
    while cursor <= len(puzzle_input):
        board = Board(puzzle_input[cursor:cursor+5])
        boards.append(board)
        cursor += 6

    return (draws, boards)


def part_1(puzzle_input: List[str]) -> int:
    draws, boards = process_input(puzzle_input)
    winning_board = None

    indx = 0
    while indx < len(draws) and winning_board is None:
        draw = draws[indx]
        for i, board in enumerate(boards):
            board.mark(draw)
            if board.bingo():
                winning_board = boards[i]
        indx += 1

    return winning_board.last_mark * winning_board.sum_of_unmarked()


def part_2(puzzle_input: List[str]) -> int:
    draws, boards = process_input(puzzle_input)
    winning_boards = []

    for draw in draws:
        for board in boards:
            if not board.won:
                board.mark(draw)
                if board.bingo():
                    winning_boards.append(board)

    last_winning_board = winning_boards[-1]
    return last_winning_board.last_mark * last_winning_board.sum_of_unmarked()


if __name__ == "__main__":
    assert part_1(TEST_DATA) == 4512
    assert part_2(TEST_DATA) == 1924

    puzzle_input = read_puzzle_data(DAY)

    score = part_1(puzzle_input)
    print(f"Part 1: {score}")

    score = part_2(puzzle_input)
    print(f"Part 2: {score}")
