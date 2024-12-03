#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 8192

char ** read_lines(const char *filename, size_t *n_lines);
void free_lines(const size_t n_lines, char **lines);
char ** str_split(const char *str, const char *delimiter, size_t *n);
char * concat(const char *a, const char *b);
