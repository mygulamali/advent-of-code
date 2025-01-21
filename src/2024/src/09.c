#include "09.h"

typedef struct SparseVector {
    size_t *ids;
    size_t *indices;
    size_t size;
} SparseVector;

SparseVector get_blocks(const char* line) {
    size_t n = strlen(line);

    SparseVector blocks = { NULL, NULL, 0 };

    size_t id = 0;
    size_t indx = 0;
    for (size_t i = 0; i < n; i++) {
        char str[2] = { line[i], '\0' }; // string of 1 character
        size_t size = atoi(str);

        if (i % 2 == 0) {
            blocks.ids = (size_t *) realloc(blocks.ids, (blocks.size + size) * sizeof(size_t));
            if (blocks.ids == NULL) {
                fprintf(stderr, "Error allocating memory\n");
                exit(EXIT_FAILURE);
            }

            blocks.indices = (size_t *) realloc(blocks.indices, (blocks.size + size) * sizeof(size_t));
            if (blocks.indices == NULL) {
                fprintf(stderr, "Error allocating memory\n");
                exit(EXIT_FAILURE);
            }

            for (size_t j = 0; j < size; j++) {
                blocks.ids[blocks.size + j] = id;
                blocks.indices[blocks.size + j] = indx + j;
            }

            blocks.size += size;
            id++;
        }

        indx += size;
    }

    return blocks;
}

size_t day_09_1(const size_t n_lines, char **lines) {
    (void) n_lines; /* unused */

    SparseVector blocks = get_blocks(lines[0]);

    // shift blocks using two-pointers at either end of the data structure
    size_t l = 1;
    size_t r = blocks.size - 1;
    while (l < r) {
        int32_t d = blocks.indices[l] - blocks.indices[l - 1] - 1;
        if (d > 0) {
            for (int32_t j = 0; j < d; j++) {
                blocks.indices[r] = blocks.indices[l - 1] + j + 1;
                r--;
            }
        }
        l++;
    }

    size_t checksum = 0;
    for (size_t i = 0; i < blocks.size; i++)
        checksum += blocks.ids[i] * blocks.indices[i];

    free(blocks.ids);
    free(blocks.indices);

    return checksum;
}
