package day06

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func TestPart1(t *testing.T) {
	assert.Equal(t, Part1("mjqjpqmgbljsphdztnvjfqwrcgsmlb"), 7)
	assert.Equal(t, Part1("bvwbjplbgvbhsrlpgdmjqwftvncz"), 5)
	assert.Equal(t, Part1("nppdvjthqldpwncqszvftbrmjlhg"), 6)
	assert.Equal(t, Part1("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"), 10)
	assert.Equal(t, Part1("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"), 11)
}

func TestPart2(t *testing.T) {
	assert.Equal(t, Part2("mjqjpqmgbljsphdztnvjfqwrcgsmlb"), 19)
	assert.Equal(t, Part2("bvwbjplbgvbhsrlpgdmjqwftvncz"), 23)
	assert.Equal(t, Part2("nppdvjthqldpwncqszvftbrmjlhg"), 23)
	assert.Equal(t, Part2("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"), 29)
	assert.Equal(t, Part2("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"), 26)
}
