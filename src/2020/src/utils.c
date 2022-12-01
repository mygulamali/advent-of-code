#include "utils.h"

char ** read_lines(const char *filename, int *n_lines) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
	exit(EXIT_FAILURE);

    char **lines = (char **) malloc(sizeof(char *));

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH - 1, fp)) {
        line[strcspn(line, "\n")] = 0;
	lines = (char **) realloc(lines, (i + 1) * sizeof(char *));
	lines[i] = (char *) malloc((strlen(line) + 1) * sizeof(char));
	strncpy(lines[i], line, strlen(line) + 1);
	i++;
    }
    *n_lines = i;

    fclose(fp);
    return lines;
}

void free_lines(const int n_lines, char **lines) {
    for (int i = 0; i < n_lines; i++) free(lines[i]);
    free(lines);
}

char * str_dup(const char *str) {
    char *ret = (char *) malloc(strlen(str) * sizeof(char));
    strcpy(ret, str);
    return ret;
}

char ** str_split(const char *str, const char *delimiter, int *n) {
    char **ret = (char **) malloc(sizeof(char *));
    char *dup = str_dup(str);

    int i = 0;
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
