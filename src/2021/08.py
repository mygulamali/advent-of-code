#!/usr/bin/env python

from typing import List, Set, Tuple, Union

from utils import read_puzzle_data

DAY = 8

TEST_PUZZLE_DATA = [
    "be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe",
    "edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc",
    "fgaebd cg bdaec gdafb agbcfd gdcbef bgcad gfac gcb cdgabef | cg cg fdcagb cbg",
    "fbegcd cbd adcefb dageb afcb bc aefdc ecdab fgdeca fcdbega | efabcd cedba gadfec cb",
    "aecbfdg fbg gf bafeg dbefa fcge gcbea fcaegb dgceab fcbdga | gecf egdcabf bgf bfgea",
    "fgeab ca afcebg bdacfeg cfaedg gcfdb baec bfadeg bafgc acf | gebdcfa ecba ca fadegcb",
    "dbcfg fgd bdegcaf fgec aegbdf ecdfab fbedc dacgb gdcebf gf | cefg dcbef fcge gbcadfe",
    "bdfegc cbegaf gecbf dfcage bdacg ed bedf ced adcbefg gebcd | ed bcgafe cdgba cbgef",
    "egadfb cdbfeg cegd fecab cgb gbdefca cg fgcdab egfdb bfceg | gbdfcae bgc cg cgb",
    "gcafb gcf dcaebfg ecagb gf abcdeg gaef cafbge fdbac fegbdc | fgae cfgab fg bagce",
]


def part_1(puzzle_data: List[str]) -> int:
    digits_list, values_list = process_puzzle_data(puzzle_data)

    accumulator = 0
    for values in values_list:
        for number in values:
            if len(number) in [2, 3, 4, 7]:
                accumulator += 1

    return accumulator


def part_2(puzzle_data: List[str]) -> int:
    digits_list, values_list = process_puzzle_data(puzzle_data)

    accumulator = 0
    for digits, values in zip(digits_list, values_list):
        number = determine_output_number(digits, values)
        accumulator += number

    return accumulator


def process_puzzle_data(puzzle_data: List[str]) -> Tuple[List[List[str]], List[List[str]]]:
    digits_list = []
    values_list = []

    for line in puzzle_data:
        left, right = line.split(" | ")
        digits_list.append(left.split())
        values_list.append(right.split())

    return (digits_list, values_list)


def determine_output_number(digits: List[str], values: List[str]) -> int:
    numbers = [set() for i in range(10)]
    segment_map = dict((letter, None) for letter in "abcdefg")

    # determine "easy" numbers
    for digit in digits:
        if len(digit) == 2:
            numbers[1] = set(digit)
        elif len(digit) == 4:
            numbers[4] = set(digit)
        elif len(digit) == 3:
            numbers[7] = set(digit)
        elif len(digit) == 7:
            numbers[8] = set(digit)
    segment_map["a"] = min(numbers[7] - numbers[1])

    # find "9"
    set_abcdf = numbers[7].union(numbers[4])
    for digit in digits:
        if len(digit) == 6 and set_abcdf <= set(digit):
            numbers[9] = set(digit)
            segment_map["g"] = min(numbers[9] - set_abcdf)
    segment_map["e"] = min(numbers[8] - numbers[9])

    # find "3"
    set_acfg = numbers[7].union(set(segment_map["g"]))
    for digit in digits:
        if len(digit) == 5 and set_acfg <= set(digit):
            numbers[3] = set(digit)
            segment_map["d"] = min(numbers[3] - set_acfg)
    segment_map["b"] = min(numbers[4] - numbers[1] - set(segment_map["g"]))

    # find "2"
    set_adeg = set([segment_map["a"], segment_map["d"], segment_map["e"], segment_map["g"]])
    for digit in digits:
        if len(digit) == 5 and set_adeg <= set(digit):
            numbers[2] = set(digit)
            segment_map["c"] = min(numbers[2] - set_adeg)
    segment_map["f"] = min(numbers[1] - set(segment_map["c"]))

    # determine remaining numbers
    numbers[0] = numbers[8] - set(segment_map["d"])
    numbers[6] = numbers[8] - set(segment_map["c"])
    numbers[5] = numbers[6] - set(segment_map["e"])

    number_map = dict((number_map_key(number), str(i)) for i, number in enumerate(numbers))
    number_str = ""
    for value in values:
        number_str += number_map[number_map_key(value)]

    return int(number_str)


def number_map_key(item: Union[List[Set[str]], str]) -> str:
    return "".join(sorted(list(item)))


if __name__ == "__main__":
    assert part_1(TEST_PUZZLE_DATA) == 26
    assert part_2(TEST_PUZZLE_DATA) == 61229

    puzzle_input = read_puzzle_data(DAY)

    n_numbers = part_1(puzzle_input)
    print(f"Part 1: {n_numbers}")

    total = part_2(puzzle_input)
    print(f"Part 2: {total}")
