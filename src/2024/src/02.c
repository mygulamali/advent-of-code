#include <limits.h>

#include "02.h"

bool is_safe(const int32_t *report, const size_t n) {
    int16_t signs[n - 1];

    for (size_t i = 0, m = n - 1; i < m; i++) {
        const int32_t diff = report[i + 1] - report[i];
        signs[i] = diff > 0 ? 1 : -1;

        // check difference is within bounds
        if (abs(diff) < 1 || abs(diff) > 3)
            return false;
    }

    // check sequence is monotonic
    for (size_t i = 0, m = n - 2; i < m; i++)
        if (signs[i + 1] != signs[i])
            return false;

    return true;
}

int32_t * slice(const int32_t *array, const size_t n, const size_t indx) {
    int32_t *ret = (int32_t *) malloc((n - 1) * sizeof(int32_t));

    size_t j = 0;
    for (size_t i = 0; i < n; i++)
        if (i != indx)
            ret[j++] = array[i];

    return ret;
}

int32_t day_02_1(const size_t n_lines, char **lines) {
    uint32_t n_safe = 0;

    for (size_t i = 0; i < n_lines; i++) {
        size_t n;
        char **report_str = str_split(lines[i], " ", &n);

        int32_t report[n];
        for (size_t j = 0; j < n; j++)
            report[j] = strtod(report_str[j], NULL);

        if (is_safe(report, n)) n_safe++;

        free(report_str);
    }

    return n_safe;
}

int32_t day_02_2(const size_t n_lines, char **lines) {
    uint32_t n_safe = 0;

    for (size_t i = 0; i < n_lines; i++) {
        size_t n;
        char **report_str = str_split(lines[i], " ", &n);

        int32_t report[n];
        for (size_t j = 0; j < n; j++)
            report[j] = strtod(report_str[j], NULL);

        if (is_safe(report, n))
            n_safe++;
        else {
            for (size_t j = 0; j < n; j++) {
                int32_t *new_report = slice(report, n, j);

                if (is_safe(new_report, n - 1)) {
                    n_safe++;
                    break;
                }

                free(new_report);
            }
        }

        free(report_str);
    }

    return n_safe;
}
