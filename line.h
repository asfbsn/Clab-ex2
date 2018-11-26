#ifndef LINE
#define LINE
#include <stdbool.h>
#include <stdio.h>

typedef struct line {
	char *buffer;
	int lines_to_print;
	bool is_there_file;
	size_t *bufsize;
	int line_num;
}line;

void fill_line(line **line, bool is_there_file, size_t bufsize,int line_num);

#endif