#include "../inc/uls.h"

void mx_l_out_st_uid(unsigned int n, int otstup) {
    struct passwd *username;
    int i;
    
    username = getpwuid(n);
    mx_printstr(username->pw_name);
    for (i = 0; i < otstup - mx_strlen(username->pw_name); i++) {
        mx_printchar(' ');
    }
    mx_printchar(' ');
    mx_printchar(' ');
}
