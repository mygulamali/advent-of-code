package day10

import (
	"fmt"
	"regexp"
	"strconv"

	"gulamali.net/src/2022/utils"
)

var Day = 10

var re = regexp.MustCompile(`addx (-?\d+)`)

func GetSignalStrength(x int, cycle int) int {
	if cycle == 20 || (cycle > 20 && (cycle - 20) % 40 == 0) {
		return x * cycle
	}

	return 0
}

func DrawPixel(crt []string, x int, cycle int) []string {
	xIndx := x % 40
	lineIndx := x / 40

	if cycle - 1 <= xIndx && xIndx <= cycle + 1 {
		line := []rune(crt[lineIndx])
		line[xIndx] = '#'
		crt[lineIndx] = string(line)
	}

	return crt
}

func Part1(data []string) int {
	totalSignalStrength := 0

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

func Part2(data []string) []string {
	crt := []string{
		"........................................",
		"........................................",
		"........................................",
		"........................................",
		"........................................",
		"........................................",
	}

	x, cycle := 1, 0
	for _, line := range data {
		crt = DrawPixel(crt, cycle, x)
		match := re.FindStringSubmatch(line)

		if len(match) > 0 {
			// addx
			cycle += 1
			crt = DrawPixel(crt, cycle, x)

			v, _ := strconv.Atoi(match[1])
			x += v
		}

		cycle += 1
	}

	return crt
}

func Main() {
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:")
	for _, line := range Part2(data) {
		fmt.Println(line)
	}
}
