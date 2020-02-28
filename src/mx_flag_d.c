#include "../inc/uls.h"

void mx_flag_d(char *source, t_list **files) {
	int i = 0;
	char *buf;

	while (source[i]) {
		buf = mx_strdup(&source[i]);
        mx_push_front(files, buf);
        i++;
	}
}
