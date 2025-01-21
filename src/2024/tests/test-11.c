#include "test-11.h"

const size_t n_lines_11 = 1;
char* lines_11[n_lines_11] = {
    "125 17"
};

void test_day_11_1(void **state) {
    (void) state; /* unused */

    const uint64_t result = day_11_1(n_lines_11, lines_11);

    assert_int_equal(result, 55312);
}
