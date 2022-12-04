package main

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TEST_DATA = []string {
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
	assert.Equal(t, Part1(TEST_DATA), 24000)
}

func TestDay1Part2(t *testing.T) {
	assert.Equal(t, Part2(TEST_DATA), 45000)
}
