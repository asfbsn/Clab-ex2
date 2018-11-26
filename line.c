#include "line.h"
void fill_line(line **line, bool is_there_file, size_t bufsize,int line_num) {
	(*line)->is_there_file  = is_there_file;
	(*line)->bufsize = bufsize;
	(*line)->line_num = line_num;
}