package day10

import (
	"fmt"
	"regexp"
	"strconv"

	"gulamali.net/src/2022/utils"
)

var Day = 10

func GetSignalStrength(x int, cycle int) int {
	if cycle == 20 || (cycle > 20 && (cycle - 20) % 40 == 0) {
		return x * cycle
	}

	return 0
}

func Part1(data []string) int {
	totalSignalStrength := 0
	re := regexp.MustCompile(`addx (-?\d+)`)

	x, cycle := 1, 1
	for _, line := range data {
		match := re.FindStringSubmatch(line)

		if len(match) > 0 {
			// addx
			cycle += 1
			totalSignalStrength += GetSignalStrength(x, cycle)

			v, _ := strconv.Atoi(match[1])
			x += v
		}

		cycle += 1
		totalSignalStrength += GetSignalStrength(x, cycle)
	}

	return totalSignalStrength
}

func Part2(data []string) int {
	return 0
}

func Main() {
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:", Part2(data))
}
