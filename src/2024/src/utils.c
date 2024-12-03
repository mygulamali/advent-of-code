#include "utils.h"

char ** read_lines(const char *filename, size_t *n_lines) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file, %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char **lines = (char **) malloc(sizeof(char *));
    if (lines == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    size_t i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH - 1, fp)) {
        line[strcspn(line, "\n")] = 0;
        lines = (char **) realloc(lines, (i + 1) * sizeof(char *));
        if (lines == NULL) {
            fprintf(stderr, "Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        lines[i] = (char *) malloc((strlen(line) + 1) * sizeof(char));
        strncpy(lines[i], line, strlen(line) + 1);
        i++;
    }
    *n_lines = i;

    fclose(fp);
    return lines;
}

void free_lines(const size_t n_lines, char **lines) {
    for (size_t i = 0; i < n_lines; i++) free(lines[i]);
    free(lines);
}

char * str_dup(const char *str) {
    char *ret = (char *) malloc(strlen(str) * sizeof(char));
    strcpy(ret, str);
    return ret;
}

char ** str_split(const char *str, const char *delimiter, size_t *n) {
    char **ret = (char **) malloc(sizeof(char *));
    char *dup = str_dup(str);

    size_t i = 0;
    char *token = strtok(dup, delimiter);
    while (token != NULL) {
        ret = (char **) realloc(ret, (i + 1) * sizeof(char *));
        ret[i] = (char *) malloc((strlen(token) + 1) * sizeof(char));
        strncpy(ret[i], token, strlen(token) + 1);
        i++;
        token = strtok(NULL, delimiter);
    }
    *n = i;

    free(dup);
    return ret;
}

char * concat(const char *a, const char *b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    char *ret = (char*) malloc(len_a + len_b + 1);

    if (ret == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(ret, a);
    strcat(ret, b);

    return ret;
}
