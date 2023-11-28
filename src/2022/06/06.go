package day06

import (
	"fmt"

	"gulamali.net/utils"
)

var Day = 6

func findMarker(data string, width int) int {
	for i := 0; i < len(data) - width; i++ {
		charMap := map[string]int{}

		for j := 0; j < width; j++ {
			char := string(data[i + j])
			_, exists := charMap[char]

			if exists {
				charMap[char] += 1
			} else {
				charMap[char] = 1
			}
		}

		if len(charMap) == width {
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
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data[0]))
	fmt.Println("Part 2:", Part2(data[0]))
}
