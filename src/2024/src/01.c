#include "01.h"

typedef struct {
    int32_t number;
    uint32_t count;
} NumberCount;

int32_t compare_ints(const void *a, const void *b) {
    int32_t int_a = *(const int32_t *)a;
    int32_t int_b = *(const int32_t *)b;

    return (int_a > int_b) - (int_a < int_b);
}

int32_t find_number(
    const NumberCount *counts,
    const u_int32_t size,
    const int32_t number
) {
    for (size_t i = 0; i < size; i++)
        if (counts[i].number == number)
            return (int32_t)i;

    return -1;
}

int32_t day_01_1(const size_t n_lines, char **lines) {
    int32_t list_a[n_lines];
    int32_t list_b[n_lines];

    for (size_t i = 0; i < n_lines; i++)
        sscanf(lines[i], "%d %d", &list_a[i], &list_b[i]);

    qsort(list_a, n_lines, sizeof(int32_t), compare_ints);
    qsort(list_b, n_lines, sizeof(int32_t), compare_ints);

    int32_t d_total = 0;
    for (size_t i = 0; i < n_lines; i++)
        d_total += abs(list_a[i] - list_b[i]);

    return d_total;
}

int32_t day_01_2(const size_t n_lines, char **lines) {
    int32_t list_l[n_lines];
    int32_t list_r[n_lines];

    for (size_t i = 0; i < n_lines; i++)
        sscanf(lines[i], "%d %d", &list_l[i], &list_r[i]);

    NumberCount counts[n_lines];
    size_t counts_size = 0;
    for (size_t i = 0; i < n_lines; i++) {
        int32_t indx = find_number(counts, counts_size, list_r[i]);

        if (indx != -1)
            counts[indx].count++;
        else {
            counts[counts_size].number = list_r[i];
            counts[counts_size].count = 1;
            counts_size++;
        }
    }

    int32_t similarity_score = 0;
    for (size_t i = 0; i < n_lines; i++) {
        int32_t indx = find_number(counts, counts_size, list_l[i]);
        if (indx != -1)
            similarity_score += counts[indx].count * counts[indx].number;
    }

    return similarity_score;
}
