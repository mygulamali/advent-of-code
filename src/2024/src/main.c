#include <stdio.h>
#include <stdlib.h>

#include "01.h"
#include "02.h"
#include "03.h"
#include "04.h"
#include "05.h"
#include "06.h"
#include "07.h"
#include "08.h"
#include "09.h"
#include "11.h"

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

    /* Day 02 */
    printf("Day 2\n");
    filename = concat(argv[1], "02.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %d\n", day_02_1(n_lines, lines));
    printf("- Part 2: %d\n", day_02_2(n_lines, lines));
    free_lines(n_lines, lines);

    /* Day 03 */
    printf("Day 3\n");
    filename = concat(argv[1], "03.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %d\n", day_03_1(n_lines, lines));
    printf("- Part 2: %d\n", day_03_2(n_lines, lines));
    free_lines(n_lines, lines);

    /* Day 04 */
    printf("Day 4\n");
    filename = concat(argv[1], "04.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %d\n", day_04_1(n_lines, lines));
    printf("- Part 2: %d\n", day_04_2(n_lines, lines));
    free_lines(n_lines, lines);

    /* Day 05 */
    printf("Day 5\n");
    filename = concat(argv[1], "05.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %d\n", day_05_1(n_lines, lines));
    free_lines(n_lines, lines);

    /* Day 06 */
    printf("Day 6\n");
    filename = concat(argv[1], "06.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %u\n", day_06_1(n_lines, lines));
    free_lines(n_lines, lines);

    /* Day 07 */
    printf("Day 7\n");
    filename = concat(argv[1], "07.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %llu\n", day_07_1(n_lines, lines));
    free_lines(n_lines, lines);

    /* Day 08 */
    printf("Day 8\n");
    filename = concat(argv[1], "08.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %u\n", day_08_1(n_lines, lines));
    free_lines(n_lines, lines);

    /* Day 09 */
    printf("Day 9\n");
    filename = concat(argv[1], "09.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %lu\n", day_09_1(n_lines, lines));
    free_lines(n_lines, lines);

    /* Day 11 */
    printf("Day 11\n");
    filename = concat(argv[1], "11.txt");
    lines = read_lines(filename, &n_lines);
    free(filename);

    printf("- Part 1: %llu\n", day_11_1(n_lines, lines));
    /* Commented out because it takes very long */
    //printf("- Part 2: %llu\n", day_11_2(n_lines, lines));
    free_lines(n_lines, lines);
}
