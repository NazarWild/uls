#include "../inc/uls.h"

char *mx_strjoin_for_path(char *argv, char *data, s_flags *flags) {
    char *part = NULL;
    char *full = NULL;

    if (flags->X) {
    	part = mx_strjoin("/", data);
		full = mx_strjoin(argv, part);
		mx_strdel(&part);
		flags->Y = 1;
	}
	else {
		full = data;
		flags->Y = 0;
	}
    return full;
}
