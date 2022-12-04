package utils

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

var DATA_DIR = "data/2022"

func ReadPuzzleData(day int) []string {
	filename := fmt.Sprintf("%s/%02d.txt", DATA_DIR, day)
	file, err := os.Open(filename)

	if err != nil {
		mssg := fmt.Sprintf("Failed to open file, %s", filename)
		log.Fatalf(mssg)
	}

	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanLines)

	var data []string
	for scanner.Scan() {
		data = append(data, scanner.Text())
	}

	file.Close()

	return data
}
