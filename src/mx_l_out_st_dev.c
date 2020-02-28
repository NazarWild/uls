#include "../inc/uls.h"

static void out_major(int len, int major) {
    int i;

    for (i = 0; i < len; i++) {
       mx_printchar(' ');
    }
    mx_printint(major);
    mx_printstr(", ");
}

static void out_minor(int len, int minor) {
    int i;
    char *minor_hex = NULL;

    if (minor > 255) {
        minor_hex = mx_nbr_to_hex(minor);
        mx_printstr("0x");
        write(1, "00000000", 8 - mx_strlen(minor_hex));
        mx_printstr(minor_hex);
    }
    else {
        len = 3;
        for (i = 0; i < len - mx_len_int(minor); i++) {
            mx_printchar(' ');
        }
        mx_printint(minor);
    }
    mx_strdel(&minor_hex);
}

void mx_l_out_st_dev(unsigned int n, int otstup1, int otstup2) {
    int len1 = otstup1 - mx_len_int(MX_MAJOR(n));
    int len2 = otstup2 - mx_len_int(MX_MINOR(n));
    int minor = MX_MINOR(n);

    mx_printchar(' ');
    out_major(len1, MX_MAJOR(n));
    out_minor(len2, minor);
    mx_printchar(' ');
}
