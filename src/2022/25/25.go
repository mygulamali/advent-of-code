package day25

import (
	"fmt"
	"math"
	"strconv"

	"gulamali.net/utils"
)

var Day = 25

func SNAFU2Dec(snafu string) int {
	decimal := 0
	n := len(snafu)

	for i := n - 1; i >= 0; i-- {
		var sign, m int
		if snafu[i] == '=' {
			sign = -1
			m = 2
		} else if snafu[i] == '-' {
			sign = -1
			m = 1
		} else {
			sign = 1
			m, _ = strconv.Atoi(string(snafu[i]))
		}

		exponent := float64(n - 1 - i)
		decimal += sign * m * int(math.Pow(5.0, exponent))
	}

	return decimal
}

func Dec2SNAFU(decimal int) string {
	remainder := float64(decimal)
	n := int(math.Floor(math.Log(remainder) / math.Log(5.0))) + 1

	snafuInts := make([]int, n + 1) // n + 1 to provide extra left most bit
	for i := n - 1; i >= 0; i-- {
		value := math.Pow(5.0, float64(i))
		m := math.Floor(remainder / value)
		remainder -= m * value
		snafuInts[n - i] = int(m)
	}

	for i := n; i >= 1; i-- {
		if snafuInts[i] > 2 {
			snafuInts[i] -= 5
			snafuInts[i - 1] += 1
		}
	}

	snafu := ""
	for i := 0; i < n + 1; i++ {
		if i == 0 && snafuInts[0] == 0 {
			continue
		}

		char := ""
		if snafuInts[i] == -2 {
			char = "="
		} else if snafuInts[i] == -1 {
			char = "-"
		} else {
			char = strconv.Itoa(snafuInts[i])
		}

		snafu += char
	}

	return snafu
}

func Part1(data []string) string {
	fuel := 0

	for _, line := range data {
		fuel += SNAFU2Dec(line)
	}

	return Dec2SNAFU(fuel)
}

func Part2(data []string) int {
	return 0
}

func Main() {
	data := utils.ReadPuzzleData(Day)

	fmt.Println("Day", Day)
	fmt.Println("Part 1:", Part1(data))
	fmt.Println("Part 2:", Part2(data))
}
