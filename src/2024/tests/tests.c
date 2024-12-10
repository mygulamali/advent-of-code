#include "test-01.h"
#include "test-02.h"
#include "test-03.h"
#include "test-04.h"
#include "test-05.h"
#include "test-07.h"

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_day_01_1),
        cmocka_unit_test(test_day_01_2),
        cmocka_unit_test(test_day_02_1),
        cmocka_unit_test(test_day_02_2),
        cmocka_unit_test(test_day_03_1),
        cmocka_unit_test(test_day_03_2),
        cmocka_unit_test(test_day_04_1),
        cmocka_unit_test(test_day_04_2),
        cmocka_unit_test(test_day_05_1),
        cmocka_unit_test(test_day_07_1),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
