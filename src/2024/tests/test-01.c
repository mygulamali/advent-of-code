#include "test-01.h"

const size_t n_lines_01 = 6;
char* lines_01[n_lines_01] = {
    "3   4",
    "4   3",
    "2   5",
    "1   3",
    "3   9",
    "3   3"
};

void test_day_01_1(void **state) {
    (void) state; /* unused */

    const int32_t result = day_01_1(n_lines_01, lines_01);

    assert_int_equal(result, 11);
}

void test_day_01_2(void **state) {
    (void) state; /* unused */

    const int32_t result = day_01_2(n_lines_01, lines_01);

    assert_int_equal(result, 31);
}
