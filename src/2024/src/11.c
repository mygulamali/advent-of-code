#include "11.h"

typedef struct Stone {
    uint64_t value;
    struct Stone *next;
} Stone;

Stone * create_stone(const uint64_t value) {
    Stone *s = (Stone *) malloc(sizeof(Stone));
    if (s == NULL) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    s->value = value;
    s->next = NULL;

    return s;
}

Stone * get_stones(char *line, size_t *n_stones) {
    size_t n;
    char **values = str_split(line, " ", &n);

    Stone *s = create_stone(strtoull(values[0], NULL, 10));
    Stone *head = s;

    for (size_t i = 1; i < n; i++) {
        s->next = create_stone(strtoull(values[i], NULL, 10));
        s = s->next;
    }

    *n_stones = n;

    for (size_t i = 0; i < n; i++) free(values[i]);
    free(values);

    return head;
}

size_t number_of_digits(const uint64_t x) {
    size_t n_digits = 0;
    uint64_t y = x;

    while (y != 0) {
        y /= 10;
        n_digits++;
    }

    return n_digits;
}

uint64_t * split_value(const uint64_t x, const size_t n_digits) {
    size_t n = n_digits / 2;

    uint64_t *values = (uint64_t *) malloc(2 * sizeof(uint64_t));
    if (values == NULL) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    uint64_t y = x;
    for (size_t i = 0; i < n; i++)
        y /= 10;

    uint64_t z = y;
    for (size_t i = 0; i < n; i++)
        z *= 10;

    values[0] = y;
    values[1] = x - z;

    return values;
}

Stone * apply_rules(Stone *s, size_t *n_stones) {
    // rule: 0 -> 1
    if (s->value == 0) {
        s->value = 1;
        return s->next;
    }

    size_t n_digits = number_of_digits(s->value);

    // rule: odd number of digits -> multiply by 2024
    if (n_digits % 2 != 0) {
        s->value *= 2024;
        return s->next;
    }

    // rule: even number of digits -> split into two stones
    uint64_t *values = split_value(s->value, n_digits);

    Stone *s_new = create_stone(values[1]);
    s_new->next = s->next;
    s->value = values[0];
    s->next = s_new;
    (*n_stones)++;

    free(values);

    return s_new->next;
}

uint64_t day_11(const size_t n_lines, char **lines, size_t blinks) {
    (void) n_lines; /* unused */

    size_t n;
    Stone *s = get_stones(lines[0], &n);
    Stone *head = s;

    for (size_t i = 0; i < blinks; i++) {
        s = head;
        while (s != NULL)
            s = apply_rules(s, &n);
    }

    // clean up
    s = head;
    while (s != NULL) {
        head = s->next;
        free(s);
        s = head;
    }

    return n;
}

uint64_t day_11_1(const size_t n_lines, char **lines) {
    return day_11(n_lines, lines, 25);
}

uint64_t day_11_2(const size_t n_lines, char **lines) {
    return day_11(n_lines, lines, 75);
}
