#include "../inc/uls.h"

void mx_err_print(s_flags *flags, char **argv, int index) {
    flags->err = 1;
    mx_printerr("uls: ");
    perror(argv[index]);
}
