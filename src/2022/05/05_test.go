package day05

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TEST_DATA = []string {
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
	expected_stacks := [][]string {
		{ "Z", "N" },
		{ "M", "C", "D" },
		{ "P" },
	}

	assert.Equal(t, ParseStacks(TEST_DATA), expected_stacks)
}

func TestParseMoves(t *testing.T) {
	expected_moves := []Move {
        Move{1, 1, 0},
        Move{3, 0, 2},
		Move{2, 1, 0},
		Move{1, 0, 1},
	}

	assert.Equal(t, ParseMoves(TEST_DATA), expected_moves)
}


func TestPart1(t *testing.T) {
	assert.Equal(t, Part1(TEST_DATA), "CMZ")
}

func TestPart2(t *testing.T) {
	assert.Equal(t, Part2(TEST_DATA), "MCD")
}
