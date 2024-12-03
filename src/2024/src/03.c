#include <regex.h>

#include "03.h"

int32_t day_03_1(const size_t n_lines, char **lines) {
    char *pattern = "mul\\(([0-9]+),([0-9]+)\\)";
    regex_t regex;
    int16_t err;

    err = regcomp(&regex, pattern, REG_EXTENDED);
    if (err) {
        fprintf(stderr, "Could not compile regex.\n");
        exit(EXIT_FAILURE);
    }

    int32_t result = 0;

    for (size_t i = 0; i < n_lines; i++) {
        regmatch_t matches[3];
        char *cursor = lines[i];

        while (regexec(&regex, cursor, 3, matches, 0) == 0) {
            char a_str[4];
            sprintf(
                a_str,
                "%.*s",
                (int32_t) (matches[1].rm_eo - matches[1].rm_so),
                cursor + matches[1].rm_so
            );
            int32_t a = strtod(a_str, NULL);

            char b_str[4];
            sprintf(
                b_str,
                "%.*s",
                (int32_t) (matches[2].rm_eo - matches[2].rm_so),
                cursor + matches[2].rm_so
            );
            int32_t b = strtod(b_str, NULL);

            result += a * b;

            cursor += matches[0].rm_eo;
        }
    }

    regfree(&regex);

    return result;
}

int32_t day_03_2(const size_t n_lines, char **lines) {
    int16_t err;

    char *pattern = "mul\\(([0-9]+),([0-9]+)\\)|do\\(\\)|don't\\(\\)";
    regex_t regex;
    err = regcomp(&regex, pattern, REG_EXTENDED);
    if (err) {
        fprintf(stderr, "Could not compile regex.\n");
        exit(EXIT_FAILURE);
    }

    int32_t result = 0;
    bool use_mul = true;
    for (size_t i = 0; i < n_lines; i++) {
        regmatch_t matches[3];
        char *cursor = lines[i];

        while (regexec(&regex, cursor, 3, matches, 0) == 0) {
            char match[13]; // mul(XXX,XXX) -> max 12 + 1 chars
            sprintf(
                match,
                "%.*s",
                (int32_t) (matches[0].rm_eo - matches[0].rm_so),
                cursor + matches[0].rm_so
            );

            if (strcmp(match, "do()") == 0)
                use_mul = true;
            else if (strcmp(match, "don't()") == 0)
                use_mul = false;
            else if (use_mul) {
                char a_str[4];
                sprintf(
                    a_str,
                    "%.*s",
                    (int32_t) (matches[1].rm_eo - matches[1].rm_so),
                    cursor + matches[1].rm_so
                );
                int32_t a = strtod(a_str, NULL);

                char b_str[4];
                sprintf(
                    b_str,
                    "%.*s",
                    (int32_t) (matches[2].rm_eo - matches[2].rm_so),
                    cursor + matches[2].rm_so
                );
                int32_t b = strtod(b_str, NULL);

                result += a*b;
            }

            cursor += matches[0].rm_eo;
        }
    }

    regfree(&regex);

    return result;
}
