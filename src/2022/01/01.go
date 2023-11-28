package day01

import (
	"fmt"
	"sort"
	"strconv"

	"gulamali.net/utils"
)

var Day = 1

func Part1(data []string) int {
    totalCalories := 0
    maxCalories := -1

	for _, line := range data {
		if line == "" {
			if totalCalories >= maxCalories {
				maxCalories = totalCalories
			}
			totalCalories = 0
			continue
		}

		calories, _ := strconv.Atoi(line)
		totalCalories += calories
	}

	return maxCalories
}

func Part2(data []string) int {
    groupedCalories := []int {0}
    counter := 0

	for _, line := range data {
		if line == "" {
			counter += 1
			groupedCalories = append(groupedCalories, 0)
			continue
		}

		calories, _ := strconv.Atoi(line)
		groupedCalories[counter] += calories
	}

	sort.Sort(sort.Reverse(sort.IntSlice(groupedCalories)))

	totalCalories := 0
	for i := 0; i < 3; i++ {
		totalCalories += groupedCalories[i]
	}

	return totalCalories
}

func Main() {
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:", Part2(data))
}
