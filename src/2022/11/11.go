package day11

import (
	"fmt"
	"regexp"
	"sort"
	"strconv"
	"strings"

	"gulamali.net/src/2022/utils"
)

var Day = 11

var reItems = regexp.MustCompile(`(\d+),?`)
var reOperation = regexp.MustCompile(`Operation: new = (.+)`)
var reTest = regexp.MustCompile(`Test: divisible by (\d+)`)
var reBranch = regexp.MustCompile(`If (true|false): throw to monkey (\d+)`)

type Monkey struct {
	items []int
	operation []string
	test int
	truthy int
	falsey int
	inspections int
}

func (self *Monkey) TestWorryLevel(indx int) (int, int) {
	worryLevel := self.CalculateWorryLevel(indx)
	if worryLevel % self.test == 0 {
		return self.truthy, worryLevel
	}
	return  self.falsey, worryLevel
}

func (self *Monkey) CalculateWorryLevel(indx int) int {
	old := self.items[indx]

	// process left-hand-side of operation
	left, err := strconv.Atoi(self.operation[0])
	if err != nil {
		left = old
	}

	// process right-hand-side of operation
	right, err := strconv.Atoi(self.operation[2])
	if err != nil {
		right = old
	}

	// calculate new worry level
	var new int
	if self.operation[1] == "+" {
		new = left + right
	} else if self.operation[1] == "*" {
		new = left * right
	}

	return new / 3
}

func ParseItems(data string) []int {
	items := []int{}

	match := reItems.FindAllStringSubmatch(data, -1)
	for i := 0; i < len(match); i++ {
		v, _ := strconv.Atoi(match[i][1])
		items = append(items, v)
	}

	return items
}

func ParseOperation(data string) []string {
	match := reOperation.FindStringSubmatch(data)
	return strings.Split(match[1], " ")
}

func ParseTest(data string) int {
	match := reTest.FindStringSubmatch(data)
	v, _ := strconv.Atoi(match[1])
	return v
}

func ParseBranch(data string) int {
	match := reBranch.FindStringSubmatch(data)
	v, _ := strconv.Atoi(match[2])
	return v
}

func ParseData(data []string) []Monkey {
	monkeys := []Monkey{}

	for i := 0; i < len(data); i += 7 {
		items := ParseItems(data[i + 1])
		operation := ParseOperation(data[i + 2])
		test := ParseTest(data[i + 3])
		truthy := ParseBranch(data[i + 4])
		falsey := ParseBranch(data[i + 5])

		monkey := Monkey{items, operation, test, truthy, falsey, 0}
		monkeys = append(monkeys, monkey)
	}

	return monkeys
}

func Part1(data []string) int {
	monkeys := ParseData(data)
	rounds := 20

	// loop over rounds
	for i := 0; i < rounds; i++ {
		// loop over monkeys
		for j := 0; j < len(monkeys); j++ {
			// loop over items taken by each monkey
			for k := 0; k < len(monkeys[j].items); k++ {
				indx, worryLevel := monkeys[j].TestWorryLevel(k)
				monkeys[indx].items = append(monkeys[indx].items, worryLevel)
			}

			monkeys[j].inspections += len(monkeys[j].items)
			monkeys[j].items = []int{}
		}
	}

	sort.Slice(monkeys, func(i, j int) bool {
		return monkeys[i].inspections > monkeys[j].inspections
	})

	return monkeys[0].inspections * monkeys[1].inspections
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
