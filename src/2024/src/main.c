#include <stdio.h>
#include <stdlib.h>

#include "01.h"

int main(const int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PUZZLE DIRECTORY>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size_t n_lines;
    char **lines;
    char *filename;

    /* Day 01 */
    printf("Day 1\n");
    filename = concat(argv[1], "01.txt");
    lines = read_lines(filename, &n_lines);

    free(filename);
    printf("- Part 1: %d\n", day_01_1(n_lines, lines));
    printf("- Part 2: %d\n", day_01_2(n_lines, lines));
    free_lines(n_lines, lines);
}
