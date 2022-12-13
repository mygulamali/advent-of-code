package day11

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TestData = []string {
	"Monkey 0:",
	"  Starting items: 79, 98",
	"  Operation: new = old * 19",
	"  Test: divisible by 23",
	"    If true: throw to monkey 2",
	"    If false: throw to monkey 3",
	"",
	"Monkey 1:",
	"  Starting items: 54, 65, 75, 74",
	"  Operation: new = old + 6",
	"  Test: divisible by 19",
	"    If true: throw to monkey 2",
	"    If false: throw to monkey 0",
	"",
	"Monkey 2:",
	"  Starting items: 79, 60, 97",
	"  Operation: new = old * old",
	"  Test: divisible by 13",
	"    If true: throw to monkey 1",
	"    If false: throw to monkey 3",
	"",
	"Monkey 3:",
	"  Starting items: 74",
	"  Operation: new = old + 3",
	"  Test: divisible by 17",
	"    If true: throw to monkey 0",
	"    If false: throw to monkey 1",
}

func TestMonkeyCalculateWorryLevel(t *testing.T) {
	items := []int{79}
	var operation = []string{}
	var monkey = Monkey{}

	operation = []string{"old", "*", "19"}
	monkey = Monkey{items, operation, 0, 0, 0, 0}
	assert.Equal(t, 500, monkey.CalculateWorryLevel(0))

	operation = []string{"old", "+", "6"}
	monkey = Monkey{items, operation, 0, 0, 0, 0}
	assert.Equal(t, 28, monkey.CalculateWorryLevel(0))
}

func TestParseItems(t *testing.T) {
	data := "  Starting items: 79, 98"
	expectedItems := []int{79, 98}

	assert.Equal(t, expectedItems, ParseItems(data))
}

func TestParseOperation(t *testing.T) {
	data := "  Operation: new = old * 19"
	expectedOperation := []string{"old", "*", "19"}

	assert.Equal(t, expectedOperation, ParseOperation(data))
}

func TestParseTest(t *testing.T) {
	data := "  Test: divisible by 23"
	assert.Equal(t, 23, ParseTest(data))
}

func TestParseBranch(t *testing.T) {
	var data string
	data = "    If true: throw to monkey 2"
	assert.Equal(t, 2, ParseBranch(data))

	data = "    If false: throw to monkey 3"
	assert.Equal(t, 3, ParseBranch(data))
}

func TestPart1(t *testing.T) {
	assert.Equal(t, 10605, Part1(TestData))
}

func TestPart2(t *testing.T) {
	assert.Equal(t, 0, Part2(TestData))
}
