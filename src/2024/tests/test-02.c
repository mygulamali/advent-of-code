#include "test-02.h"

const size_t n_lines_02 = 6;
char* lines_02[n_lines_02] = {
    "7 6 4 2 1",
    "1 2 7 8 9",
    "9 7 6 2 1",
    "1 3 2 4 5",
    "8 6 4 4 1",
    "1 3 6 7 9"
};

void test_day_02_1(void **state) {
    (void) state; /* unused */

    const int32_t result = day_02_1(n_lines_02, lines_02);

    assert_int_equal(result, 2);
}

void test_day_02_2(void **state) {
    (void) state; /* unused */

    const int32_t result = day_02_2(n_lines_02, lines_02);

    assert_int_equal(result, 4);
}
