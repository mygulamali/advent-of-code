#include <string.h>

#include "07.h"

uint64_t * equation_values(char* line, uint64_t *test_value, size_t *n_values) {
    size_t n;
    char **str = str_split(line, " ", &n);
    *n_values = n - 1;

    // values
    uint64_t *v = malloc((n - 1) * sizeof(uint64_t));
    for (size_t i = 1; i < n; i++)
        v[i - 1] = strtoull(str[i], NULL, 10);

    // test value
    str[0][strlen(str[0]) - 1] = '\0';
    *test_value = strtoull(str[0], NULL, 10);

    for (size_t i = 0; i < n; i++) free(str[i]);
    free(str);

    return v;
}

bool can_solve(const uint64_t *values, const size_t n_values, const uint64_t test_value) {
    // n = pow(2, n_values - 1)
    size_t n = 1;
    for (size_t i = 0; i < n_values - 1; i++)
        n *= 2;

    for (size_t i = 0; i < n; i++) {
        uint64_t result = values[0];
        size_t j = 1;
        for (int32_t bit = n_values - 2; bit >= 0; bit--) {
            uint8_t x = (i >> bit) & 1;
            if (x == 0)
                result += values[j];
            else
                result *= values[j];
            j++;
        }

        if (result == test_value)
            return true;
    }

    return false;
}

uint64_t day_07_1(const size_t n_lines, char **lines) {
    uint64_t result = 0;

    for (size_t i = 0; i < n_lines; i++) {
        size_t n_values;
        uint64_t test_value;
        uint64_t *values = equation_values(lines[i], &test_value, &n_values);

        if (can_solve(values, n_values, test_value))
            result += (uint64_t) test_value;

        free(values);
    }

    return result;
}
