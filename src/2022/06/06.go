package day06

import (
	"fmt"

	"gulamali.net/src/2022/utils"
)

var DAY = 6

func findMarker(data string, width int) int {
	for i := 0; i < len(data) - width; i++ {
		char_map := map[string]int{}

		for j := 0; j < width; j++ {
			char := string(data[i + j])
			_, exists := char_map[char]

			if exists {
				char_map[char] += 1
			} else {
				char_map[char] = 1
			}
		}

		if len(char_map) == width {
			return i + width
		}
	}
	return -1
}

func Part1(data string) int {
	return findMarker(data, 4)
}

func Part2(data string) int {
	return findMarker(data, 14)
}

func Main() {
	data := utils.ReadPuzzleData(DAY)

	fmt.Println("Day", DAY)
	fmt.Println("Part 1:", Part1(data[0]))
	fmt.Println("Part 2:", Part2(data[0]))
}
