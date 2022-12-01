#include "utils.h"

#define TARGET 2020

int main(int argc, char *argv[]) {
    if (argc != 2) {
	printf("Usage: %s <PUZZLE INPUT>\n", argv[0]);
	exit(EXIT_FAILURE);
    }

    printf("Day 1\n");

    int n;
    char **lines = read_lines(argv[1], &n);

    int input[n];
    for (int i = 0; i < n; i++)
	input[i] = atoi(lines[i]);
    free_lines(n, lines);

    /* Part 1 */
    bool stop = false;
    int x, y;
    for (int i = 0; i < n && !stop; i++) {
	x = input[i];
	for (int j = 0; j < n && !stop; j++) {
	    y = input[j];
	    if ((x + y == TARGET) && (i != j)) {
		stop = true;
		break;
	    }
	}
    }

    if (!stop) {
	printf("Error: answer not found.\n");
	exit(EXIT_FAILURE);
    }

    printf("Part 1: %d x %d = %d\n", x, y, x * y);

    /* Part 2 */
    int z;
    stop = false;
    for (int i = 0; i < n && !stop; i++) {
	x = input[i];
	for (int j = 0; j < n && !stop; j++) {
	    y = input[j];
	    for (int k = 0; k < n && !stop; k++) {
		z = input[k];
		if ((x + y + z == TARGET) && (i != j) && (i != k) && (j != k)) {
		    stop = true;
		    break;
		}
	    }
	}
    }

    if (!stop) {
	printf("Error: answer not found.\n");
	exit(EXIT_FAILURE);
    }

    printf("Part 2: %d x %d x %d = %d\n", x, y, z, x * y * z);

    exit(EXIT_SUCCESS);
}
