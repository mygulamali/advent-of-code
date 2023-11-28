package day05

import (
	"fmt"
	"regexp"
	"strconv"
	"strings"

	"gulamali.net/utils"
)

var Day = 5

type Move struct {
	amount int
	from int
	to int
}

func ParseStacks(data []string) [][]string {
	stacks := [][]string {}

	for lineIndx, line := range data {
		if data[lineIndx + 1] == "" {
			break
		}

		// number of stacks specified on the line
		n := (len(line) - 3) / 4 + 1

		// append empty stacks if greater than available stacks
		if n > len(stacks) {
			for i := len(stacks); i < n; i++ {
				stacks = append(stacks, []string {})
			}
		}

		// add crates to the stacks
		for i := 0; i < len(line); i += 4 {
			crate := line[i:i + 3]
			stackIndx := i / 4

			if crate != "   " {
				stacks[stackIndx] = append(stacks[stackIndx], string(crate[1]))
			}
		}
	}

	// reverse stack order
	for k := 0; k < len(stacks); k++ {
		for i, j := 0, len(stacks[k]) - 1; i < j; i, j = i + 1, j - 1 {
			stacks[k][i], stacks[k][j] = stacks[k][j], stacks[k][i]
		}
	}

	return stacks
}

func ParseMoves(data []string) []Move {
	moves := []Move{}
	re := regexp.MustCompile(`move (\d+) from (\d+) to (\d+)`)

	parse := false
	for _, line := range data {
		if line == "" {
			parse = true
			continue
		}

		if parse {
			match := re.FindAllStringSubmatch(line, -1)

			amount, _ := strconv.Atoi(match[0][1])
			from, _ := strconv.Atoi(match[0][2])
			to, _ := strconv.Atoi(match[0][3])

			moves = append(moves, Move{amount, from - 1, to - 1})
		}
	}

	return moves
}

func getTopCrates(stacks [][]string) []string {
	topCrates := []string{}
	for _, stack := range stacks {
		n := len(stack)
		topCrates = append(topCrates, stack[n - 1])
	}
	return topCrates
}

func Part1(data []string) string {
	stacks := ParseStacks(data)
	moves := ParseMoves(data)

	for _, move := range moves {
		n := len(stacks[move.from])

		// add crates to "to" stack
		for i := n - 1; i >= n - move.amount; i-- {
			stacks[move.to] = append(stacks[move.to], stacks[move.from][i])
		}

		// remove crates from "from" stack
		stacks[move.from] = stacks[move.from][:n - move.amount]
	}

	topCrates := getTopCrates(stacks)
	return strings.Join(topCrates, "")
}

func Part2(data []string) string {
	stacks := ParseStacks(data)
	moves := ParseMoves(data)

	for _, move := range moves {
		n := len(stacks[move.from])

		// add crates to "to" stack
		for i := n - move.amount; i < n; i++ {
			stacks[move.to] = append(stacks[move.to], stacks[move.from][i])
		}

		// remove crates from "from" stack
		stacks[move.from] = stacks[move.from][:n - move.amount]
	}

	topCrates := getTopCrates(stacks)
	return strings.Join(topCrates, "")
}

func Main() {
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:", Part2(data))
}
