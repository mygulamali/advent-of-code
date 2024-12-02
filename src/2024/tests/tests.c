#include "test-01.h"
#include "test-02.h"

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_day_01_1),
        cmocka_unit_test(test_day_01_2),
        cmocka_unit_test(test_day_02_1)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
