#include "io_func.h"
#include "line.h"


void dynamicScan(char** str)
{
	*str = (char*)malloc(10 * sizeof(char));
	int i = 0, j = 1, k = 0, c;
	do {
		c = getchar();
		*(*str + i) = c;
		i++;
		k++;
		if (k >= 10)
		{
			j++;
			*str = (char*)realloc(*str, j * 10 * sizeof(char));
			///  assert(*str);
			k = 0;
		}
	} while (c != '\n');

	*(*str + i) = '\0';
}


void read_line(FILE *file, char **buffer, size_t *bufsize, bool is_stdin) {
	int num_of_chars = 0;
	
	if (!is_stdin) {
		dynamicScan(buffer);
	}
	else
		num_of_chars = getline(buffer, bufsize, file);


}
void my_tolower(char **buffer, char **needle) {
	//*needle = _strlwr(*needle);
	//*buffer = _strlwr(*buffer);

	for (int i = 0; i<strlen(*buffer); i++) {
		buffer[i]= tolower(buffer[i]);
	}
	for (int i = 0; i<strlen(*needle); i++) {
		*(*needle + i) = tolower(*(*needle+i));
	}
}
int compare(char *buffer, char *needle,int flags[8]) {
	int ret_val = 0;
	char *line_result;
	if (1 == flags[0])//-i
		my_tolower(&buffer, &needle);
	line_result = strstr(buffer, needle);
	ret_val = (NULL == line_result) ? 0 : 1;
	if (1 == flags[5]) {//-x
		ret_val = strcmp(buffer, needle);
		ret_val = (ret_val != 0) ? 1 : 0;
	}
	if (1 == flags[1])//-v
		ret_val = 1 - ret_val;
	return ret_val;
}
void my_print(line *my_line,int flags[8],FILE *file) {
	if (1 == flags[2])//-c
		printf("%d\n", my_line->line_num);
	else {
		if (1 == flags[3])//-n
			printf("%d ", my_line->line_num);
		if (1== flags[4])//-b
			printf("%d:", ftell(file));// FIXME ctalor :if stdin we will have a problem
		printf("%s\n", my_line->buffer);
	}
}
void read_compare_print_wr(line *my_line,FILE *file, char *needle, int flags[8]) {
	int to_print = NULL;
	read_line(file,&(my_line->buffer), my_line->bufsize, my_line->is_there_file);
	to_print = compare(my_line->buffer,needle,flags);
	if (to_print) {
		if (1 == flags[6])
			my_line->lines_to_print=flags[7];
		my_print(my_line, flags, file);
	}
	else if ((1 == flags[6]) && (my_line->lines_to_print > 0)) {
		my_line->lines_to_print--;
		my_print(my_line, flags, file);
	}
	
}