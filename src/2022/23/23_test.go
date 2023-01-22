package day23

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TestData = []string {
	"....#..",
	"..###.#",
	"#...#.#",
	".#...##",
	"#.###..",
	"##.#.##",
	".#..#..",
}

func TestPart1(t *testing.T) {
	assert.Equal(t, 110, Part1(TestData))
}

func TestPart2(t *testing.T) {
	assert.Equal(t, 20, Part2(TestData))
}
