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
    const size_t list_size = sizeof(int32_t) * n_lines;
    int32_t *list_1 = (int32_t *) malloc(list_size);
    int32_t *list_2 = (int32_t *) malloc(list_size);

    if (list_1 == NULL || list_2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n_lines; i++)
        sscanf(lines[i], "%d %d", &list_1[i], &list_2[i]);

    qsort(list_1, n_lines, sizeof(int32_t), compare_ints);
    qsort(list_2, n_lines, sizeof(int32_t), compare_ints);

    int32_t d_total = 0;
    for (size_t i = 0; i < n_lines; i++)
        d_total += abs(list_1[i] - list_2[i]);

    free(list_1);
    free(list_2);

    return d_total;
}

int32_t day_01_2(const size_t n_lines, char **lines) {
    const size_t list_size = sizeof(int32_t) * n_lines;
    int32_t *list_l = (int32_t *) malloc(list_size);
    int32_t *list_r = (int32_t *) malloc(list_size);

    if (list_l == NULL || list_r == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

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

    free(list_l);
    free(list_r);

    return similarity_score;
}
