package day21

import (
	"fmt"
	"regexp"
	"strconv"

	"gulamali.net/utils"
)

var Day = 21

var reDataOperation = regexp.MustCompile(`(\w{4}): (\w{4}) ([/+-/*//]) (\w{4})`)
var reDataNumber = regexp.MustCompile(`(\w{4}): (\d+)`)
var reNumber = regexp.MustCompile(`^-?\d+$`)

type Monkey struct {
	number string
	left string
	operator rune
	right string
}

func NewMonkey(data string) (string, Monkey) {
	match := reDataOperation.FindStringSubmatch(data)

	var monkey Monkey
	if len(match) > 0 {
		monkey = Monkey{
			left: match[2],
			operator: rune(match[3][0]),
			right: match[4],
		}
	} else {
		match = reDataNumber.FindStringSubmatch(data)
		monkey = Monkey{
			number: match[2],
		}
	}

	return match[1], monkey
}

func isNumber(str string) bool {
	return reNumber.MatchString(str)
}

func Part1(data []string) int {
	monkeys := map[string]Monkey{}
	for _, line := range data {
		name, monkey := NewMonkey(line)
		monkeys[name] = monkey
	}

	iters := 0
	for !isNumber(monkeys["root"].number) || iters < 100 {
		for name, monkey := range monkeys {
			if isNumber(monkey.number) {
				continue
			}

			leftNumber := monkeys[monkey.left].number
			if isNumber(leftNumber) && !isNumber(monkey.left) {
				monkey.left = leftNumber
			}

			rightNumber := monkeys[monkey.right].number
			if isNumber(rightNumber) && !isNumber(monkey.right) {
				monkey.right = rightNumber
			}

			if isNumber(monkey.right) && isNumber(monkey.left) {
				left, _ := strconv.Atoi(monkey.left)
				right, _ := strconv.Atoi(monkey.right)

				var result int
				if monkey.operator == '+' {
					result = left + right
				} else if monkey.operator == '-' {
					result = left - right
				} else if monkey.operator == '*' {
					result = left * right
				} else if monkey.operator == '/' {
					result = left / right
				}

				monkey.number = strconv.Itoa(result)
			}

			monkeys[name] = monkey
		}

		iters += 1
	}

	root, _ := strconv.Atoi(monkeys["root"].number)
	return root
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
