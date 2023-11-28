package day23

import (
	"fmt"

	"gulamali.net/utils"
)

var Day = 23

func ParseData(data []string) Grid {
	grid := Grid{elves: []Elf{}}

	for y, line := range data {
		for x, char := range line {
			if char == rune('#') {
				elf := Elf{
					x: x,
					y: y,
					xNew: x,
					yNew: y,
					proposed: false,
				}
				grid.elves = append(grid.elves, elf)
			}
		}
	}

	return grid
}

func Part1(data []string) int {
	grid := ParseData(data)

	for round := 0; round < 10; round++ {
		grid.Update(round)
	}

	return grid.EmptyGround()
}

func Part2(data []string) int {
	grid := ParseData(data)
	rounds := 0

	for true {
		if !grid.RequiresUpdate() {
			break
		}

		grid.Update(rounds)
		rounds++
	}

	return rounds + 1
}

func Main() {
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:", Part2(data))
}
