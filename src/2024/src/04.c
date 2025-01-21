#include "04.h"

int32_t day_04_1(const size_t n_lines, char **lines) {
    size_t height = n_lines;
    size_t width = strlen(lines[0]);

    int32_t result = 0;

    // horizontal
    for (size_t y = 0; y < height; y++)
        for (size_t x = 0; x < width - 3; x++) {
            char str[5];
            for (size_t i = 0; i < 4; i++) str[i] = lines[y][x + i];
            str[4] = '\0';

            if (strcmp(str, "XMAS") == 0 || strcmp(str, "SAMX") == 0)
                result++;
        }

    // vertical
    for (size_t x = 0; x < width; x++)
        for (size_t y = 0; y < height - 3; y++) {
            char str[5];
            for (size_t i = 0; i < 4; i++) str[i] = lines[y + i][x];
            str[4] = '\0';

            if (strcmp(str, "XMAS") == 0 || strcmp(str, "SAMX") == 0)
                result++;
        }

    // diagonally (top-left to bottom-right)
    for (size_t y = 0; y < height - 3; y++)
        for (size_t x = 0; x < width - 3; x++) {
            char str[5];
            for (size_t i = 0; i < 4; i++) str[i] = lines[y + i][x + i];
            str[4] = '\0';

            if (strcmp(str, "XMAS") == 0 || strcmp(str, "SAMX") == 0)
                result++;
        }

    // diagonally (top-right to bottom-left)
    for (size_t y = 0; y < height - 3; y++)
        for (size_t x = 3; x < width; x++) {
            char str[5];
            for (size_t i = 0; i < 4; i++) str[i] = lines[y + i][x - i];
            str[4] = '\0';

            if (strcmp(str, "XMAS") == 0 || strcmp(str, "SAMX") == 0)
                result++;
        }

    return result;
}

int32_t day_04_2(const size_t n_lines, char **lines) {
    size_t height = n_lines;
    size_t width = strlen(lines[0]);

    int32_t result = 0;

    for (size_t y = 0; y < height - 2; y++)
        for (size_t x = 0; x < width - 2; x++) {
            // diagonally (top-left to bottom-right)
            char a[4];
            for (size_t i = 0; i < 3; i++) a[i] = lines[y + i][x + i];
            a[3] = '\0';

            // diagonally (top-right to bottom-left)
            char b[4];
            for (size_t i = 0; i < 3; i++) b[i] = lines[y + i][x + 2 - i];
            b[3] = '\0';

            if (
                (strcmp(a, "MAS") == 0 || strcmp(a, "SAM") == 0) &&
                (strcmp(b, "MAS") == 0 || strcmp(b, "SAM") == 0)
            )
                result++;
        }

    return result;
}
