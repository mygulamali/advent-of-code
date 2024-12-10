#include "test-07.h"

const size_t n_lines_07 = 9;
char* lines_07[n_lines_07] = {
    "190: 10 19",
    "3267: 81 40 27",
    "83: 17 5",
    "156: 15 6",
    "7290: 6 8 6 15",
    "161011: 16 10 13",
    "192: 17 8 14",
    "21037: 9 7 18 13",
    "292: 11 6 16 20"
};

void test_day_07_1(void **state) {
    (void) state; /* unused */

    const uint64_t result = day_07_1(n_lines_07, lines_07);

    assert_int_equal(result, 3749);
}
