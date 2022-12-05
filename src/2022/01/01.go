package day01

import (
	"fmt"
	"sort"
	"strconv"

	"gulamali.net/src/2022/utils"
)

var DAY = 1

func Part1(data []string) int {
    total_calories := 0
    max_calories := -1

	for _, line := range data {
		if line == "" {
			if total_calories >= max_calories {
				max_calories = total_calories
			}
			total_calories = 0
			continue
		}

		calories, _ := strconv.Atoi(line)
		total_calories += calories
	}

	return max_calories
}

func Part2(data []string) int {
    grouped_calories := []int {0}
    counter := 0

	for _, line := range data {
		if line == "" {
			counter += 1
			grouped_calories = append(grouped_calories, 0)
			continue
		}

		calories, _ := strconv.Atoi(line)
		grouped_calories[counter] += calories
	}

	sort.Sort(sort.Reverse(sort.IntSlice(grouped_calories)))

	total_calories := 0
	for i := 0; i < 3; i++ {
		total_calories += grouped_calories[i]
	}

	return total_calories
}

func Main() {
	data := utils.ReadPuzzleData(DAY)

	fmt.Println("Day", DAY)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:", Part2(data))
}
