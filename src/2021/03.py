#!/usr/bin/env python

from typing import List, Optional

from utils import read_puzzle_data

DAY = 3

TEST_DATA = [
    "00100",
    "11110",
    "10110",
    "10111",
    "10101",
    "01111",
    "00111",
    "11100",
    "10000",
    "11001",
    "00010",
    "01010",
]


def determine_gamma_rate(report: List[str]) -> str:
    n = len(list(report[0]))

    ones = [0 for i in range(n)]
    zeros = [0 for i in range(n)]
    for line in report:
        for i, bit in enumerate(line):
            if bit == "1":
                ones[i] += 1
            else:
                zeros[i] += 1

    gamma_rate = ["1" if (ones[indx] >= zeros[indx]) else "0" for indx in range(n)]

    return "".join(gamma_rate)


def determine_epsilon_rate(report: List[str], gamma_rate: Optional[str] = None) -> str:
    if gamma_rate is None:
        gamma_rate = determine_gamma_rate(report)

    epsilon_rate = ["0" if bit == "1" else "1" for bit in gamma_rate]

    return "".join(epsilon_rate)


def filter_report(report: List[str], bit: str, indx: int) -> List[str]:
    return [line for line in report if line[indx] == bit]


def part_1(report: List[str]) -> int:
    gamma_rate = determine_gamma_rate(report)
    epsilon_rate = determine_epsilon_rate(report, gamma_rate)

    return int(gamma_rate, 2) * int(epsilon_rate, 2)


def part_2(report: List[int]) -> int:
    filtered_report = [line for line in report]
    indx = 0

    while len(filtered_report) > 1:
        gamma_rate = determine_gamma_rate(filtered_report)
        bit = gamma_rate[indx]
        filtered_report = filter_report(filtered_report, bit, indx)
        indx += 1

    o2_generator_rating = filtered_report[0]

    filtered_report = [line for line in report]
    indx = 0

    while len(filtered_report) > 1:
        epsilon_rate = determine_epsilon_rate(filtered_report)
        bit = epsilon_rate[indx]
        filtered_report = filter_report(filtered_report, bit, indx)
        indx += 1

    co2_scrubber_rating = filtered_report[0]

    return int(o2_generator_rating, 2) * int(co2_scrubber_rating, 2)


if __name__ == "__main__":
    assert part_1(TEST_DATA) == 198
    assert part_2(TEST_DATA) == 230

    report = read_puzzle_data(DAY)

    power_consumption = part_1(report)
    print(f"Part 1: {power_consumption}")

    life_support_rating = part_2(report)
    print(f"Part 2: {life_support_rating}")
