#include "test-03.h"

void test_day_03_1(void **state) {
    (void) state; /* unused */

    const size_t n_lines = 1;
    char* lines[n_lines] = {
        "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"
    };

    const int32_t result = day_03_1(n_lines, lines);

    assert_int_equal(result, 161);
}

void test_day_03_2(void **state) {
    (void) state; /* unused */

    const size_t n_lines = 1;
    char* lines[n_lines] = {
        "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))"
    };

    const int32_t result = day_03_2(n_lines, lines);

    assert_int_equal(result, 48);
}
