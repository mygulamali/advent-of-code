package day23

import (
	"fmt"
	"math"
)

type Grid struct {
	elves []Elf
}

func (g *Grid) North() int {
	y := math.MaxInt
	for i := 0; i < len(g.elves); i++ {
		y = min(y, g.elves[i].y)
	}
	return y
}

func (g *Grid) South() int {
	y := math.MinInt
	for i := 0; i < len(g.elves); i++ {
		y = max(y, g.elves[i].y)
	}
	return y
}

func (g *Grid) West() int {
	x := math.MaxInt
	for i := 0; i < len(g.elves); i++ {
		x = min(x, g.elves[i].x)
	}
	return x
}

func (g *Grid) East() int {
	x := math.MinInt
	for i := 0; i < len(g.elves); i++ {
		x = max(x, g.elves[i].x)
	}
	return x
}

func (g *Grid) ElfIsClear(i int) bool {
	for j := 0; j < len(g.elves); j++ {
		if i == j {
			continue
		}

		if g.elves[i].N(g.elves[j]) ||
			g.elves[i].NW(g.elves[j]) ||
			g.elves[i].NE(g.elves[j])||
			g.elves[i].S(g.elves[j]) ||
			g.elves[i].SW(g.elves[j]) ||
			g.elves[i].SE(g.elves[j]) ||
			g.elves[i].W(g.elves[j]) ||
			g.elves[i].E(g.elves[j]) {
			return false
		}
	}

	return true
}

func (g *Grid) ElfCanMoveNorth(i int) bool {
	for j := 0; j < len(g.elves); j++ {
		if i == j {
			continue
		}

		// N || NW || NE
		if g.elves[i].N(g.elves[j]) || g.elves[i].NW(g.elves[j]) || g.elves[i].NE(g.elves[j]) {
			return false
		}
	}

	return true
}

func (g *Grid) ElfCanMoveSouth(i int) bool {
	for j := 0; j < len(g.elves); j++ {
		if i == j {
			continue
		}

		// S || SW || SE
		if g.elves[i].S(g.elves[j]) || g.elves[i].SW(g.elves[j]) || g.elves[i].SE(g.elves[j]) {
			return false
		}
	}

	return true
}

func (g *Grid) ElfCanMoveWest(i int) bool {
	for j := 0; j < len(g.elves); j++ {
		if i == j {
			continue
		}

		// W || NW || SW
		if g.elves[i].W(g.elves[j]) || g.elves[i].NW(g.elves[j]) || g.elves[i].SW(g.elves[j]) {
			return false
		}
	}

	return true
}

func (g *Grid) ElfCanMoveEast(i int) bool {
	for j := 0; j < len(g.elves); j++ {
		if i == j {
			continue
		}

		// E || NE || SE
		if g.elves[i].E(g.elves[j]) || g.elves[i].NE(g.elves[j]) || g.elves[i].SE(g.elves[j]) {
			return false
		}
	}

	return true
}

func (g *Grid) ProposeNewElfPosition(i int, direction int) {
	if direction == 0 { // N
		if g.ElfCanMoveNorth(i) {
			g.elves[i].xNew = g.elves[i].x
			g.elves[i].yNew = g.elves[i].y - 1
			g.elves[i].proposed = true
		}
	} else if direction == 1 { // S
		if g.ElfCanMoveSouth(i) {
			g.elves[i].xNew = g.elves[i].x
			g.elves[i].yNew = g.elves[i].y + 1
			g.elves[i].proposed = true
		}
	} else if direction == 2 { // W
		if g.ElfCanMoveWest(i) {
			g.elves[i].xNew = g.elves[i].x - 1
			g.elves[i].yNew = g.elves[i].y
			g.elves[i].proposed = true
		}
	} else if direction == 3 { // E
		if g.ElfCanMoveEast(i) {
			g.elves[i].xNew = g.elves[i].x + 1
			g.elves[i].yNew = g.elves[i].y
			g.elves[i].proposed = true
		}
	}
}

func (g *Grid) Update(round int) {
	// propose new positions
	for i := 0; i < len(g.elves); i++ {
		g.elves[i].xNew = g.elves[i].x
		g.elves[i].yNew = g.elves[i].y

		if g.ElfIsClear(i) {
			continue
		}

		for d := 0; d < 4; d++ {
			if !g.elves[i].proposed {
				g.ProposeNewElfPosition(i, (round + d) % 4)
			}
		}
	}

	// check there are no clashes in new positions
	for i := 0; i < len(g.elves); i++ {
		for j := i + 1; j < len(g.elves); j++ {
			if g.elves[i].xNew == g.elves[j].xNew && g.elves[i].yNew == g.elves[j].yNew {
				g.elves[i].xNew = g.elves[i].x
				g.elves[i].yNew = g.elves[i].y
				g.elves[j].xNew = g.elves[j].x
				g.elves[j].yNew = g.elves[j].y
				break
			}
		}
	}

	// update to new positions
	for i := 0; i < len(g.elves); i++ {
		g.elves[i].x = g.elves[i].xNew
		g.elves[i].y = g.elves[i].yNew
		g.elves[i].proposed = false
	}
}

func (g *Grid) EmptyGround() int {
	return ((g.South() - g.North() + 1) * (g.East() - g.West() + 1)) - len(g.elves)
}

func (g *Grid) IsEmpty(x int, y int) bool {
	for _, elf := range g.elves {
		if elf.x == x && elf.y == y {
			return false
		}
	}

	return true
}

func (g *Grid) Print() {
	yMin := g.North()
	yMax := g.South()
	xMin := g.West()
	xMax := g.East()

	for y := yMin; y <= yMax; y++ {
		for x := xMin; x <= xMax; x++ {
			if g.IsEmpty(x, y) {
				fmt.Printf(".")
			} else {
				fmt.Printf("#")
			}
		}
		fmt.Printf("\n")
	}
	fmt.Printf("\n")
}

func (g *Grid) RequiresUpdate() bool {
	for i := 0; i < len(g.elves); i++ {
		if !g.ElfIsClear(i) {
			return true
		}
	}

	return false
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
