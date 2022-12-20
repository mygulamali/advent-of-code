package day11

import (
	"fmt"
	"math/big"
	"regexp"
	"sort"
	"strconv"
	"strings"

	"gulamali.net/src/2022/utils"
)

var Day = 11

var Zero = big.NewInt(0)

var reItems = regexp.MustCompile(`(\d+),?`)
var reOperation = regexp.MustCompile(`Operation: new = (.+)`)
var reTest = regexp.MustCompile(`Test: divisible by (\d+)`)
var reBranch = regexp.MustCompile(`If (true|false): throw to monkey (\d+)`)

type Monkey struct {
	items []*big.Int
	operation []string
	test *big.Int
	truthy int
	falsey int
	inspections int
}

func (self *Monkey) TestWorryLevel(indx int, part2 bool) (int, *big.Int) {
	worryLevel := self.CalculateWorryLevel(indx, part2)
	tmp := big.NewInt(0)
	if tmp.Mod(worryLevel, self.test).Cmp(Zero) == 0 {
		return self.truthy, worryLevel
	}
	return  self.falsey, worryLevel
}

func (self *Monkey) CalculateWorryLevel(indx int, part2 bool) *big.Int {
	old := self.items[indx]

	// process left-hand-side of operation
	left, ok := new(big.Int).SetString(self.operation[0], 10)
	if !ok {
		left = old
	}

	// process right-hand-side of operation
	right, ok := new(big.Int).SetString(self.operation[2], 10)
	if !ok {
		right = old
	}

	// calculate new worry level
	new := big.NewInt(0)
	if self.operation[1] == "+" {
		new.Add(left, right)
	} else if self.operation[1] == "*" {
		new.Mul(left, right)
	}

	if part2 {
		return new
	}

	tmp := big.NewInt(0)
	return tmp.Div(new, big.NewInt(3))
}

func ParseItems(data string) []*big.Int {
	items := []*big.Int{}

	match := reItems.FindAllStringSubmatch(data, -1)
	for i := 0; i < len(match); i++ {
		v, _ := new(big.Int).SetString(match[i][1], 10)
		items = append(items, v)
	}

	return items
}

func ParseOperation(data string) []string {
	match := reOperation.FindStringSubmatch(data)
	return strings.Split(match[1], " ")
}

func ParseTest(data string) *big.Int {
	match := reTest.FindStringSubmatch(data)
	v, _ := new(big.Int).SetString(match[1], 10)
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

func SimbianShenanigans(data []string, rounds int, part2 bool) int {
	monkeys := ParseData(data)

	// loop over rounds
	for i := 0; i < rounds; i++ {
		// loop over monkeys
		for j := 0; j < len(monkeys); j++ {
			// loop over items taken by each monkey
			for k := 0; k < len(monkeys[j].items); k++ {
				indx, worryLevel := monkeys[j].TestWorryLevel(k, part2)
				monkeys[indx].items = append(monkeys[indx].items, worryLevel)
			}

			monkeys[j].inspections += len(monkeys[j].items)
			monkeys[j].items = []*big.Int{}
		}
	}

	sort.Slice(monkeys, func(i, j int) bool {
		return monkeys[i].inspections > monkeys[j].inspections
	})

	return monkeys[0].inspections * monkeys[1].inspections
}


func Part1(data []string) int {
	return SimbianShenanigans(data, 20, false)
}

func Part2(data []string) int {
	return SimbianShenanigans(data, 20, true)
	// return SimbianShenanigans(data, 10000, true)
}

func Main() {
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:", Part2(data))
}
