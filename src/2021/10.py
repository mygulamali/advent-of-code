#!/usr/bin/env python

from typing import List, Optional

from utils import read_puzzle_data

DAY = 10

TEST_PUZZLE_DATA = [
    "[({(<(())[]>[[{[]{<()<>>",
    "[(()[<>])]({[<{<<[]>>(",
    "{([(<{}[<>[]}>{[]{[(<()>",
    "(((({<>}<{<{<>}{[]{[]{}",
    "[[<[([]))<([[{}[[()]]]",
    "[{[{({}]{}}([{[{{{}}([]",
    "{<[[]]>}<{[{[{[]{()[[[]",
    "[<(<(<(<{}))><([]([]()",
    "<{([([[(<>()){}]>(<<{{",
    "<{([{{}}[<[[[<>{}]]]>[]]",
]

BRACKET_MAP = {
    ")": "(",
    "]": "[",
    "}": "{",
    ">": "<",
}

INVERSE_BRACKET_MAP = {
    "(": ")",
    "[": "]",
    "{": "}",
    "<": ">",
}

ILLEGAL_BRACKET_SCORE_MAP = {
    ")": 3,
    "]": 57,
    "}": 1197,
    ">": 25137,
}

AUTOCOMPLETE_BRACKET_SCORE_MAP = {
    ")": 1,
    "]": 2,
    "}": 3,
    ">": 4,
}


def part_1(puzzle_input: List[str]) -> int:
    accumulator = 0

    for line in puzzle_input:
        accumulator += syntax_error_score(line)

    return accumulator


def part_2(puzzle_input: List[str]) -> int:
    scores = []

    for line in puzzle_input:
        brackets = determine_completion_brackets(line)
        if brackets is not None:
            scores.append(completion_brackets_score(brackets))

    middle_indx = len(scores) // 2
    middle_score = sorted(scores)[middle_indx]

    return middle_score


def syntax_error_score(line: str) -> int:
    stack = []

    for bracket in line:
        if bracket in "([{<":
            stack.append(bracket)
        elif BRACKET_MAP[bracket] == stack[-1]:
            stack.pop()
        else:
            return ILLEGAL_BRACKET_SCORE_MAP[bracket]

    return 0


def determine_completion_brackets(line: str) -> Optional[List[str]]:
    stack = []

    for bracket in line:
        if bracket in "([{<":
            stack.append(bracket)
        elif BRACKET_MAP[bracket] == stack[-1]:
            stack.pop()
        else:
            return None

    return [INVERSE_BRACKET_MAP[bracket] for bracket in reversed(stack)]


def completion_brackets_score(completion_brackets: List[str]) -> int:
    score = 0

    for bracket in completion_brackets:
        score = 5 * score + AUTOCOMPLETE_BRACKET_SCORE_MAP[bracket]

    return score


if __name__ == "__main__":
    assert part_1(TEST_PUZZLE_DATA) == 26397
    assert part_2(TEST_PUZZLE_DATA) == 288957

    puzzle_input = read_puzzle_data(DAY)

    score = part_1(puzzle_input)
    print(f"Part 1: {score}")

    score = part_2(puzzle_input)
    print(f"Part 2: {score}")
