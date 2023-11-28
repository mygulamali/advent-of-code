package day21

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

var TestData = []string {
	"root: pppw + sjmn",
	"dbpl: 5",
	"cczh: sllz + lgvd",
	"zczc: 2",
	"ptdq: humn - dvpt",
	"dvpt: 3",
	"lfqf: 4",
	"humn: 5",
	"ljgn: 2",
	"sjmn: drzm * dbpl",
	"sllz: 4",
	"pppw: cczh / lfqf",
	"lgvd: ljgn * ptdq",
	"drzm: hmdt - zczc",
	"hmdt: 32",
}

func TestPart1(t *testing.T) {
	assert.Equal(t, 152, Part1(TestData))
}

func TestPart2(t *testing.T) {
	assert.Equal(t, 0, Part2(TestData))
}
