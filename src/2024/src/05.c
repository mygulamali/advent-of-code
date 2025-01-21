#include "05.h"

typedef struct {
    uint32_t first;
    uint32_t second;
} Rule;

Rule * get_rules(char **lines, const size_t n_lines, size_t *n_rules) {
    Rule *rules = malloc(2 * sizeof(uint32_t));
    if (rules == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    size_t count = 0;
    size_t rule_size = 2 * sizeof(uint32_t);
    while ((strcmp(lines[count], "") != 0) && count < n_lines) {
        rules = (Rule *) realloc(rules, (count + 1) * rule_size);
        if (rules == NULL) {
            fprintf(stderr, "Error allocating memory\n");
            exit(EXIT_FAILURE);
        }

        size_t n_pages;
        char **pages = str_split(lines[count], "|", &n_pages);
        rules[count].first = (uint32_t) strtod(pages[0], NULL);
        rules[count].second = (uint32_t) strtod(pages[1], NULL);

        for (size_t i = 0; i < n_pages; i++) free(pages[i]);
        free(pages);

        count++;
    }

    *n_rules = count;

    return rules;
}

uint32_t * get_pages(char *line, size_t *n_pages) {
    char **pages = str_split(line, ",", n_pages);

    uint32_t *result = malloc(*n_pages * sizeof(uint32_t));
    if (result == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < *n_pages; i++)
        result[i] = (uint32_t) strtod(pages[i], NULL);

    for (size_t i = 0; i < *n_pages; i++) free(pages[i]);
    free(pages);

    return result;
}

int32_t find_rule(
    const uint32_t page_a,
    const uint32_t page_b,
    const Rule *rules,
    const size_t n_rules
) {
    for (size_t i = 0; i < n_rules; i++) {
        if (page_a == rules[i].first && page_b == rules[i].second)
            return (int32_t) i;
    }

    return -1;
}

bool is_valid(
    const uint32_t *pages,
    const size_t n_pages,
    const Rule *rules,
    const size_t n_rules
) {
    for (size_t i = 0; i < n_pages; i++)
        for (size_t j = i + 1; j < n_pages; j++) {
            const int32_t rule_indx = find_rule(pages[i], pages[j], rules, n_rules);
            if (rule_indx == -1)
                return false;
        }

    return true;
}

uint32_t day_05_1(const size_t n_lines, char **lines) {
    size_t n_rules;
    Rule *rules = get_rules(lines, n_lines, &n_rules);

    uint32_t result = 0;
    for (size_t i = n_rules + 1; i < n_lines; i++) {
        size_t n_pages;
        u_int32_t *pages = get_pages(lines[i], &n_pages);
        if (is_valid(pages, n_pages, rules, n_rules)) {
            size_t mid_indx = n_pages / 2;
            result += pages[mid_indx];
        }
        free(pages);
    }

    free(rules);
    return result;
}
