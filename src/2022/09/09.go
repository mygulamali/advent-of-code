package day09

import (
	"fmt"
	"log"
	"regexp"
	"strconv"

	"gulamali.net/utils"
)

var Day = 9

var reStep = regexp.MustCompile(`^([U|R|D|L]) (-?\d+)$`)

type Position struct {
	x int
	y int
}

func (p *Position) MoveUp(v int) {
	p.y += v
}

func (p *Position) MoveRight(v int) {
	p.x += v
}

func (p *Position) MoveDown(v int) {
	p.y -= v
}

func (p *Position) MoveLeft(v int) {
	p.x -= v
}

func Part1(data []string) int {
	head := Position{0, 0}
	tail := Position{0, 0}
	positionMap := map[Position]int{}

	for i, line := range data {
		match := reStep.FindStringSubmatch(line)
		direction := match[1]
		value, _ := strconv.Atoi(match[2])

		for j := 0; j < value; j++ {
			if direction == "U" {
				head.MoveUp(1)
				if head.y - tail.y > 1 {
					tail.x = head.x
					tail.y = head.y - 1
				}
			} else if direction == "R" {
				head.MoveRight(1)
				if head.x - tail.x > 1 {
					tail.x = head.x - 1
					tail.y = head.y
				}
			} else if direction == "D" {
				head.MoveDown(1)
				if tail.y - head.y > 1 {
					tail.x = head.x
					tail.y = head.y + 1
				}
			} else if direction == "L" {
				head.MoveLeft(1)
				if tail.x - head.x > 1 {
					tail.x = head.x + 1
					tail.y = head.y
				}
			} else {
				mssg := fmt.Sprintf("Unrecognised line %d: %s", i, line)
				log.Fatalf(mssg)
			}

			_, exists := positionMap[tail]
			if exists {
				positionMap[tail] += 1
			} else {
				positionMap[tail] = 1
			}
		}
	}

	return len(positionMap)
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
