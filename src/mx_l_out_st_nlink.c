#include "../inc/uls.h"

void mx_l_out_st_nlink(unsigned long n, int otstup, s_flags *fl) {
    int i;
    int len = otstup - mx_len_int(n);

    for (i = 0; i < len; i++) {
        mx_printchar(' ');
    }
    mx_printint(n);
    mx_printchar(' ');
    if (fl->g && fl->o)
    	mx_printstr("  ");
}
