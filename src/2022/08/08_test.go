package day08

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TestData = []string {
	"30373",
	"25512",
	"65332",
	"33549",
	"35390",
}

func TestPart1(t *testing.T) {
	assert.Equal(t, 21, Part1(TestData))
}

func TestPart2(t *testing.T) {
	assert.Equal(t, 8, Part2(TestData))
}
