#include <limits.h>

#include "02.h"

bool is_safe(const int32_t *report, const size_t n) {
    int16_t last_sign = 0;

    for (size_t i = 0, m = n - 1; i < m; i++) {
        const int32_t diff = report[i + 1] - report[i];
        const int16_t sign = diff > 0 ? 1 : -1;

        // check difference is within bounds
        if (abs(diff) < 1 || abs(diff) > 3)
            return false;

        // check sequence is monotonic
        if ((i > 1) && (sign != last_sign))
            return false;

        last_sign = sign;
    }

    return true;
}

int32_t day_02_1(const size_t n_lines, char **lines) {
    uint32_t n_safe = 0;

    for (size_t i = 0; i < n_lines; i++) {
        size_t n;
        char **report_str = str_split(lines[i], " ", &n);

        int32_t report[n];
        for (size_t j = 0; j < n; j++)
            report[j] = atoi(report_str[j]);

        if (is_safe(report, n)) n_safe++;

        free(report_str);
    }

    return n_safe;
}
