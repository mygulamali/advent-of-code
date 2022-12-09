package day05

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TestData = []string {
	"    [D]",
	"[N] [C]",
	"[Z] [M] [P]",
	" 1   2   3",
	"",
	"move 1 from 2 to 1",
	"move 3 from 1 to 3",
	"move 2 from 2 to 1",
	"move 1 from 1 to 2",
}

func TestParseStacks(t *testing.T) {
	expectedStacks := [][]string {
		{ "Z", "N" },
		{ "M", "C", "D" },
		{ "P" },
	}

	assert.Equal(t, ParseStacks(TestData), expectedStacks)
}

func TestParseMoves(t *testing.T) {
	expectedMoves := []Move {
        Move{1, 1, 0},
        Move{3, 0, 2},
		Move{2, 1, 0},
		Move{1, 0, 1},
	}

	assert.Equal(t, ParseMoves(TestData), expectedMoves)
}


func TestPart1(t *testing.T) {
	assert.Equal(t, "CMZ", Part1(TestData))
}

func TestPart2(t *testing.T) {
	assert.Equal(t, "MCD", Part2(TestData))
}
