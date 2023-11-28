package day25

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TestData = []string {
	"1=-0-2",
	"12111",
	"2=0=",
	"21",
	"2=01",
	"111",
	"20012",
	"112",
	"1=-1=",
	"1-12",
	"12",
	"1=",
	"122",
}

func TestSNAFU2Dec(t *testing.T) {
	assert.Equal(t, 1747, SNAFU2Dec("1=-0-2"))
	assert.Equal(t, 906, SNAFU2Dec("12111"))
	assert.Equal(t, 198, SNAFU2Dec("2=0="))
	assert.Equal(t, 11, SNAFU2Dec("21"))
	assert.Equal(t, 201, SNAFU2Dec("2=01"))
	assert.Equal(t, 31, SNAFU2Dec("111"))
	assert.Equal(t, 1257, SNAFU2Dec("20012"))
	assert.Equal(t, 32, SNAFU2Dec("112"))
	assert.Equal(t, 353, SNAFU2Dec("1=-1="))
	assert.Equal(t, 107, SNAFU2Dec("1-12"))
	assert.Equal(t, 7, SNAFU2Dec("12"))
	assert.Equal(t, 3, SNAFU2Dec("1="))
	assert.Equal(t, 37, SNAFU2Dec("122"))
}

func TestDec2SNAFU2Dec(t *testing.T) {
	assert.Equal(t, "1=-0-2", Dec2SNAFU(1747))
	assert.Equal(t, "12111", Dec2SNAFU(906))
	assert.Equal(t, "2=0=", Dec2SNAFU(198))
	assert.Equal(t, "21", Dec2SNAFU(11))
	assert.Equal(t, "2=01", Dec2SNAFU(201))
	assert.Equal(t, "111", Dec2SNAFU(31))
	assert.Equal(t, "20012", Dec2SNAFU(1257))
	assert.Equal(t, "112", Dec2SNAFU(32))
	assert.Equal(t, "1=-1=", Dec2SNAFU(353))
	assert.Equal(t, "1-12", Dec2SNAFU(107))
	assert.Equal(t, "12", Dec2SNAFU(7))
	assert.Equal(t, "1=", Dec2SNAFU(3))
	assert.Equal(t, "122", Dec2SNAFU(37))
}

func TestPart1(t *testing.T) {
	assert.Equal(t, "2=-1=0", Part1(TestData))
}

func TestPart2(t *testing.T) {
	assert.Equal(t, 0, Part2(TestData))
}
