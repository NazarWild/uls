#include "../inc/uls.h"

void mx_l_out_st_size(unsigned long n, int otstup) {
    int i;
    int len = otstup - mx_len_int(n);

    for (i = 0; i < len; i++) {
        mx_printchar(' ');
    }
    mx_printint(n);
    mx_printchar(' ');
}
