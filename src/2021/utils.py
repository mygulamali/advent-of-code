import pathlib
from typing import List

DATA_DIR = "./data/2021"


def puzzle_data_filename(day: int) -> str:
    return f"{DATA_DIR}/{day:02d}.txt"


def read_puzzle_data(day: int) -> List[str]:
    filename = puzzle_data_filename(day)

    if not pathlib.Path(filename).is_file():
        raise IOError(f"Cannot find puzzle data file: {filename}")

    with open(filename, "r") as fp:
        data = [line.rstrip("\n") for line in fp]

    return data
