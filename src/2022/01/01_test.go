package day01

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TestData = []string {
    "1000",
    "2000",
    "3000",
    "",
    "4000",
    "",
    "5000",
    "6000",
    "",
    "7000",
    "8000",
    "9000",
    "",
    "10000",
}

func TestDay1Part1(t *testing.T) {
	assert.Equal(t, 24000, Part1(TestData))
}

func TestDay1Part2(t *testing.T) {
	assert.Equal(t, 45000, Part2(TestData))
}
