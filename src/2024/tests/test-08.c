#include "test-08.h"

const size_t n_lines_08 = 12;
char* lines_08[n_lines_08] = {
    "............",
    "........0...",
    ".....0......",
    ".......0....",
    "....0.......",
    "......A.....",
    "............",
    "............",
    "........A...",
    ".........A..",
    "............",
    "............"
};

void test_day_08_1(void **state) {
    (void) state; /* unused */

    const uint32_t result = day_08_1(n_lines_08, lines_08);

    assert_int_equal(result, 14);
}
