package day08

import (
	"fmt"
	"strconv"

	"gulamali.net/utils"
)

var Day = 8

func height(data []string, row int, col int) int {
	strValue := string(data[row][col])
	intValue, _ := strconv.Atoi(strValue)
	return intValue
}

func Part1(data []string) int {
	rows := len(data)
	cols := len(data[0])

	visible := 0
	for row := 1; row < rows - 1; row++ {
		for col := 1; col < cols - 1; col++ {
			thisTree := height(data, row, col)

			// visible from top
			top := true
			for i := 0; i < row; i++ {
				if height(data, i, col) >= thisTree {
					top = false
					break
				}
			}

			// visible from bottom
			bottom := true
			for i := row + 1; i < rows; i++ {
				if height(data, i, col) >= thisTree {
					bottom = false
					break
				}
			}

			// visible from left
			left := true
			for i := 0; i < col; i++ {
				if height(data, row, i) >= thisTree {
					left = false
					break
				}
			}

			// visible from right
			right := true
			for i := col + 1; i < cols; i++ {
				if height(data, row, i) >= thisTree {
					right = false
					break
				}
			}

			if (top || bottom || left || right) {
				visible += 1
			}
		}
	}

	return 2 * (rows + cols - 2) + visible
}

func Part2(data []string) int {
	rows := len(data)
	cols := len(data[0])

	bestScore := 0
	for row := 1; row < rows - 1; row++ {
		for col := 1; col < cols - 1; col++ {
			thisTree := height(data, row, col)

			// scene to top
			top := 0
			for i := row - 1; i >= 0; i-- {
				top += 1
				if height(data, i, col) >= thisTree {
					break
				}
			}

			// scene to bottom
			bottom := 0
			for i := row + 1; i < rows; i++ {
				bottom += 1
				if height(data, i, col) >= thisTree {
					break
				}
			}

			// scene to left
			left := 0
			for i := col - 1; i >= 0; i-- {
				left += 1
				if height(data, row, i) >= thisTree {
					break
				}
			}

			// scene to right
			right := 0
			for i := col + 1; i < cols; i++ {
				right += 1
				if height(data, row, i) >= thisTree {
					break
				}
			}

			score := top * bottom * left * right
			if score > bestScore {
				bestScore = score
			}
		}
	}

	return bestScore
}

func Main() {
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:", Part2(data))
}
