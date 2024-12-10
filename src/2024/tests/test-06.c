#include "test-06.h"

const size_t n_lines_06 = 10;
char* lines_06[n_lines_06] = {
    "....#.....",
    ".........#",
    "..........",
    "..#.......",
    ".......#..",
    "..........",
    ".#..^.....",
    "........#.",
    "#.........",
    "......#...",
};

void test_day_06_1(void **state) {
    (void) state; /* unused */

    const uint32_t result = day_06_1(n_lines_06, lines_06);

    assert_int_equal(result, 41);
}
