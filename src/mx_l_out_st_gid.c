#include "../inc/uls.h"

void mx_l_out_st_gid(unsigned long n, int otstup) {
    struct group *gr;
    int i;

    gr = getgrgid(n);
    if (gr != NULL) {
        mx_printstr(gr->gr_name);
        for (i = 0; i < otstup - mx_strlen(gr->gr_name); i++) {
            mx_printchar(' ');
        }
    }
    else {
        mx_printint(n);
        for (i = 0; i < otstup - mx_len_int(n); i++) {
            mx_printchar(' ');
        }
    }
    mx_printchar(' ');
    mx_printchar(' ');
}
