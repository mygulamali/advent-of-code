#include "test-09.h"

const size_t n_lines_09 = 1;
char* lines_09[n_lines_09] = {
    "2333133121414131402"
};

void test_day_09_1(void **state) {
    (void) state; /* unused */

    const uint64_t result = day_09_1(n_lines_09, lines_09);

    assert_int_equal(result, 1928);
}
