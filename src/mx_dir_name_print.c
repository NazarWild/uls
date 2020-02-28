#include "../inc/uls.h"

void mx_dir_name_print(int i, char *source) {
    if (i > 0)
        mx_printstr("\n");
    mx_printstr(source);
    mx_printchar(':');
    mx_printchar('\n');
}
