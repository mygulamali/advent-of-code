#include "test-04.h"

const size_t n_lines_04 = 10;
char* lines_04[n_lines_04] = {
    "MMMSXXMASM",
    "MSAMXMSMSA",
    "AMXSXMAAMM",
    "MSAMASMSMX",
    "XMASAMXAMM",
    "XXAMMXXAMA",
    "SMSMSASXSS",
    "SAXAMASAAA",
    "MAMMMXMMMM",
    "MXMXAXMASX",
};

void test_day_04_1(void **state) {
    (void) state; /* unused */

    const int32_t result = day_04_1(n_lines_04, lines_04);

    assert_int_equal(result, 18);
}

void test_day_04_2(void **state) {
    (void) state; /* unused */

    const int32_t result = day_04_2(n_lines_04, lines_04);

    assert_int_equal(result, 9);
}
