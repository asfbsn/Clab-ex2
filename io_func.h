#ifndef IO_FUNC
#define IO_FUNC
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "line.h"


void read_compare_print_wr(line *my_line, FILE *file, char *needle, int flags[8]);

#endif

