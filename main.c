#include <stdlib.h>
#include "io_func.h"
#include "line.h"




bool my_is_digit(char arg[]) {
	for (int i=0; i < strlen(arg); i++) {
		if (!isdigit(arg[i]))
			return 0;
	}
	return 1;
}
int map_flags_to_array(int argc ,char **argv,int *flags[]) {
	int idx = argc-2, ret_val=0 ;
	char *temp = NULL;
		for (int i=1;i<argc;i++)
		{
			if (!strcmp(argv[idx+1], "-i")) {
				flags[0] = 1;
				idx--;
			}
			else if (!strcmp(argv[idx+1], "-v")){
				flags[1] = 1;
			idx--;
		}
			else if (!strcmp(argv[idx+1], "-c")){
				flags[2] = 1;
				idx--;
}
			else if (!strcmp(argv[idx+1], "-n")){
				flags[3] = 1; 
				idx--;
			}
			else if (!strcmp(argv[idx+1], "-b")){
				flags[4] = 1;
				idx--;
			}
			else if (!strcmp(argv[idx+1], "-x")){
				flags[5] = 1;
				idx--;
			}
			else if (!strcmp(argv[idx+1], "-A")){
				flags[6] = 1;
				idx--;
			}
			else if (my_is_digit(argv[idx+1])){
				flags[7] = atoi(argv[idx + 1]);
				idx--;
			}
			else{
				ret_val=1;
				idx--;
			}
			
		}
		return ret_val;
}

int main(int argc, char *argv[]) {
	int line_num = 0;
	FILE *search_file = NULL;
	char *buffer ;
	line *my_line;//FIXME CTALOR -malloc or use the same one? 
	if(NULL==(my_line = (line*)malloc(sizeof(line)))) exit(-1);
	my_line->lines_to_print = 0;
	buffer = (char**)malloc(1 * sizeof(char*));//check allocation
	size_t bufsize = 0;
	int line_result = NULL,is_there_file = 0;
	int flags[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	is_there_file= map_flags_to_array(argc, argv, &flags);
	if (is_there_file) {
		if(NULL==(search_file = fopen(argv[argc-1], "r")))exit(-1);
		while (!feof(search_file)) {
			line_num++;
			fill_line(&my_line, is_there_file, bufsize, line_num);
			read_compare_print_wr(my_line, search_file, argv[1], flags);
		}
	}
	else while (1) {
			line_num++;
			fill_line(&my_line, is_there_file,bufsize,line_num);
			read_compare_print_wr(&my_line,search_file, argv[1], flags);
		}
	free(buffer);
//	free(my_line->buffer);
	free(my_line);
	return 0;
}