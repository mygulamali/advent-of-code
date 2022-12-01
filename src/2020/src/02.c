#include "utils.h"

bool password_is_valid_1(const char *policy) {
    int n;
    char **parts = str_split(policy, " ", &n);

    char *validation_char = str_dup(parts[1]);
    char *password = str_dup(parts[2]);

    parts = str_split(parts[0], "-", &n);

    printf("%s | %s * %s * %c * %s\n", policy, parts[0], parts[1], validation_char[0], password);

    free(validation_char);
    free(password);
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
	printf("Usage: %s <PUZZLE INPUT>\n", argv[0]);
	exit(EXIT_FAILURE);
    }

    printf("Day 2\n");

    int n;
    char **lines = read_lines(argv[1], &n);

    /* Part 1 */

    int count = 0;
    for (int i = 0; i < n; i++)
	if ((i % 100 == 0) && password_is_valid_1(lines[i])) count++;

    printf("Part 1: %d\n", count);

    /* Part 2 */

    /* printf("Part 2: %d x %d x %d = %d\n", x, y, z, x * y * z); */

    free_lines(n, lines);
    exit(EXIT_SUCCESS);
}
