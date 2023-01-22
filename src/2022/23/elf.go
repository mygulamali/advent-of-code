package day23

type Elf struct {
	x int
	y int
	xNew int
	yNew int
	proposed bool
}

func (e *Elf) N(o Elf) bool {
	if e.x == o.x && e.y - 1 == o.y {
		return true
	}
	return false
}

func (e *Elf) NW(o Elf) bool {
	if e.x - 1 == o.x && e.y - 1 == o.y {
		return true
	}
	return false
}

func (e *Elf) NE(o Elf) bool {
	if e.x + 1 == o.x && e.y - 1 == o.y {
		return true
	}
	return false
}

func (e *Elf) S(o Elf) bool {
	if e.x == o.x && e.y + 1 == o.y {
		return true
	}
	return false
}

func (e *Elf) SW(o Elf) bool {
	if e.x - 1 == o.x && e.y + 1 == o.y {
		return true
	}
	return false
}

func (e *Elf) SE(o Elf) bool {
	if e.x + 1 == o.x && e.y + 1 == o.y {
		return true
	}
	return false
}

func (e *Elf) W(o Elf) bool {
	if e.x - 1 == o.x && e.y == o.y {
		return true
	}
	return false
}

func (e *Elf) E(o Elf) bool {
	if e.x + 1 == o.x && e.y == o.y {
		return true
	}
	return false
}
